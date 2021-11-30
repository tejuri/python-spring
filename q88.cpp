#include<iostream>
using namespace std;
struct linkedlist
{
    int data;
    linkedlist *next;
};
linkedlist *nodecreation(int value)
{
    linkedlist *temp=new linkedlist();
    if (temp == NULL)
    {
        cout<<"Memory not allocated "<<endl;
        return 0;
    }
    else
    {
        temp->data = value;
        temp->next = NULL;     
        return temp;
    }

}
void insertatbeginning(linkedlist *head)
{
    int n;
    cout<<"Enter the value to be inserted:\n";
    cin>>n;
    linkedlist *temp,*head1;
    temp=nodecreation(n);
    if(head==NULL)
    {
        head=temp;
        head->next=NULL;

    }
    else
    {
        head1=head;
        head=temp;
        head->next=head1;

    }
    cout<<"Element Inserted at beginning"<<endl;

}

void insertatlast(linkedlist *head)
{
    int value;
    cout<<"Enter the value to be inserted: ";
    cin>>value;
    linkedlist *temp,*head1;
    temp=nodecreation(value);
    head1=head;
    while(head1->next!=NULL)
    {
        head1=head1->next;
    }
    temp->next=NULL;
    head1->next = temp;
    cout<<"Element Inserted at last"<<endl;  
}

void insertinbetweenbyvalue(linkedlist *head)
{
    linkedlist *prev,*temp;
    int n,m;
    cout<<"Enter the value to be inserted:\n";
    cin>>n;
    cout<<"Enter the value of the node after which element has to be inserted:\n";
    cin>>m;
    temp=nodecreation(n);
    prev=head;
    while(prev->data!=m)
    {
        prev=prev->next;
    }

    temp->next=prev->next;
    prev->next=temp;

}
void insertatposition(linkedlist *head)
{
    linkedlist *temp1,*temp,*ptr;
    int n,pos,counter=0,i;
    cout<<"Enter the value to be inserted:\n";
    cin>>n;
    cout<<"Enter the postion at which node to be inserted:\n";
    cin>>pos;
    temp=nodecreation(n);
    temp1=head;
    while(temp1!=NULL)
    {
        temp1=temp1->next;
        ++counter;
    }
    if (pos == 1)
    {
        if (head== NULL)
        {
            head= temp;
            head->next = NULL;
        }
        else
        {
            ptr=head;
            head= temp;
            head->next=ptr;
        }
    }
     else if (pos > 1  && pos <= counter)
    {
        temp1= head;
        for (i = 1; i < pos; i++)
        {
            ptr = temp1;
            temp1 = temp1->next;
        }
        ptr->next = temp;
        temp->next = temp1;
    }
    else
    {
        cout<<"Positon out of range"<<endl;
    }
}


void reverse(linkedlist *head)
{
   linkedlist *ptr1, *ptr2, *ptr3;
    if (head== NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    if (head->next == NULL)
    {
        return;
    }  
    ptr1 = head;
    ptr2 = ptr1->next;
    ptr3 = ptr2->next;
    ptr1->next = NULL;
    ptr2->next = ptr1;
    while (ptr3 != NULL)
    {
        ptr1 = ptr2;
        ptr2 = ptr3;
        ptr3 = ptr3->next;
        ptr2->next = ptr1;         
    }
    head= ptr2;
}

void countofnodes(linkedlist *head)
{
    linkedlist *temp=head;
    int count=0;
    while(temp!=NULL)
    {
        temp=temp->next;
        ++count;

    }
    cout<<"The count of nodes is: "<<count<<endl;
}

void display(linkedlist *head)
{
     linkedlist *temp;
    if (head == NULL)
    {
        cout<<"The List is Empty"<<endl;
        return;
    }
    temp = head;
    cout<<"Elements of list are: "<<endl;
    while (temp != NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void deletefrombeginning(linkedlist *head)
{
    if(head==NULL)
    {
    cout<<"No node to delete\n";
    return;
    }

    linkedlist *temp=head;
    head=head->next;
    delete temp;

}

void deleteattheend(linkedlist *head)
{
    if(head==NULL)
    {
        cout<<"No node to delete\n";
        return;
    }
    if(head->next==NULL)
    {
        delete head;
        
    }
    linkedlist *prev=head;
    while(prev->next->next!=NULL)
    {
        prev=prev->next;
    }

    delete(prev->next);

    prev->next=NULL;
    cout<<"Deleted end node\n";
}

void deletebyvalue(linkedlist *head)
{
    int n;
    cout<<"Enter value of node to be deleted:\n";
    cin>>n;
    if(head==NULL)
    {
        cout<<"No node to be deleted\n";
        return;
    }

    linkedlist *temp,*ptr;
    if(head->data==n)
    {
        ptr=head;
        head=head->next;
        delete ptr;
    }

    temp=head;
    while(temp->next->data!=n)
    {
        temp=temp->next;
    }
    linkedlist *to_be_deleted=temp->next;
    temp->next=temp->next->next;

    delete to_be_deleted;

    cout<<"Element deleted\n";
}

void delete_pos(linkedlist *head)
{
    int pos, i, counter = 0;
    if (head == NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    cout<<"Enter the position of value to be deleted: ";
    cin>>pos;
    linkedlist *temp, *ptr;
    temp= head;
    if (pos == 1)
    {
        head = temp->next;
    }
    else
    {
        while (temp!= NULL)
        {
            temp=temp->next;
            counter++;  
        }
        if (pos > 0 && pos <= counter)
        {
            temp= head;
            for (i = 1;i < pos;i++)
            {
                ptr =temp;
                temp=temp->next;
            }
            ptr->next =temp->next;
        }
        else
        {
            cout<<"Position out of range"<<endl;
        }
        delete temp;
        cout<<"Element Deleted"<<endl;
    }
}

int main()
{
    int choice;
    linkedlist *head=NULL;
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
        cout<<"9.Reverse and display"<<endl;
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
            insertatbeginning(&head);
            cout<<endl;
            break;
        case 2:
            cout<<"Inserting Node at Last: "<<endl;
            insertatlast(&head);
            cout<<endl;
            break;
        case 3:
            cout<<"Inserting Node after some node by value:"<<endl;
            insertinbetweenbyvalue(&head);
            cout<<endl;
            break;
        case 4:
            cout<<"Insert node at position"<<endl;
            insertatposition(&head);
            cout<<endl;
            break;
        case 5:
            cout<<"Delete at the beginning"<<endl;
            deletefrombeginning(&head);
            break;
        case 6:
            cout<<"Delete at the end"<<endl; 
            deleteattheend(&head);
            cout<<endl;
            break;
        case 7:
            cout<<"Delete node by value"<<endl;
            deletebyvalue(&head);
            cout<<endl;
            break;
        case 8:
            cout<<"Delete node at a given position"<<endl;
            delete_pos(&head);
            cout<<endl;
            break;
        case 9:
            cout<<"Reverse and display"<<endl;
            reverse(&head);
            display(head);
            cout<<endl;
            break;
        case 10:
            cout<<"Display "<<endl;
            display(head);
            cout<<endl;
            break;
        case 11: 
            cout<<"11. Count of elements "<<endl;
            countofnodes(head);
            cout<<endl;
            break; 
        default:
            cout<<"Wrong choice"<<endl;
        }
    }
    return 0;

}
 


 