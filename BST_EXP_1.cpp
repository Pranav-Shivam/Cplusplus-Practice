#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *left,*right;
    Node(int value)
    {
        data=value;
        left =NULL;
        right= NULL;
    }
};
//Inserting node 
Node* insertBST(Node *root,int val)
{
    if(root==NULL)
    {
        return new Node(val);
    }
    if(val< root->data)
    {
        root->left= insertBST(root->left,val);
    }
    else
    {
        root->right=insertBST(root->right,val);
    }
    return root;
}
//Searching a node
Node* searchBST(Node* root, int key)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(root->data==key)
    {
        return root;
    }
    if(root->data > key)
    {
        return searchBST(root->left,key);
    }
    //data < key
    return searchBST(root->right,key);
}
//Deleting a node
Node* inorderSucc(Node* root)
{
    Node* curr=root;
    while(curr && curr->left!= NULL)
    {
        curr=curr->right;
    }
    return curr;
}
Node* deleteBST(Node* root,int key)
{
     if(key < root->data)
     {
         root->left=deleteBST(root->left,key);
     }
     else if(key > root->data)
     {
         root->right=deleteBST(root->right,key);
     }
     else
     {
         if(root->left==NULL)
         {
             Node* temp=root->right;
             free(root);
             return temp;
         }
         else if(root->right==NULL)
         {
             Node* temp=root->left;
             free(root);
             return temp; 
         }
         Node* temp= inorderSucc(root->right);
         root->data=temp->data;
         root->right=deleteBST(root->right,temp->data);
     }
     return root;
}
void inorder(Node* root)
{
    if(root== NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<"\t";
    inorder(root->right);
}

int main()
{
    cout<<"Hello"<<endl;
    int height;
    int s_key;    //search key
    int d_key;   //delete key
    cout<<"Enter the height of the tree :- ";
    cin>>height;
    cout<<"Enter the searching key of the tree :- ";
    cin>>s_key;
    cout<<"Enter the deleting key of the tree :- ";
    cin>>d_key;
    int arr[height];
    cout<<"\nEnter the elements \n";
    //enter the elements of BST tree
    for(int i=0;i<height;i++)
    {
        cout<<"Enter new element :- ";
        cin>>arr[i];
    }
    Node* root=NULL;
    root=insertBST(root,arr[0]);
    for(int i=1;i<height;i++)
    {
        insertBST(root,arr[i]);
    }
    cout<<"\n The BST \n";
    cout<<"\n";
    //Searching 
    if(searchBST(root,s_key)==NULL)
    {
        cout<<"\n"<<s_key<<" not exist s\n"<<endl;
    }
    else
    {
        cout<<"\n"<<s_key<<" exists \n";
    }
    inorder(root);
    cout<<endl;
    root=deleteBST(root,d_key);
    cout<<"\n The BST after deleting \n";
    cout<<"\n";
    inorder(root);
    cout<<endl;
    return 0;
}