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
    if(head==NULL){
    head=input;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        temp=temp->next;

        temp->next=input;
    }
    return head;
}
void traverse(linkedlist *head)
{

    linkedlist* temp = head;

    while (temp) {
        cout << temp->data;
        temp = temp->next;
    }
}
linkedlist* insertatbegining(linkedlist *head,int d)
{
    linkedlist *input= new linkedlist();
    input->data=d;
    input->next=NULL;
    if(head==NULL)
    head=input;
    else
    {
        input->next=head;
        head=input;
    }
    return head;
}
linkedlist* reverse(linkedlist *head)
{
    linkedlist *prev = NULL, *curr = head;

    while (curr) {
        linkedlist* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    head = prev;
    return head;
}

linkedlist* sum(linkedlist *head1,linkedlist *head2,linkedlist *head3)
{
    head1 = reverse(head1);
    head2 = reverse(head2);

    int carry=0;

    linkedlist *temp1=head1;
    linkedlist *temp2=head2;

    while(temp1!=NULL || temp2!=NULL || carry==1)
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
        head3 = insertatbegining(head3,sum%10);
    }
    return head3;
}

int main()
{
    struct linkedlist *head1=NULL;
    struct linkedlist *head2=NULL;
    struct linkedlist *head3= NULL;
    int n;
    cout<<"Enter the 1st number (enter -1 to stop entering): \n";
    while(1)
    {
        cin>>n;
        if(n==-1)
        break;
        head1=insert(head1,n);
    }
    cout<<"Enter the 2nd number (enter -1 to stop entering): \n";
    while(1)
    {
        cin>>n;
        if(n==-1)
        break;
        head2=insert(head2,n);
    }
    cout<<"list 1: ";
    traverse(head1);
    cout<<endl;
    cout<<"list 2: ";
    traverse(head2);
    cout<<endl;

    head3 = sum(head1,head2,head3);
    cout<<"Total : ";
    traverse(head3);

    return 0;

}
