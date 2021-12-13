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
   ptr = head;
   while(ptr != NULL) {
      cout<< ptr->data <<" ";
      ptr = ptr->next;
   }
   cout<<endl;
}

int count() {
    int c=0;
   struct Node* ptr;
   ptr = head;
   while(ptr != NULL) {
      c++;
      ptr = ptr->next;
   }
   return c;
}
struct Node *front, *middle,*end1;
void frontMiddleend1Split(int a, int b, int c) {
   struct Node* ptr, *temp;
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
        }
        else{
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;}
        ptr = ptr->next;
   }
   while(ptr != NULL && b>0) {
        b--;
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
   while(ptr != NULL && c>0) {
        c--;
       struct Node* newNode = new Node;
        newNode->data = ptr->data;
        newNode->next = NULL;
        temp = end1;
        if (end1 == NULL) {
            newNode->prev = NULL;
            end1 = newNode;
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
    n = count();
    int a,b;
    if((n+1)%3 == 0){
        a = (n+1)/3;
        b = (n-2)/3;
    }
    else if((n-1)%3 == 0){
        a = (n-1)/3;
        b = (n+2)/3;
    }
    cout<<a<<" "<<b<<endl;
    frontMiddleend1Split(a,b,a);
    display(front);
    display(middle);
    display(end1);
return 0;
}
