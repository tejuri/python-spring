#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node *prev;
}*head;
void create(int value)
{
    node *temp,*ptr;
    temp=new node();
    temp->data=value;
    temp->next=NULL;
    if(head==NULL)
    {
        temp->prev=NULL;
        head=temp;
    }
    else
    {
        ptr=head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
        temp->prev=ptr;
    
    }
}

void insertatbeginning(int value)
{
    if(head==NULL)
    {
        cout<<"Head is not created\n";
        return;
    }

    node *temp;
    temp=new node();
    temp->prev=NULL;
    temp->data=value;
    temp->next=head;
    head->prev=temp;
    head=temp;
    cout<<"Element inserted at the beginning\n";
}

void insertatlast(int value)
{
    node *ptr=new node();
    node *temp;
    if(ptr==NULL)
    {
        cout<<"Overflow\n";
    }
    else
    {
        ptr->data=value;
        if(head==NULL)
        {
            ptr->next=NULL;
            ptr->prev=NULL;
            head=ptr;
        }
        else
        {
            temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=ptr;
            ptr->prev=temp;
            ptr->next=NULL;
        }
    }
    cout<<"Element inserted at the end\n";
}

void insertafterposition(int value,int pos)
{
    if(head==NULL)
    {
        return;
    }
    node *temp,*ptr;
    int i;
    ptr=head;
    for(i=0;i<pos-1;i++)
    {
        ptr=ptr->next;
        if(ptr==NULL)
        {
            cout<<"Position doesn't exist\n";
            return;
        }
    }
    temp=new node();
    temp->data=value;
    if(ptr->next==NULL)
    {
        ptr->next=temp;
        temp->next=NULL;
        temp->prev=ptr;
    }
    else
    {
        temp->next=ptr->next;
        temp->next->prev=temp;
        ptr->next=temp;
        temp->prev=ptr;
    }
    cout<<"Element inserted\n"<<endl;

}

void insertaftervalue(int value1,int value2)
{
    node *temp=head;
    while(temp->data!=value2)
    temp=temp->next;
    node *ptr=new node();
    ptr->data=value1;
    ptr->next=temp->next;
    ptr->next->prev=ptr;
    ptr->prev=temp;
    temp->next=ptr;

}

void countofnodes()
{
    int count=0;
    node *temp=head;

    while(temp)
    {
        ++count;
        temp=temp->next;
        
    }
    cout<<"The count of elements in the doubly linked list is: "<<count<<endl;
}
void deleteelement(int value)
{
   node *temp, *temp2;
     
    if (head->data == value)
    {
        temp = head;
        head = head->next;  
        head->prev = NULL;
        cout<<"Element Deleted"<<endl;
        delete(temp);
        return;
    }
    temp2= head;
    while (temp2->next->next != NULL)
    {   
        if (temp2->next->data == value)  
        {
            temp = temp2->next;
            temp2->next = temp->next;
            temp->next->prev = temp2;
            cout<<"Element Deleted"<<endl;
            delete(temp);
            return;
        }
        temp2=temp2->next;
    }
     
    if (temp2->next->data == value)    
    { 	
        temp = temp2->next;
        delete(temp);
        temp2->next = NULL;
        cout<<"Element Deleted"<<endl;
        return;
    }
    cout<<"Element "<<value<<" not found"<<endl;
}

void deleteend(){
    node *temp=head;
    while(temp->next->next) 
    temp=temp->next;
    node *temp1=temp->next;
    temp->next=NULL;
    delete(temp1);
    cout<<"End deleted\n";
}
void deleteHead(){
    node *temp=head;
    head=head->next;
    head->prev=NULL;
    delete(temp);
    cout<<"Head deleted\n";
}
void deleteIndex(int i){
    node *temp=head;
    while(--i) 
    temp=temp->next;
    node *temp1=temp->next;
    temp->next=temp1->next;
    temp1->next->prev=temp;
    delete(temp1);

    cout<<"Element deleted\n";
}

void display()
{
    node *temp=head;
    cout<<"The elements are:\n";
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void reverseDisplay()
{
    node *temp=head;
    while(temp->next) temp=temp->next;
    while(temp) 
    {
        cout<<temp->data<<" "; 
        temp=temp->prev;
    }
    cout<<endl;
}

 
int main()
{
    head=NULL;
    int choice;
    int n,i,m;
     while (1)
    {
        cout<<"0.Exit"<<endl;
        cout<<"1.Insert Node at beginning"<<endl;
        cout<<"2.Insert node at last"<<endl;
        cout<<"3.Insert node after some node by value"<<endl;
        cout<<"4.Insert node at position"<<endl;
        cout<<"5.Delete at the beginning"<<endl;
        cout<<"6.Delete at the end"<<endl;
        cout<<"7.Delete node by value"<<endl;
        cout<<"8.Delete node at a given position"<<endl;
        cout<<"9.Reverse display"<<endl;
        cout<<"10. Display "<<endl;
        cout<<"11. Count of elements "<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 0: cout<<"Exit";
                exit(1);
                break;
        case 1:
            cout<<"Inserting Node at Beginning: "<<endl;
            cout<<"Enter the element to be inserted\n";
            cin>>n;
            insertatbeginning(n);
            cout<<endl;
            break;
        case 2:
            cout<<"Inserting Node at Last: "<<endl;
            cout<<"Enter the element to be inserted\n";
            cin>>n;
            insertatlast(n);
            cout<<endl;
            break;
        case 3:
            cout<<"Inserting Node after some node by value:"<<endl;
            cout<<"Enter the element to be inserted\n";
            cin>>n;
            cout<<"Enter the value after which element has to be inserted\n";
            cin>>m;
            insertaftervalue(n,m);
            cout<<endl;
            break;
        case 4:
            cout<<"Insert node at position"<<endl;
            cout<<"Enter the element to be inserted\n";
            cin>>n;
            cout<<"Enter the position after which element has to be inserted\n";
            cin>>m;
            insertafterposition(n,m);
            cout<<endl;
            break;
        case 5:
            cout<<"Delete at the beginning"<<endl;
            deleteHead();
            break;
        case 6:
            cout<<"6.Delete at the end"<<endl;
            deleteend();
            cout<<endl;
            break;
        case 7:
            cout<<"Delete node by value"<<endl;
            cout<<"Enter the element to be delete: "<<endl;
            cin>>n;
            deleteelement(n);
            cout<<endl;
            break;
        case 8:
            cout<<"Delete node at a given position"<<endl;
            cout<<"Enter the position of the node to be deleted:\n";
            deleteIndex(m);
            cout<<endl;
            break;
        case 9:
            cout<<"Reverse and display"<<endl;
            reverseDisplay();
            
            cout<<endl;
            break;
        case 10:
            cout<<"Display "<<endl;
            display();
            cout<<endl;
            break;
        case 11: 
            cout<<"Count of elements "<<endl;
            countofnodes();
            cout<<endl;
            break; 
        default:
            cout<<"Wrong choice"<<endl;
        }
    }
    return 0;

}