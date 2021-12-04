#include<iostream>
#include <math.h>
using namespace std;

struct linkedlist
{
    int coefficient;
    int degree;
    struct linkedlist *next;

};

linkedlist *insert(linkedlist *head,int coefficient, int degree)
{
    linkedlist *temp;
    linkedlist *input=new linkedlist();
    input->coefficient=coefficient;
    input->degree=degree;
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
        cout<<temp->coefficient<<"x^"<<temp->degree;
        if(temp->next!=NULL)
            cout<<" + ";
        temp = temp->next;
    }
}

void polynomialValue(linkedlist *head, int value)
{
    linkedlist* temp = head;
    long sum =0;
    while (temp) {
        sum+=temp->coefficient* pow(value,temp->degree);
        temp = temp->next;
    }
    cout<<"value of the polynomial (";
    traverse(head);
    cout<<") at "<<value<<" is: "<<sum<<endl;
}

linkedlist* sumPolyonmial(linkedlist *head1,linkedlist *head2,linkedlist *head3)
{
    linkedlist *temp1=head1;
    linkedlist *temp2=head2;

    while(temp1!=NULL || temp2!=NULL)
    {
        int sum=0,degree=0;
        if(temp1!=NULL && temp2==NULL)
        {
            sum=temp1->coefficient;
            degree=temp1->degree;
            temp1=temp1->next;
        }
        else if(temp2!=NULL && temp1==NULL)
        {
            sum=temp2->coefficient;
            degree=temp2->degree;
            temp2=temp2->next;
        }
        else if(temp1->degree > temp2->degree)
        {
            sum=temp1->coefficient;
            degree=temp1->degree;
            temp1=temp1->next;
        }
        else if(temp1->degree < temp2->degree)
        {
            sum=temp2->coefficient;
            degree=temp2->degree;
            temp2=temp2->next;
        }
        else if(temp1->degree == temp2->degree)
        {
            sum=temp2->coefficient + temp1->coefficient;
            degree=temp2->degree;
            temp2=temp2->next;
            temp1=temp1->next;
        }
        head3 = insert(head3,sum,degree);
    }
    return head3;
}

linkedlist* copy(linkedlist* head1, linkedlist* head2){
    linkedlist *temp1=head1;
    while(temp1!=NULL){
        head2=insert(head2,temp1->coefficient,temp1->degree);
        temp1=temp1->next;
    }
    return head2;
}

linkedlist* product(linkedlist *head1,linkedlist *head2,linkedlist *head3)
{
    linkedlist *temp1=head1;
    linkedlist *temp2=head2;
    linkedlist *temp4=NULL;
    while(temp1!=NULL)
    {
        linkedlist *temp3=NULL;
        temp2 = head2;
        while(temp2!=NULL){
            int coefficient = temp1->coefficient * temp2->coefficient;
            int degree = temp1->degree + temp2->degree;
            temp3 = insert(temp3,coefficient,degree);
            temp2=temp2->next;
        }
        temp1=temp1->next;
        temp4=NULL;
        temp4 = copy(head3,temp4);
        head3=NULL;
        head3 = sumPolyonmial(temp4,temp3, head3);
    }
    return head3;
}


int main()
{
    struct linkedlist *head1=NULL;
    struct linkedlist *head2=NULL;
    struct linkedlist *head3= NULL;
    struct linkedlist *head4= NULL;
    int n1,n2,value;
    cout<<"************** Assuming that polynomials are given such that degree are in increasing order **************\n";
    cout<<"Enter the coefficient followed by degree (enter (-1,-1) to stop entering): \n";
    while(1)
    {
        cin>>n1>>n2;
        if(n1==-1 && n2==-1)
        break;
        head1=insert(head1,n1,n2);
    }
    cout<<"Enter the coefficient followed by degree (enter (-1,-1) to stop entering): \n";
    while(1)
    {
        cin>>n1>>n2;
        if(n1==-1 && n2==-1)
        break;
        head2=insert(head2,n1,n2);
    }
    cout<<"polynomial 1: ";
    traverse(head1);
    cout<<endl;
    cout<<"polynomial 2: ";
    traverse(head2);
    cout<<endl;
    cout<<endl;

    head3 = sumPolyonmial(head1,head2,head3);
    cout<<"sum of polynomial : ";
    traverse(head3);
    cout<<endl;
    cout<<endl;

    head4 = product(head1,head2,head4);
    cout<<"product of polynomial : ";
    traverse(head4);
    cout<<endl;
    cout<<endl;

    cout<<"enter the value at which polynomial should be calculated"<<endl;
    cin>>value;

    polynomialValue(head1,value);

    return 0;

}
