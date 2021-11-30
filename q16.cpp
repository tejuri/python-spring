#include<iostream>

#define SPACE 10

using namespace std;

class AVLnode {
  public:
    int data;
  AVLnode * leftchild;
  AVLnode * rightchild;

  AVLnode() {
    data = 0;
    leftchild = NULL;
    rightchild = NULL;
  }
  AVLnode(int v) {
    data = v;
    leftchild = NULL;
    rightchild = NULL;
  }
};

class AVLTree {
  public:
    AVLnode * root;
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
  
  int height(AVLnode * temp) {
    if (temp == NULL)
      return -1;
    else {
  
      int lheight = height(temp -> leftchild);
      int rheight = height(temp -> rightchild);


      if (lheight > rheight)
        return (lheight + 1);
      else return (rheight + 1);
    }
  }


  int getBalanceFactor(AVLnode * temp) {
    if (temp == NULL)
      return -1;
    return height(temp -> leftchild) - height(temp -> rightchild);
  }

  AVLnode * rightRotate(AVLnode * temp) {
    AVLnode * temp1 = temp -> leftchild;
    AVLnode * temp2 = temp1 -> rightchild;

     
    temp1 -> rightchild = temp;
    temp -> leftchild = temp2;

    return temp1;
  }

  AVLnode * leftRotate(AVLnode * temp1) {
    AVLnode * temp = temp1 -> rightchild;
    AVLnode * temp2 = temp -> leftchild;

    
    temp -> leftchild = temp1;
    temp1 -> rightchild = temp2;

    return temp;
  }

  AVLnode * insert(AVLnode * temp, AVLnode * new_node) {
    if (temp == NULL) {
      temp = new_node;
      cout << "Node value inserted" << endl;
      return temp;
    }

    if (new_node -> data < temp -> data) {
      temp -> leftchild = insert(temp -> leftchild, new_node);
    } else if (new_node -> data > temp -> data) {
      temp -> rightchild = insert(temp -> rightchild, new_node);
    } else {
      cout << "Duplicate value" << endl;
      return temp;
    }

    int bf = getBalanceFactor(temp);
   
    if (bf > 1 && new_node -> data < temp -> leftchild -> data)
      return rightRotate(temp);

    if (bf < -1 && new_node -> data > temp -> rightchild -> data)
      return leftRotate(temp);

   
    if (bf > 1 && new_node -> data > temp -> leftchild -> data) {
      temp -> leftchild = leftRotate(temp -> leftchild);
      return rightRotate(temp);
    }

   
    if (bf < -1 && new_node -> data < temp -> rightchild -> data) {
      temp -> rightchild = rightRotate(temp -> rightchild);
      return leftRotate(temp);
    }

  
    return temp;

  }

  AVLnode * minvalue(AVLnode * node) {
    AVLnode * current = node;
   
    while (current -> leftchild != NULL) {
      current = current -> leftchild;
    }
    return current;
  }

  AVLnode * deleteNode(AVLnode * temp, int v) {
  
    if (temp == NULL) {
      return NULL;
    }
    
    else if (v < temp -> data) {
      temp -> leftchild = deleteNode(temp -> leftchild, v);
    }
     
    else if (v > temp -> data) {
      temp -> rightchild = deleteNode(temp -> rightchild, v);
    }
    
    else {
     
      if (temp -> leftchild == NULL) {
        AVLnode * temp = temp -> rightchild;
        delete temp;
        return temp;
      } else if (temp -> rightchild == NULL) {
        AVLnode * temp = temp -> leftchild;
        delete temp;
        return temp;
      } else {
        
        AVLnode * temp = minvalue(temp -> rightchild);
       
        temp -> data = temp -> data;
        
        temp -> rightchild = deleteNode(temp -> rightchild, temp -> data);
        
      }
    }

    int bf = getBalanceFactor(temp);
   
    if (bf == 2 && getBalanceFactor(temp -> leftchild) >= 0)
      return rightRotate(temp);
    
    else if (bf == 2 && getBalanceFactor(temp -> leftchild) == -1) {
      temp -> leftchild = leftRotate(temp -> leftchild);
      return rightRotate(temp);
    }
    
    else if (bf == -2 && getBalanceFactor(temp -> rightchild) <= -0)
      return leftRotate(temp);
    
    else if (bf == -2 && getBalanceFactor(temp -> rightchild) == 1) {
      temp -> rightchild = rightRotate(temp -> rightchild);
      return leftRotate(temp);
    }

    return temp;
  }


  void printPreorder(AVLnode * temp)  
  {
    if (temp == NULL)
      return;
   
    cout << temp -> data << " ";
   
    printPreorder(temp -> leftchild);
    
    printPreorder(temp -> rightchild);
  }


  AVLnode * Search(AVLnode * temp, int val) {
    if (temp == NULL || temp -> data == val)
      return temp;

    else if (val < temp -> data)
      return Search(temp -> leftchild, val);

    else
      return Search(temp -> rightchild, val);
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
 
    AVLnode * new_node = new AVLnode();

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