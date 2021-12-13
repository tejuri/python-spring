#include<iostream>
using namespace std;
struct Node {
   int data;
   struct Node *prev;
   struct Node *next;
};
struct Node* head = NULL;

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

void display(Node* head) {
   struct Node* ptr;
   ptr = ;
   while(ptr != NULL) {
      cout<< ptr->data <<" ";
      ptr = ptr->next;
   }
   cout<<endl;
}

int count() {
    int c=0
   struct Node* ptr;
   ptr = head;
   while(ptr != NULL) {
      c++;
      ptr = ptr->next;
   }
   return c;
}
truct Node *front, *middle,*end;
int frontMiddleEndSplit(int a, int b) {
   struct Node* ptr, *temp, *front, *middle,*end;
   ptr = head;
   while(ptr != NULL && a>0) {
        a--;
       struct Node* newNode = new Node;
        newNode->data = ptr->data;
        newNode->next = NULL;
        temp = front;
        if (front == NULL) {
            newNode->prev = NULL;
            front = newNode;
            return;
        }
        else{
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;}
        ptr = ptr->next;
   }
   while(ptr != NULL && b>0) {
        a--;
       struct Node* newNode = new Node;
        newNode->data = ptr->data;
        newNode->next = NULL;
        temp = middle;
        if (middle == NULL) {
            newNode->prev = NULL;
            middle = newNode;
        }
        else{
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;}
        ptr = ptr->next;
   }
   while(ptr != NULL && a>0) {
        a--;
       struct Node* newNode = new Node;
        newNode->data = ptr->data;
        newNode->next = NULL;
        temp = end;
        if (end == NULL) {
            newNode->prev = NULL;
            end = newNode;
        }
        else{
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;}
        ptr = ptr->next;
   }
}

int main(){
    int n, input;
    cout <<"enter the number of items(Enter -1 to exit.)\n";
    while(1){
        cin>>n;
        if(n==-1)break;
        insert(n);
    }
    display(head);
    int n = count();
    int a,b;
    if((n+1)%3 == 0){
        a = (n+1)/3;
        b = (n-2)/3;
    }
    else if((n-1)%3 == 0){
        a = (n-1)/3;
        b = (n+2)/3;
    }
    display(front);
    display(middle);
    display(end);
return 0;
}
