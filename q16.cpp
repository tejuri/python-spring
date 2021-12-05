#include<iostream>

#define SPACE 10

using namespace std;

class Node {
  public:
    int data;
  Node * left;
  Node * right;

  Node() {
    data = 0;
    left = NULL;
    right = NULL;
  }
  Node(int v) {
    data = v;
    left = NULL;
    right = NULL;
  }
};

class AVLTree {
  public:
    Node * root;
  AVLTree() {
    root = NULL;
  }
  bool isTreeEmpty() {
    if (root == NULL) {
      return true;
    } else {
      return false;
    }
  }

  int height(Node * temp) {
    if (temp == NULL)
      return -1;
    else {

      int lheight = height(temp -> left);
      int rheight = height(temp -> right);


      if (lheight > rheight)
        return (lheight + 1);
      else return (rheight + 1);
    }
  }


  int getBalanceFactor(Node * temp) {
    if (temp == NULL)
      return -1;
    return height(temp -> left) - height(temp -> right);
  }

  Node * rightRotate(Node * temp) {
    Node * temp1 = temp -> left;
    Node * temp2 = temp1 -> right;


    temp1 -> right = temp;
    temp -> left = temp2;

    return temp1;
  }

  Node * leftRotate(Node * temp1) {
    Node * temp = temp1 -> right;
    Node * temp2 = temp -> left;


    temp -> left = temp1;
    temp1 -> right = temp2;

    return temp;
  }

  Node * insert(Node * temp, Node * new_node) {
    if (temp == NULL) {
      temp = new_node;
      cout << "Node value inserted" << endl;
      return temp;
    }

    if (new_node -> data < temp -> data) {
      temp -> left = insert(temp -> left, new_node);
    } else if (new_node -> data > temp -> data) {
      temp -> right = insert(temp -> right, new_node);
    } else {
      cout << "Duplicate value" << endl;
      return temp;
    }

    int bf = getBalanceFactor(temp);

    if (bf > 1 && new_node -> data < temp -> left -> data)
      return rightRotate(temp);

    if (bf < -1 && new_node -> data > temp -> right -> data)
      return leftRotate(temp);


    if (bf > 1 && new_node -> data > temp -> left -> data) {
      temp -> left = leftRotate(temp -> left);
      return rightRotate(temp);
    }


    if (bf < -1 && new_node -> data < temp -> right -> data) {
      temp -> right = rightRotate(temp -> right);
      return leftRotate(temp);
    }


    return temp;

  }

  Node * minvalue(Node * node) {
    Node * current = node;

    while (current -> left != NULL) {
      current = current -> left;
    }
    return current;
  }

  Node * deleteNode(Node * temp, int v) {

    if (temp == NULL) {
      return NULL;
    }

    else if (v < temp -> data) {
      temp -> left = deleteNode(temp -> left, v);
    }

    else if (v > temp -> data) {
      temp -> right = deleteNode(temp -> right, v);
    }

    else {
      if (temp -> left == NULL) {
        Node * temp1 = temp -> right;
        if (temp1 == NULL)
            {
                temp1 = root;
                root = NULL;
        }
        else
        *temp = *temp1;
        delete temp1;
      } else if (temp -> right == NULL) {
        Node * temp1 = temp -> left;
        if (temp1 == NULL)
            {
                temp1 = root;
                root = NULL;
        }
        else
        *temp = *temp1;
        delete temp1;
      } else {

        Node * temp1 = minvalue(temp -> right);

        temp -> data = temp1 -> data;

        temp -> right = deleteNode(temp -> right, temp1 -> data);

      }
    }

    int bf = getBalanceFactor(temp);

    if (bf == 2 && getBalanceFactor(temp -> left) >= 0)
      return rightRotate(temp);

    else if (bf == 2 && getBalanceFactor(temp -> left) == -1) {
      temp -> left = leftRotate(temp -> left);
      return rightRotate(temp);
    }

    else if (bf == -2 && getBalanceFactor(temp -> right) <= -0)
      return leftRotate(temp);

    else if (bf == -2 && getBalanceFactor(temp -> right) == 1) {
      temp -> right = rightRotate(temp -> right);
      return leftRotate(temp);
    }

    return temp;
  }


  void printPreorder(Node * temp)
  {
    if (temp == NULL)
      return;

    cout << temp -> data << " ";

    printPreorder(temp -> left);

    printPreorder(temp -> right);
  }


  Node * Search(Node * temp, int val) {
    if (temp == NULL || temp -> data == val)
      return temp;

    else if (val < temp -> data)
      return Search(temp -> left, val);

    else
      return Search(temp -> right, val);
  }

};

int main() {
  AVLTree obj;
  int option, val;

  do {
    cout << "What operation do you want to perform? " <<
      " Select Option number. Enter 0 to exit." << endl;
    cout << "1. Insert Node" << endl;
    cout << "2. Display" << endl;
    cout << "3. Delete Node" << endl;
    cout << "4. Search Node" << endl;
    cout << "0. Exit Program" << endl;

    cin >> option;

    Node * new_node = new Node();

    switch (option) {
    case 0:
      break;
    case 1:
      cout << "AVL INSERT" << endl;
      cout << "Enter value of node to insert in AVL Tree: ";
      cin >> val;
      new_node -> data = val;
      obj.root = obj.insert(obj.root, new_node);
      cout << endl;
      break;
    case 2:{
      cout << "DISPLAY " << endl;

      cout << endl;

       obj.printPreorder(obj.root);
       cout<<endl;
    }
    break;

    case 3:
      cout << "DELETE" << endl;
      cout << "Enter value of node to delete in AVL: ";
      cin >> val;
      new_node = obj.Search(obj.root, val);
      if (new_node != NULL) {
        obj.root = obj.deleteNode(obj.root, val);
        cout << "Value Deleted" << endl;
      } else {
        cout << "Value not found" << endl;
      }
      break;
    case 4:
      cout << "SEARCH" << endl;
      cout << "Enter value of node to search in AVL Tree: ";
      cin >> val;

      new_node = obj.Search(obj.root, val);
      if (new_node != NULL) {
        cout << "Value found" << endl;
      } else {
        cout << "Value not found" << endl;
      }
      break;

    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);

  return 0;
}
