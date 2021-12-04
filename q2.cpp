#include<iostream>
using namespace std;

class stack
{
    int *ptr,index,size;
    public :
    int count=0;
    stack()
    {
        index=-1;
        size=2000;
        ptr= new int[size];
    }
    void push(int data)
    {
        if(index>=size)
        {
            cout<<"Stack overflow\n";
        }
        else
        {
            //*(ptr+index)=data;
            ptr[++index]=data;
            cout<<"Element pushed\n";

            ++count;
        }
    }

    void pop()
    {
        if(index==-1)
        cout<<"Stack id empty\n";

        else
        cout<<"Element popped is: "<<*(ptr+index)<<endl;
         index--;
        count--;
    }

    void displaytop()
    {
        if(index==-1)
        {
            cout<<"Stack is empty";
        }
        else
        cout<<"The top element is: "<<*(ptr+index)<<endl;
    }

    void displayelements()
    {
        cout<<"The elements are: \n";
        for(int i=0;i<=index;i++)
        {
            cout<<ptr[i]<<" ";
        }
        cout<<endl;
    }

    void swappingtwotopelements()
    {
        cout<<"Element at top before swapping:\n";
        displaytop();

        int temp= *(ptr+index);
        *(ptr+index)=*(ptr+(index-1));
        *(ptr+(index-1))=temp;

        cout<<"Element at top after swapping: \n";
        displaytop();
    }

    void countofelements()
    {
        cout<<"The count of elements in the stack is: "<<count;
    }
};

int main()
{
    stack s1;
    char ch;
    int n;

    cout<<"Implementation of stack using pointer:\n";
    cout<<"1. Push\n";
    cout<<"2. Pop\n";
    cout<<"3. Display of top element of stack\n";
    cout<<"4. Swap top two elements of the stack\n";
    cout<<"5. Count the number of elements in the stack\n";
    cout<<"6. Display the elements of the stack\n";
    cout<<"0. Exit\n";
    do{
    cout<<"Enter your choice: \n";
    cin>>ch;
    switch(ch)
    {
        case '0': break;
        case '1': { cout<<"Enter the element to be pushed: ";
                    cin>>n;
                    s1.push(n);
                  }
                  break;
        case '2':  {
                    cout<<"Pop\n";
                    s1.pop();
                    }
                break;
        case '3': {
                    s1.displaytop();
        }       break;
        case '4':  {
                    s1.swappingtwotopelements();
                 }
                 break;
        case '5': {
                    s1.countofelements();
        }
                break;

        case '6': {
                   cout<<"Display:\n";
                   s1.displayelements();
                    }
                    break;
    }

}while(ch!='0');

return 0;
}
