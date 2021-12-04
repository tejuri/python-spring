#include<iostream>
using namespace std;
#define SIZE 5000
struct Queue
{
    int front, rear;
    int size;
    struct node* *array;
};

// A utility function to create a new Queue
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

// Standard Queue Functions
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

node* constructTree(struct node* root, struct Queue* queue)
{
    Enqueue(NULL, queue);

    int data, level=0;

    while (!isEmpty(queue))
    {
        struct node* temp1 = Dequeue(queue);

        if(temp1==NULL){
            level++;
            Enqueue(NULL, queue);
            continue;
        }
        struct node* temp2 = Dequeue(queue);
        if(temp2==NULL){
            return temp1;
        }

        if(level%2==0)
        data = min(temp1->data, temp2->data);
        else
        data = max(temp1->data, temp2->data);

        struct node* temp = newNode(data);
        temp->left = temp1;
        temp->right = temp2;

        Enqueue(temp, queue);
    }
}

int main(){
    struct Queue* queue = createQueue(SIZE);
    int n;
    struct node* root = NULL;
    while(1){
        cin>>n;
        if(n==-1)break;
        Enqueue(newNode(n), queue);
    }
    root = constructTree(root, queue);
    cout<<"The reverse inorder traversal: \n";
    reverseinordertraversal(root);
    cout<<endl;
    cout<<"The selected path from root: \n";
    selectedPath(root,0);
    cout<<endl;

}
