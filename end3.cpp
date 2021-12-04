#include<iostream>
#include <math.h>
using namespace std;

struct linkedlist
{
    int data;
    struct linkedlist *next;

};

linkedlist *insert(linkedlist *head,int data)
{
    linkedlist *temp;
    linkedlist *input=new linkedlist();
    input->data=data;
    input->next=NULL;
    if(head==NULL){
    head=input;
    input->next=head;
    }
    else
    {
        temp=head;
        while(temp->next!=head)
        temp=temp->next;
        temp->next=input;
        input->next=head;
    }
    return head;
}

void traverse(linkedlist *head)
{
    if(head==NULL) return;
    linkedlist* temp = head;
    cout<<temp->data<<" ";
    temp=temp->next;

    while (temp!=head) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int totalElements(linkedlist *head)
{
    int count=1;
    if(head==NULL)return 0;
    linkedlist* temp = head;
    temp=temp->next;

    while (temp!=head) {
        count++;
        temp = temp->next;
    }
    return count;
}

linkedlist* traverseToKth(linkedlist *head, int k)
{
    if(head==NULL) return NULL;
    linkedlist* temp = head;


    for(int i=1;i<=k-1;i++)
        temp=temp->next;
    int t = temp->data;
    temp->data = temp->next->next->data;
    temp->next->next->data =t;
    return head;
}



int main()
{
    struct linkedlist *head=NULL;
    int n,k;
    cout<<"enter the data for circular queue\n";
    while(1)
    {
        cin>>n;
        if(n==-1)
        break;
        head=insert(head,n);
    }

    int count = totalElements(head);
    cout<<"the circular link list before alteration: \t";
    traverse(head);
    cout<<endl;
    do{
        count--;
        cout<<"enter k"<<endl;
        cin>>k;
        head = traverseToKth(head,k);
        cout<<"Tranversal after this iteration:\t";
        traverse(head);
        cout<<endl;
    }while(count>0);

    return 0;

}
