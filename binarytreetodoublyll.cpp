#include<iostream>
using namespace std;

#include<iostream>
using namespace std;

#define MAX 2000
struct bst
{
    int data;
    bst *leftchild;
    bst *rightchild;
};
struct Node {
   int data;
   struct Node *prev;
   struct Node *next;
};
struct Node* head = NULL;
/*void insert(int newdata) {
   struct Node* newnode = new Node();
   newnode->data = newdata;
   newnode->prev = NULL;
   newnode->next = head;
   if(head != NULL)
   head->prev = newnode ;
   head = newnode;
}*/
void insert(int data) 
{
    struct Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    struct Node* temp = head;
    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;
        
    temp->next = newNode;
    newNode->prev = temp;
}
void display() {
   struct Node* ptr;
   ptr = head;
   while(ptr != NULL) {
      cout<< ptr->data <<" ";
      ptr = ptr->next;
   }
}
bst* newnode(int d)
{
    bst *input=new bst();
    input->data=d;
    input->leftchild=NULL;
    input->rightchild=NULL;

    return input;
}
bst* insert(bst *root,int data)
{
    if(root==NULL)
    {
   	 	root=newnode(data);    
    }
    if(data<root->data)
    root->leftchild=insert(root->leftchild,data);
    else if(data>root->data)
    root->rightchild=insert(root->rightchild,data);
    return root;
}
class stack
{
public:
    int elements[1000];
    int size;
    int top;
  stack()
  {
      size=20000;
      top=-1;
  }

void push(int x)
{
    if(top==size-1)
    cout<<"stack is full";
    else
    {
        elements[++top]=x;

    }

}
void pop()
{
    int t;
    if(top==-1)
     return ;
     
     else 
     {
    while(top!=-1)
    {
     insert(elements[top--]);
     
     }
     }
}
};

class Queue
{
    public: 
      int front,rear;
      bst *queue[MAX];
      int qsize;
      Queue()
      {
              front=rear=-1;
              qsize=0;
              
      }
 
       void enqueue(bst *item)
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
  
       bst *dequeue()
       {
              bst *item;
  
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
void btreetodoublyll(bst *root)
{
    if(root==NULL)
    return ;
    Queue q4;
    stack s4;
    int level=1;
    q4.enqueue(root);
    q4.enqueue(NULL);
    while(q4.qsize!=0)
    {
        bst *x=q4.dequeue();
        if(x!=NULL)
        {
            if(level%2!=0)
            {
                s4.push(x->data);
                if(x->leftchild!=NULL)
                {
                    q4.enqueue(x->leftchild);
                }
                if(x->rightchild!=NULL)
                {
                    q4.enqueue(x->rightchild);
                }
            }

            else if(level%2==0)
            {
                //cout<<x->data<<" ";
                insert(x->data);
                if(x->leftchild!=NULL)
                {
                    q4.enqueue(x->leftchild);
                }
                if(x->rightchild!=NULL)
                {
                    q4.enqueue(x->rightchild);
                }
            }
        }

        else if(q4.qsize!=0)
        {
            s4.pop();
            q4.enqueue(NULL);
            level++;
        }
    }
}

int main()
{
    Queue q;   
	bst* rootptr;
	rootptr=NULL;
	int n,i;
	cout<<"Enter numbers for tree:";
	cin>>n;
	rootptr=insert(rootptr,n);
	bst *temp=rootptr;
	
	while(1)
	{
	    cin>>n;
	    if(n==-1)
	    break;
	    temp=insert(temp,n);
	}
    cout<<endl;
  
  btreetodoublyll(rootptr);

  display();

return 0;
}


