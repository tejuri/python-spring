#include<iostream>
#include<cmath>
using namespace std;

void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

class MinHeap {
  public:
    int *arr; 
  int capacity; 
  int heap_size; 

  MinHeap(int cap) 
  {
    heap_size = 0;
    capacity = cap;
  arr=new int[cap];
  }
  int parent(int i) 
  {
    return (i-1)/2;
  }

  int left(int i) 
  {
    return (2*i+1);
  }

  int right(int i) {
    return (2*i+2);
  }

  int getMin() 
  {
    return arr[0];
  }

  void insertKey(int k) {
    if (heap_size == capacity) {
      cout << "\nOverflow: Could not insert Key\n";
      return;
    }

    heap_size++;
    int i = heap_size - 1;
    arr[i] = k;

    while (i != 0 &&arr[parent(i)] >arr[i]) {
      swap(arr[i],arr[parent(i)]);
      i = parent(i);
    }
  }
  void decreaseKey(int i, int value) {
  arr[i]=value;
    while (i != 0 &&arr[parent(i)] >arr[i]) 
    {
      swap(arr[i],arr[parent(i)]);
      i = parent(i);
    }
  }

  void deleteKey(int i) {
    decreaseKey(i, INT_MIN);
    extractMin();
  }
  void linearSearch(int val) {
    for (int i = 0; i < heap_size; i++) {
      if(arr[i] == val) {
        cout << "Value Found!";
        return;
      }
    }
    cout << "Value NOT Found!";
  }

  int extractMin() {
    if (heap_size <= 0)
      return INT_MAX;
    if (heap_size == 1) {
      heap_size--;
      return arr[0];
    }

    
    int root =arr[0];
  arr[0] =arr[heap_size - 1];
    heap_size--;
    MinHeapify(0);

    return root;
  }

  void MinHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size &&arr[l] <arr[i])
      smallest = l;
    if (r < heap_size &&arr[r] <arr[smallest])
      smallest = r;
    if (smallest != i) {
      swap( &arr[i], &arr[smallest]);
      MinHeapify(smallest);
    }
  }

  void printArray() {
    for (int i = 0;i< heap_size;i++)
      cout <<arr[i]<< " ";
    cout << endl;
  }
  /*int height() 
  {
    return ceil(log2(heap_size+1))-1;
  }*/

};

int main() {
  int s;
  cout << "Enter Size of Min Heap" << endl;
  cin >> s;
  MinHeap obj(s);
  cout << "Min Heap Created" << endl;

  int option, val;

  do {
    cout << "What operation do you want to perform? " <<" Select Option number. Enter 0 to exit." << endl;
    cout << "1. Insert Key/Node" << endl;
    cout << "2. Search Key/Node" << endl;
    cout << "3. Delete Key/Node" << endl;
    cout<<"4. Display "<<endl;
    cout << "0. Exit Program" << endl;

    cin >> option;

    switch (option) {
    case 0:
      break;
    case 1:
      cout << "INSERT Operation" << endl;
      cout << "Enter value to insert: ";
      cin >> val;
      obj.insertKey(val);
      cout << endl;
      break;
    case 2:
      cout << "SEARCH Operation" << endl;
      cout << "Enter value to search: ";
      cin >> val;
      obj.linearSearch(val);
      break;
    case 3:
      cout << "DELETE Operation" << endl;
      cout << "Enter index of heap array to delete: ";
      cin >> val;
      obj.deleteKey(val);
      break;
    case 4:
      cout<<"DISPLAY Operation"<<endl;
      obj.printArray();
      break;
    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);

  return 0;
}