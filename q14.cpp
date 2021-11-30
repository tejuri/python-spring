#include<iostream>
using namespace std;

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
    btree *input==new btree();
    input->data=d;
    input->leftchild=NULL;
    input->rightchild=NULL;

    return input;
}

btree insert(btree *root, int data)
{
    if(root==NULL)
    root=newnode(data);

    if(root->leftchild==NULL)
    {
        root->leftchild=insert(root->leftchild,data);
    }
    else if(root->rightchild==NULL)
    {
        root->rightchild=insert(root->rightchild,data);
    }
    return root;

}
void remove_node(btree *root, btree *n)
{
    if(root==NULL)
    return ;
    if(root==n)
    {
        delete() n;
        root=NULL;
        return ;
    }
    if(root->leftchild==n)
    {
        delete() n;
        root->leftchild=NULL;
        return;
    }
    if(root->rightchild==n)
    {
        delete() n;
        root->rightchild=NULL;
        return;
    }
}
btree *deletenode(btree *root, int key)
{
    Queue q;
    if(root==NULL)
    return NULL;
    if(!root->leftchild && !root->rightchild)
    {
        if(root->data==key)
        {
        delete() root;
        root= NULL;
        }
         return root;
    }
        q.enqueue(root);
        btree *key_node=NULL;
        btree *curr_node=NULL;

        while(q.qsize!=0)
        {
            curr_node=q.dequeue();
            if(curr_node->data==key)
            {
                key_node= curr_node;
            }
            if(curr_node->leftchild)
            {
                q.enqueue(curr_node->leftchild);
            }
            if(curr_node->rightchild)
            {
                q.enqueue(curr_node->rightchild);
            }
            if(key_node)
            {
                key_node->data=curr_node->data;
                remove_node(root,curr_node);
            }

            return root;
        }

}

void inorderTraversal(btree *root){
    if(root == NULL) return;

    //left root right
    inorderTraversal(root->left);
    cout << root->data<<" ";
    inorderTraversal(root->right);
}

void preOrderTraversal(btree * root){
   
    if(root == NULL) 
    return;

    // Root Left Right
    cout << root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);

}

void postOrderTraversal(btree *root){
    if(root == NULL) return;

    // left right root
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);

    cout << root->data<<" ";

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
	   
	bst* rootptr;
	rootptr=NULL;
    btree *temp=rootptr;

    cout<<"Enter your choices : blah blah write it later 1 2 3 4 5 6 7 8 9 0\n";
    char ch;
    do{
    cin>>ch;
    switch(ch)
    {
        case 1: { cout<<"Enter an element: \n";
                 cin>>n;
                  temp=insert(temp,n);}
                  break;      

        case 2: 
    }
    }

    return 0;
}