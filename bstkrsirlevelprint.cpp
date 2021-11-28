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
     cout<<elements[top--]<<" ";
     
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
void levelorder(bst *root)
{
    Queue q1;
    if(root==NULL)
    return ;
    q1.enqueue(root);

    while(q1.qsize!=0)
    {
        bst *x=q1.dequeue();

        cout<<x->data<<" ";

        if(x->leftchild!=NULL)
        {
            q1.enqueue(x->leftchild);
        }

        if(x->rightchild!=NULL)
        {
            q1.enqueue(x->rightchild);
        }
    }

}
void reversereverselevelorder(bst *root)
{
    Queue q2;
    stack s1;
    if(root==NULL)
    return ;
    q1.enqueue(root);

    while(q1.qsize!=0)
    {
        bst *x=q1.dequeue();

        s1.push(x->data);

        if(x->leftchild!=NULL)
        {
            q1.enqueue(x->leftchild);
        }

        if(x->rightchild!=NULL)
        {
            q1.enqueue(x->rightchild);
        }
    }
    s1.pop();

}
void reverselevelorder(bst *root)
{
    Queue q3;
    stack s3;
    if(root==NULL)
    return ;
    q3.enqueue(root);

    while(q3.qsize!=0)
    {
        bst *x=q3.dequeue();

        s3.push(x->data);

        if(x->rightchild!=NULL)
        {
            q3.enqueue(x->rightchild);
        }

        if(x->leftchild!=NULL)
        {
            q3.enqueue(x->leftchild);
        }
    }
    s3.pop();

}
void squirrellevlorder(bst *root)
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

                if(x->rightchild!=NULL)
                {
                    q4.enqueue(x->rightchild);
                }
                if(x->leftchild!=NULL)
                {
                    q4.enqueue(x->leftchild);
                }
            }

            else if(level%2==0)
            {
                cout<<x->data<<" ";
                if(x->rightchild!=NULL)
                {
                    q4.enqueue(x->rightchild);
                }
                if(x->leftchild!=NULL)
                {
                    q4.enqueue(x->leftchild);
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
void antisquirrellevlorder(bst *root)
{
    if(root==NULL)
    return ;
    Queue q5;
    stack s5;
    int level=1;
    q5.enqueue(root);
    q5.enqueue(NULL);
    while(q5.qsize!=0)
    {
        bst *x=q5.dequeue();
        if(x!=NULL)
        {
            if(level%2!=0)
            {
                s5.push(x->data);
                if(x->leftchild!=NULL)
                {
                    q5.enqueue(x->leftchild);
                }
                if(x->rightchild!=NULL)
                {
                    q5.enqueue(x->rightchild);
                }
            }

            else if(level%2==0)
            {
                cout<<x->data<<" ";
                
                if(x->leftchild!=NULL)
                {
                    q5.enqueue(x->leftchild);
                }
                if(x->rightchild!=NULL)
                {
                    q5.enqueue(x->rightchild);
                }
            }
        }

        else if(q5.qsize!=0)
        {
            s5.pop();
            q5.enqueue(NULL);
            level++;
        }
    }
}





int main()
{
    Queue q;
	s.size=20000;
    s.top=-1;
	
	   
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
     
     levelorder(rootptr);
     cout<<endl;
     reversereverselevelorder(rootptr);
     cout<<endl;
     reverselevelorder(rootptr);
     cou<<endl;
     squirrellevlorder(rootptr);
     cout<<endl;
     antisquirrellevlorder(rootptr);

     return 0;
}