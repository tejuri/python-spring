#include<iostream>
#include <stack>
using namespace std;
#define SIZE 5000
struct Queue
{
    int front, rear;
    int size;
    struct node* *array;
};


struct Queue* createQueue(int size)
{
    struct Queue* queue = (struct Queue*) malloc(sizeof( struct Queue ));

    queue->front = queue->rear = -1;
    queue->size = size;

    queue->array = (struct node**) malloc
                   (queue->size * sizeof( struct node* ));

    int i;
    for (i = 0; i < size; ++i)
        queue->array[i] = NULL;

    return queue;
}

int isEmpty(struct Queue* queue)
{
    return queue->front == -1;
}

int isFull(struct Queue* queue)
{  return queue->rear == queue->size - 1; }

int hasOnlyOneItem(struct Queue* queue)
{  return queue->front == queue->rear;  }

void Enqueue(struct node *root, struct Queue* queue)
{
    if (isFull(queue))
        return;

    queue->array[++queue->rear] = root;

    if (isEmpty(queue))
        ++queue->front;
}

struct node* Dequeue(struct Queue* queue)
{
    if (isEmpty(queue))
        return NULL;

    struct node* temp = queue->array[queue->front];

    if (hasOnlyOneItem(queue))
        queue->front = queue->rear = -1;
    else
        ++queue->front;

    return temp;
}

struct node* getFront(struct Queue* queue)
{  return queue->array[queue->front]; }

struct node
{
    int data;
    struct node *right,*left;
};

struct node* newNode(int data)
{
    struct node* temp = new node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void reverseinordertraversal(node *root)
 {
     if (root == NULL)
        return;


    reverseinordertraversal(root->right);


    cout<<root->data<<" ";

    reverseinordertraversal(root->left);
 }

 void selectedPath(node *root, int level=0)
 {
     if (root == NULL)
        return;

    cout<<root->data<<" ";
    if(level%2==0)
    selectedPath(root->left, 1);
    else selectedPath(root->right, 0);
 }

node* interchange(struct node* root)
{
    struct Queue* queue = createQueue(SIZE);
    stack<node*> stack;
    Enqueue(root, queue);
    Enqueue(NULL, queue);
    int data, level=0;
    while (!isEmpty(queue))
    {
        struct node* temp = Dequeue(queue);
        if(temp==NULL){
            while (!stack.empty()) {
                struct node* temp1 = stack.top();
                struct node* front = getFront(queue);
                int x = temp1->data;
                temp1->data=front->data;
                front->data=x;
                Dequeue(queue);
                stack.pop();
                Enqueue(front, queue);
            }
        }
        if (temp&&temp->left){
            Enqueue(temp->left, queue);
            stack.push(temp->left);
        }

        if (temp&&temp->right){
            Enqueue(temp->right, queue);
            stack.push(temp->right);
        }
        Enqueue(NULL, queue);
    }
    return root;
}

struct node* constructTree(struct node* node, int data)
{
    if (node == NULL)
        return newNode(data);

    if (data < node->data)
        node->left = constructTree(node->left, data);
    else if (data > node->data)
        node->right = constructTree(node->right, data);

    return node;
}

void levelOrder(struct node* root)
{
    struct Queue* queue = createQueue(SIZE);

    stack<node*> stack;

    Enqueue(root, queue);

    while (!isEmpty(queue))
    {
        struct node* temp = Dequeue(queue);

        cout<<temp->data<<" ";

        if (temp->left)
            Enqueue(temp->left, queue);

        if (temp->right)
            Enqueue(temp->right, queue);
    }
}

int main(){
    struct Queue* queue = createQueue(SIZE);
    int n;
    struct node* root = NULL;
    while(1){
        cin>>n;
        if(n==-1)break;
        root = constructTree(root,n);
    }
    root = interchange(root);
    cout<<endl;
    levelOrder(root);
}
