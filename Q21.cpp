#include<iostream>
#include<string.h>
using namespace std;

#define MAX 2000
struct bst
{
    string data;
    bst *leftchild;
    bst *rightchild;
};
bst* newnode(string d)
{
    bst *input=new bst();
    input->data=d;
    input->leftchild=NULL;
    input->rightchild=NULL;

    return input;
}
bst* insert(bst *root,string data)
{
    if(root==NULL)
    {
   	 	root=newnode(data);
    }
    if(data<root->data)
    root->leftchild=insert(root->leftchild,data);
    else if(data>root->data)
    root->rightchild=insert(root->rightchild,data);
    return root;
}

void inorder(bst *root){
if(root==NULL)return;

inorder(root->leftchild);
cout<<root->data<<"\n";
inorder(root->rightchild);

}

int main()
{
	bst* rootptr;
	rootptr=NULL;
	string n;
	cout<<"Enter words for tree (type END to exit input):\n";
	getline(cin, n);
	rootptr=insert(rootptr,n);
	bst *temp=rootptr;

	while(1)
	{
	    getline(cin, n);
	    if(n=="END")
	    break;

	    temp=insert(temp,n);
	}
    cout<<endl;

    inorder(temp);
     return 0;
}
