/*
Name :    Uddhav patil
Roll no:  236
Batch:    E2
PRN no:   0220200126
Exam no:  S204153
problem statement: Write a program in C++ to implement binary search tree with the following options: 
1. Insert node 2. Recursive Traversals (inorder, preorder, postorder) 3. Search
*/


#include<iostream>
#include<conio.h>
using namespace std;
class node
{
	public:
	int data;
	node *left;
	node *right;
};
class BST
{
	public:
		node *mainroot;
		BST()
		{
			mainroot=NULL;
		}
		node *create();
		void search(node *root);
		void rec_inorder(node *root);
		void rec_preorder(node *root);
		void rec_postorder(node *root);
};
node *BST::create()
{
	char c;
	node *root;
	do
	{
		node *temp=new node();
		cout<<"Enter data:";
		cin>>temp->data;
		temp->left=NULL;
		temp->right=NULL;	
		if(mainroot==NULL)
		{
			mainroot=temp;
		}
		else
		{
			root=mainroot;
			while(1)
			{
				if(temp->data < root->data)    //less data insert at left side
				{	
					if(root->left==NULL)      //check already present or not
					{
						root->left=temp;
						break;
					}
					else
					{
						root=root->left;	
					}	
				}
				else if(temp->data > root->data)  //greater data at right side
				{
					if(root->right==NULL)      //check already present or not
					{
						root->right=temp;
						break;
					}
					else
					{
						root=root->right;	
					}	
				}
			}
		}
		cout<<"Do you want to add more?(y/n)\n";
		cin>>c;
	}while(c=='y');
	return(mainroot);
}
void BST::search(node *root)
{
	int skey;
	cout<<"\nEnter key for search:";
	cin>>skey;
	node* temp=root;
	int flag=0;
	while(1)
	{
		if(temp->data==skey)
		{
			flag=1;
			cout<<"Node Found:"<<temp->data;
			break;
		}
		else if(skey < temp->data)
		{
			temp=temp->left;
		}
		else
		{
			temp=temp->right;
		}
		if(temp==NULL)
		{
			break;
		}
	}
	if(flag==0)
	{
		cout<<"Node Not found.";
	}
}
void BST::rec_inorder(node *root)
{
	if (root != NULL)
	{
		rec_inorder(root->left);     //left child
    	cout<<root->data<<" ";	    //node
    	rec_inorder(root->right);    //right child
	} 	
}

void BST::rec_preorder(node *root)
{
	if (root != NULL)
	{
		cout<<root->data<<" ";	    //node
    	rec_preorder(root->left);     //left child
    	rec_preorder(root->right);     //right child
	}	
}

void BST::rec_postorder(node *root)
{
	if (root != NULL)
	{
		rec_postorder(root->left);   //left child
    	rec_postorder(root->right);  //right child
    	cout<<root->data<<" ";	    //node
	}		
}
int main()
{
	BST b;
	int ch;int i=0;
	cout<<"-------------- BST------------\n";
	node *root1;
	
	while(1)
	{
		cout<<"\nChoose.\n1.create\n2.search\n3.Preorder Traversal\n4.Inorder Traversal\n5.Postorder Traversal\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
                cout<<"\nCreating\n";
                root1=b.create();
                break;
			case 2:
				b.search(root1);
				break;
			case 3:
				cout<<"\nRecursive preorder\n";
				b.rec_preorder(root1);
				break;
			case 4:
				cout<<"\nRecursive Inorder\n";
				b.rec_inorder(root1);
				break;
			case 5:
				cout<<"\nRecursive Postorder\n";
				b.rec_postorder(root1);
				break;
		}
	}	
	return 0;
}


/*
output:
-------------- BST------------

Choose.
1.create
2.search
3.Preorder Traversal
4.Inorder Traversal
5.Postorder Traversal
1

Creating
Enter data:56
Do you want to add more?(y/n)
y
Enter data:34
Do you want to add more?(y/n)
y
Enter data:87
Do you want to add more?(y/n)
y
Enter data:67
Do you want to add more?(y/n)
y
Enter data:22
Do you want to add more?(y/n)
n

Choose.
1.create
2.search
3.Preorder Traversal
4.Inorder Traversal
5.Postorder Traversal
2

Enter key for search:87
Node Found:87
Choose.
1.create
2.search
3.Preorder Traversal
4.Inorder Traversal
5.Postorder Traversal
3

Recursive preorder
56 34 22 87 67
Choose.
1.create
2.search
3.Preorder Traversal
4.Inorder Traversal
5.Postorder Traversal
4

Recursive Inorder
22 34 56 67 87
Choose.
1.create
2.search
3.Preorder Traversal
4.Inorder Traversal
5.Postorder Traversal
5

Recursive Postorder
22 34 67 87 56
*/
