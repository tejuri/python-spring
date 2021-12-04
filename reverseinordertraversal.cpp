 #include<iostream>
 using namespace std;
 
 void reverseinordertraversal(btree *root)
 {
     if (root == NULL)
        return;


    reverseinordertraversal(root->right);


    cout<<root->data<<" ";

    reverseinordertraversal(root->left);
 }
 

 int main()
 {
     cout<<"0";
     return 0;
 }