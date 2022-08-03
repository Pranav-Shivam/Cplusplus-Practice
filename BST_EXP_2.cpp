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

void printPostorder(struct Node* node)
{
	if (node == NULL)
		return;	
	printPostorder(node->left);
	printPostorder(node->right);
	cout << node->data << " ";
}

void printInorder(struct Node* node)
{
	if (node == NULL)
		return;

	printInorder(node->left);

	cout << node->data << " ";

	printInorder(node->right);
}

void printPreorder(struct Node* node)
{
	if (node == NULL)
		return;

	cout << node->data << " ";
	printPreorder(node->left);
	printPreorder(node->right);
}

int main()
{
    cout<<"Hello"<<endl;
    int height;
    cout<<"Enter the height of the tree :- ";
    cin>>height;
    
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
    cout << "\nPreorder traversal of binary tree is \n";
	printPreorder(root);

	cout << "\nInorder traversal of binary tree is \n";
	printInorder(root);

	cout << "\nPostorder traversal of binary tree is \n";
	printPostorder(root);
    return 0;
}