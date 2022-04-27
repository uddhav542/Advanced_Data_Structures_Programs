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
		void inorder(node *root);
		void preorder(node *root);
		void postorder(node *root);
		void search(node *root);
		//void del(node *root);
};

node *BST::create()
{
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
			if(temp->data < root->data) //less data insert at left side
			{
				
				if(root->left==NULL) //check already present or not
				{
					root->left=temp;
					break;
				}
				else
				{
					root=root->left;	
				}	
			}
			else if(temp->data > root->data)//greater data at right side
			{
				if(root->right==NULL) //check already present or not
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
		cout<<"Do you want to add more?\n";
	}while(getch()!='n');
	return(mainroot);
}

void BST::inorder(node *root)
{
	if (root != NULL)
	{
		inorder(root->left); //left child
    	cout<<root->data<<" ";	//node
    	inorder(root->right); //right child
	} 	
}

void BST::preorder(node *root)
{
	if (root != NULL)
	{
		cout<<root->data<<" ";	//node
    	preorder(root->left); //left child
    	preorder(root->right); //right child
	}	
}

void BST::postorder(node *root)
{
	if (root != NULL)
	{
		postorder(root->left); //left child
    	postorder(root->right); //right child
    	cout<<root->data<<" ";	//node
	}		
}

void BST::search(node *root)
{
	int skey;
	cout<<"Enter key for search:";
	cin>>skey;
	node* temp=root;
	int t=0;
	while(1)
	{
		if(temp->data==skey)
		{
			t=1;
			cout<<"Node Found.";
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
	if(t==0)
	{
		cout<<"Node Not found.";
	}
}

/*void BST::del(node *root)
{
	node* temp=root;
	while(1)
	{
		if(temp->left==NULL && temp->right==NULL)
		{
			delete(temp);
			break;
		}
		else if(temp->left!=NULL)
		{
			temp=temp->left;
		}
		else if(temp->right!=NULL)
		{
			temp=temp->right;
		}
	}
	
}*/
int main()
{
	BST b;
	int ch;
	node *root1;
	root1=b.create();
	while(1)
	{
		cout<<"\nChoose. \n1.PreOrder\n2.InOrder\n3.PostOrder\n4.search\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
			b.preorder(root1);
			break;
			case 2:
			b.inorder(root1);
			break;
			case 3:
			b.postorder(root1);
			break;
			case 4:
			b.search(root1);
			//case 5:
			//b.del(root1);
			//break;
		}
	}	
	return 0;
}
