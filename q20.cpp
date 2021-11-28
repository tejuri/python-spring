#include<iostream>
using namespace std;

struct linkedlist
{
    int data;
    struct linkedlist *next;
    
};

linkedlist *insert(linkedlist *head,int n)
{
    linkedlist *temp;
    linkedlist *input=new linkedlist();
    input->data=n;
    input->next=NULL;
    if(head==NULL)
    head=input;
    else
    {
        temp=head;
        while(temp->next!=NULL)
        temp=temp->next;

        temp->next=input;
    }
    return temp;
}
void insertatbegining(linkedlist *head,int d)
{
    linkedlist *input= new linkedlist();
    input->data=d;
    if(head==NULL)
    head=input;
    else
    {
        input->next=head;
        head=input;
    }
}
void reverse(linkedlist *head)
{
    linkedlist *prev = NULL, *curr = head;
 
    while (curr) {
        linkedlist* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    head = prev;
}
void traverse(linkedlist *head)
{
 
    linkedlist* temp = head;
 
    while (temp) {
        cout << temp->data;
        temp = temp->next;
    }
    cout << "NULL";
}

void sum(linkedlist *head1,linkedlist *head2,linkedlist *head3)
{
    reverse(head1);
    reverse(head2);

    int carry=0;

    linkedlist *temp1=head1;
    linkedlist *temp2=head2;

    while(temp1!=NULL && temp2!=NULL || carry==1)
    {
        int sum=0;
        if(temp1!=NULL)
        {
            sum+=temp1->data;
            temp1=temp1->next;
        }
        if(temp2!=NULL)
        {
            sum+=temp2->data;
            temp2=temp2->next;
        }
        sum+=carry;
        carry=sum/10;
        insertatbegining(head3,sum%10);
    }
}

int main()
{
    struct linkedlist *head1=NULL , *temp1;
    struct linkedlist *head2=NULL, *temp2;
    struct linkedlist *head3= NULL, *temp3;
    int n;
    cout<<"Enter the 1st number (enter -1 to stop entering): \n";
    while(1)
    {
        cin>>n;
        if(n==-1)
        break;
        temp1=insert(head1,n);
        temp1=temp1->next;
    }
    cout<<"Enter the 2nd number (enter -1 to stop entering): \n";
    while(1)
    {
        cin>>n;
        if(n==-1)
        break;
        temp2=insert(head2,n);
        temp2=temp2->next;
    }
    traverse(head1);
    cout<<endl;
    traverse(head2);
    cout<<endl;

    sum(head1,head2,head3);
    traverse(head3);

    return 0;
    
}