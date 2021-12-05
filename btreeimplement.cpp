#include<iostream>
using namespace std;
#define MAX 2000
struct btree
{
    int data;
    btree *leftchild;
    btree *rightchild;
};
struct stack
{
    int elements[1000];
    int size;
    int top;
}s;

void push(int x)
{
    if(s.top==s.size-1)
    cout<<"stack is full";
    else
    {
        s.elements[++s.top]=x;

    }

}
void pop()
{
    int t;
    if(s.top==-1)
     return ;

     else
     {
    while(s.top!=-1)
    {
     cout<<s.elements[s.top--]<<" ";

     }
     }

}
class Queue
{
    public:
      int front,rear;
      btree *queue[MAX];
      int qsize;
      Queue()
      {
              front=rear=-1;
              qsize=0;

      }

       void enqueue(btree *item)
       {
              if(rear==MAX-1)
             {
                      cout<<"\nQUEUE OVERFLOW";
             }
             else if(front==-1 && rear==-1)
             {
                      front=rear=0;
                      queue[rear]=item;
                      qsize++;

             }
             else
             {
                      rear++;
                      queue[rear]=item;
                      qsize++;

             }
       }

       btree *dequeue()
       {
              btree *item;

              if(rear==-1)
             {
                       cout<<"\nQUEUE UNDERFLOW";
                       return NULL;
             }
             else if(front==0 && rear==0)
             {
                       item=queue[front];
                       front=rear=-1;
                       qsize--;

             }
             else
             {
                      item=queue[front];
                      front++;
                      qsize--;

             }

             return item;
       }
};
btree *newnode(int x)
{
    btree *input=new btree();
    input->data=x;
    input->leftchild=NULL;
    input->rightchild=NULL;

    return input;
}

btree *insert(btree *root, int data)
{
    if(root==NULL)
    return newnode(data);
    Queue q1;
    q1.enqueue(root);
    btree *temp=NULL;

    while(q1.qsize!=0)
    {
        temp=q1.dequeue();
        if (temp->leftchild != NULL)
            q1.enqueue(temp->leftchild);
        else {
            temp->leftchild = newnode(data);
            return root;
        }

        if (temp->rightchild)
            q1.enqueue(temp->rightchild);
        else {
            temp->rightchild = newnode(data);
            return root;
        }
    }
}
void remove_node(btree *root, btree *n)
{
    Queue q1;
    if(root==NULL)
    return;
    q1.enqueue(root);
    btree *temp=NULL;

    while(q1.qsize!=0)
    {
        temp=q1.dequeue();

        if(temp==n)
        {
            temp = NULL;
            delete(n);
            return;
        }
        if(temp->rightchild){
            if(temp->rightchild==n)
            {
                temp->rightchild = NULL;
                delete(n);
                return;
            }
            else q1.enqueue(temp->rightchild);
        }

        if(temp->leftchild){
            if(temp->leftchild==n)
            {
                temp->leftchild = NULL;
                delete(n);
                return;
            }
            else q1.enqueue(temp->leftchild);
        }

    }

}
btree *deletenode(btree *root, int key)
{
    Queue q1;
    if(root==NULL)
    return NULL;
    q1.enqueue(root);
    btree *key_node=NULL;
    btree *curr_node;

    while(q1.qsize!=0)
    {
        curr_node=q1.dequeue();

        if(curr_node->data==key)
        {
            key_node= curr_node;
        }

        if(curr_node->leftchild)
        q1.enqueue(curr_node->leftchild);

        if(curr_node->rightchild)
        q1.enqueue(curr_node->rightchild);

    }
    cout<<curr_node->data<<endl<<endl;
    int data = curr_node->data;
    remove_node(root, curr_node);
    key_node->data = data;
    return root;
}

void inorderTraversal(btree *root){
    if(root == NULL)
    return;
    inorderTraversal(root->leftchild);
    cout << root->data<<" ";
    inorderTraversal(root->rightchild);
}

