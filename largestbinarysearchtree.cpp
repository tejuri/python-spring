#include<iostream>
#include<climits>
using namespace std;

struct node
{
    int data;
    node *left,*right;
    node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

struct info()
{
    int size;
    int max;
    int min;
    int ans; 
    bool isbst;
}

info largestbstinbt(node *root)
{
    if(root==NULL)
    {
        return{0,INT_MIN,INT_MAX,0,true};
    }
    if(root->left==NULL && root->right==NULL)
    {
        return{1,root->data,root->data,1,true};
    }
    info leftinfo=largestbstinbt(root->left);
    infor rightinfo=largestbstinbt(root->right);
    info curr;
    curr.size=(1+leftinfo.size+rightinfo.size);

    if(leftinfo.isbst && rightinfo.isbst && leftinfo.max<root->data &&rightinfo.min>root->data)
    {
        curr.min=min(leftinfo.min,min(rightinfo.min,root->data));
        curr.max=max(rightinfo.max,max(leftinfo.max,root->data));

        curr.ans=curr.size;
        curr.isbst=true;

        return curr;
    }

    
}