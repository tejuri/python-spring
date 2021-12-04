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
void display() {
   struct Node* ptr;
   ptr = head;
   while(ptr != NULL) {
      cout<< ptr->data <<" ";
      ptr = ptr->next;
   }
}

void swap(int n) {
    int k=n/2;
   struct Node* ptr, *temp;
   ptr = head;
   temp = head;
   while(ptr->next != NULL) {
      ptr = ptr->next;
   }
   while(temp!=NULL && ptr!=NULL&&k>0){
        k--;
    int n1 = temp->data;
    int n2 = ptr->data;
    temp->data =n2;
    ptr->data = n1;
    temp=temp->next;
    ptr = ptr->prev;
   }
}


void updateInfo(int n) {
    int k=n/2;
   struct Node* ptr, *temp;
   ptr = head;
   temp = head;
   while(ptr->next != NULL) {
      ptr = ptr->next;
   }

   while(temp!=NULL  && ptr!=NULL && k>0){
    k--;
    int n1 = temp->data;
    int n2 = ptr->data;
    temp->data = n1 + n2;
    ptr->data = n1*n2;
    temp=temp->next;
    ptr = ptr->prev;
   }
   swap(n);
}

int main(){
    int n, input;
    cout <<"enter the number of nodes\n";
    cin>>n;
    if(n%2!=0){
        cout<<"n needs to be even";
        return 0;
    }
    for(int i=0;i<n;i++){
        cin>>input;
        insert(input);
    }
    updateInfo(n);
    display();
return 0;
}