void preordertraversal(btree *root){

    if(root==NULL)
    return;
    cout<<root->data<<" ";
    preordertraversal(root->leftchild);
    preordertraversal(root->rightchild);

}

void postorder(btree *root)
{
    if(root == NULL)
    return;

    postorder(root->leftchild);
    postorder(root->rightchild);

    cout<<root->data<<" ";

}
int height(btree *root)
{
    if(root==NULL)
    return 0;

    int l=height(root->leftchild);
    int r=height(root->rightchild);

    return 1+max(l,r);
}

int numberofnodes(btree *root)
{
    if(root==NULL)
    return 0;

    return 1+numberofnodes(root->leftchild)+numberofnodes(root->rightchild);
}

//full btree is a tree in which every node has either zero or 2 children

bool isfull(btree *root)
{
    if(root==NULL)
    return true;

    if(root->leftchild==NULL && root->rightchild==NULL)
    return true;

    if((root->leftchild) && (root->rightchild))
    {
        return (isfull(root->leftchild) && isfull(root->rightchild));
    }

    return false;
}

void displaylevel(btree *root, int l)
{
    if(root==NULL)
    return ;

    Queue q1;
    q1.enqueue(root);
    q1.enqueue(NULL);
    int level=0;

    while(q1.qsize!=0)
    {
        btree *x=q1.dequeue();

        if(x!=NULL)
        {
            if(level==l)
            push(x->data);
        }

        if(x->rightchild)
        q1.enqueue(x->rightchild);

        if(x->leftchild)
        q1.enqueue(x->leftchild);

        else if(q1.qsize!=0)
        {
          q1.enqueue(NULL);
          level++;
        }

    }
    pop();
}

int main()
{
    Queue q;
	s.size=20000;
    s.top=-1;
	int n;

	btree* rootptr;
	rootptr=NULL;
    btree *temp=rootptr;
    bool full;


    int ch;
    do{
    cout<<"Enter your choices :Enter 0 to exit\n";
    cout<<"1. Add an element to the binary tree\n ";
    cout<<"2. Delete an element from the tree\n";
    cout<<"3. Display level i of the tree.\n";
    cout<<"4. Inorder traversal.\n";
    cout<<"5. Preorder traversal.\n";
    cout<<"6. Postorder traversal.\n";
    cout<<"7. Height of the tree.\n";
    cout<<"8. Number of elements in the tree\n";
    cout<<"9. A message stating whether the tree is a full binary tree or not\n";
    cout<<"0. Exit\n";
    cin>>ch;
    switch(ch)
    {
        case 0:
        break;
        case 1:
        cout<<"Enter an element: \n";
        cin>>n;
        temp=insert(temp,n);

        break;

        case 2:
        cout<<"Enter the value of the node to be deleted:\n";
        cin>>n;
        temp=deletenode(temp,n);
        break;
        case 3:
        cout<<"Enter the level that has to be displayed:\n";
        cin>>n;
        displaylevel(temp,n);
        cout<<endl;
        break;
        case 4:
        cout<<"Inorder traversal\n";
        inorderTraversal(temp);
        cout<<endl;
        break;
        case 5:
        cout<<"Preorder traversal\n";
        preordertraversal(temp);
        cout<<endl;
        break;
        case 6:
        cout<<"Postorder traversal\n";
        postorder(temp);
        cout<<endl;
        break;
        case 7:
        cout<<"The height of tree is "<<height(temp)<<endl;
        break;
        case 8:
        cout<<"The number of elements in tree is: "<<numberofnodes(temp)<<endl;
        break;
        case 9:
        full=isfull(temp);
        if(full!=false)
        {
            cout<<"Tree is full\n";
        }
        else
        cout<<"Tree is not full\n";
        break;
        default: cout<<"Enter proper option number\n";
        break;
    }
    }while(ch!=0);

    return 0;
}
