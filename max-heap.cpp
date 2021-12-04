#include <iostream>
using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
      largest = left;

    if (right < n && arr[right] > arr[largest])
      largest = right;

    if (largest != i) {
      swap(&arr[i], &arr[largest]);
      heapify(arr, n, largest);
    }
}

void insert(int arr[], int* n, int k)
{
    *n=*n+1;
    int i = *n-1;
    arr[i] = k;
    int parent = (i-1)/2;

    while (i != 0 && arr[parent] < arr[i])
    {
       swap(&arr[i], &arr[parent]);
       i = parent;
       parent = (i-1)/2;
    }
}

int getMax(int arr[], int* n)
{
    int root = arr[0];
    arr[0] = arr[*n-1];
    *n=*n-1;
    heapify(arr,*n,0);

    return root;
}

void deleteAtIndex(int arr[], int *n, int i)
{
    arr[i] = INT_MAX;
    int parent = (i-1)/2;

    while (i != 0 && arr[parent] < arr[i])
    {
       swap(&arr[i], &arr[parent]);
       i = parent;
       parent = (i-1)/2;
    }
    getMax(arr,n);
}

int main() {
    int arr[20000];
    int n, size=0,ch;
    cout<<"Implementation of min-heap \n";
    cout<<"1. Insert\n";
    cout<<"2. Delete\n";
    cout<<"0. Exit\n";
    do{
    cout<<"Enter your choice: \n";
    cin>>ch;
    switch(ch)
    {
        case 0: break;
        case 1: cout<<"Enter the element to be inserted\n";cin>>n;insert(arr, &size, n);break;
        case 2: cout<<"Enter the index of element to be deleted\n";cin>>n;deleteAtIndex(arr, &size, n);break;
    }

}while(ch!=0);
    cout<<getMax(arr, &size);
    return 0;
}
