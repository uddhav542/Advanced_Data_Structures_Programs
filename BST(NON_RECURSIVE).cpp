/*
Name :    Uddhav patil
Roll no:  236
Batch:    E2
PRN no:   0220200126
Exam no:  S204153
Title:   Write a program in C++ to implement the following operations on Binary Search Tree:
	 create, recur- sive inorder traversal, recursive preorder traversal, 
	recursive postorder traversal, non recursive inorder traversal, 
	non recursive preorder traversal, non recursive postorder traversal, 
	delete a node, insert a node, level wise printing.

*/
#include<iostream>
#include<bits/stdc++.h>
#include<conio.h>
#include<stack>
#include<queue>
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
		void inorder(node *root);
		void preorder(node *root);
		void postorder(node *root);
		void nonrec_inorder(node *root);
		void nonrec_preorder(node *root);
		void nonrec_postorder(node *root);
		void level_wise_non_rec(node * root);
		void level_wise_rec(node * root);
		void printNodesAtLevel(node * root,int currentLevel,int Level);
		int getHeight(node * root);
		node * deleteNode(node * root,int key);
		node * minValueNode(node *node);
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
		cout<<"Do you want to add more?(y/n)\n";
	}while(getch()!='n');
	return(mainroot);
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
void BST::nonrec_preorder(node *root)
{
	/*1) Create an empty stack nodeStack and push root node to stack. 
	  2) Do the following while nodeStack is not empty. 
        ….a) Pop an item from the stack and print it. 
        ….b) Push right child of a popped item to stack 
        ….c) Push left child of a popped item to stack
       The right child is pushed before the left child to make sure that the left subtree is processed first.
	*/
	stack<node *>s;
	node *curr=root;
	s.push(curr);
	while(s.empty()==false)
	{
		curr=s.top();
		s.pop();
		cout<<curr->data<<" ";
		if(curr->right!=NULL)
			s.push(curr->right);
		if(curr->left!=NULL)
			s.push(curr->left);
	}
}
void BST::nonrec_inorder(node *root)  
{
	/*
	1) Create an empty stack S.
	2) Initialize current node as root
	3) Push the current node to S and set current = current->left until current is NULL
	4) If current is NULL and stack is not empty then 
     a) Pop the top item from stack.
     b) Print the popped item, set current = popped_item->right 
     c) Go to step 3.
	5) If current is NULL and stack is empty then we are done.*/
	stack<node *>s;
	node *curr=root;
	while(curr!=NULL||s.empty()==false)
	{
		while(curr!=NULL)
		{
			s.push(curr);
			curr=curr->left;
		}
		curr=s.top();
		s.pop();
		cout<<curr->data<<" ";
		curr=curr->right;
	}
}

void BST::nonrec_postorder(node *root)
{
	/*  1. Push root to first stack.
		2. Loop while first stack is not empty
   			2.1 Pop a node from first stack and push it to second stack
   			2.2 Push left and right children of the popped node to first stack
		3. Print contents of second stack*/
	stack<node *>s1,s2;
	node *curr=root;
	s1.push(curr);
	while (s1.empty()==false) 
	{
		
        curr = s1.top();
        s1.pop();
        s2.push(curr);
  
        if (curr->left!=NULL)
            s1.push(curr->left);
        if (curr->right!=NULL)
            s1.push(curr->right);
    }
    while (s2.empty()==false) 
	{
        curr = s2.top();
        s2.pop();
        cout << curr->data << " ";
    }
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
void BST::level_wise_non_rec(node * root)
{
	queue <node *>q;
	node *curr;
	q.push(root);
	while(q.empty()==false)
	{
		int nodecount=q.size();
		cout<<"\n";
	
	while(nodecount>0)
	{
		curr=q.front();
		cout<<curr->data<<" ";
		q.pop();
		if(curr==NULL)
		{
			q.push(NULL);
			cout<<"\n";
		}
		else
		{
			if(curr->left!=NULL)
			{
				q.push(curr->left);
			}
			if(curr->right!=NULL)
			{
				q.push(curr->right);
			}
			nodecount--;
		}	
	}
}
}
void BST::printNodesAtLevel(node * root,int currentLevel,int Level)
{
	if(root==NULL)
	{
		return;
	}	
	if(currentLevel==Level)
	{
		cout<<root->data<<" ";
		return;
	}
	printNodesAtLevel(root->left, currentLevel+1, Level);
	printNodesAtLevel(root->right, currentLevel+1, Level);

}
int BST::getHeight( node *root)
{
    int leftHeight, rightHeight;
    if(root == NULL)
        return 0;
    leftHeight = getHeight(root->left);
    rightHeight = getHeight(root->right);
    
	if(leftHeight>=rightHeight)
		return leftHeight+1;
	else
		return rightHeight+1;
    
}
void BST::level_wise_rec(node* root)
{
    int i, height = getHeight(root);
    /* Iterate from level 0 to height-1 and 
 print one level at a time */
    for(i = 0; i < height; i++){
     printNodesAtLevel(root, 0, i);
     printf("\n");
    }
}
node * BST::deleteNode(node *root, int key)
{
    // base case
    if (root == NULL)        
		return root;
     // If the key to be deleted is smaller than the root’s key, then it lies in left subtree
    if (key < root->data)
        root->left = deleteNode(root->left, key);
     // If the key to be deleted is greater than the root'skey, then it lies in right subtree
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    // if key is same as root's key, then This is the node to be deleted
    else {
        // node with only one child or no child
        if (root->left == NULL) 
		{
            node* temp = root->right;            
			free(root);            
			return temp;
        }
        else if (root->right == NULL) 
		{
            node* temp = root->left;             
			free(root);            
			return temp;
        }
         // node with two children: Get the inorder successor (smallest in the right subtree)
        node* temp = minValueNode(root->right);
         // Copy the inorder successor's content to this node
        root->data = temp->data;
         // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;	
}

node * current; 
node *BST:: minValueNode(node *node)
{

	current=node;
	while(current&&current->left!=NULL)
	{
		current=current->left;
	}
	return current;
}

int main()
{
	BST b;
	int ch;int i=0;
	node *root1;
	root1=b.create();
	while(1)
	{
		cout<<"\nChoose. \n1.Non-Recursive PreOrder\n2.Non-Recursive InOrder\n3.Non-Recursive PostOrder\n4.Non Recursive Level wise \n5.Level wise\n6.delete\n7.search\n";
		cout<<"8.preorder\n9.inorder\n10.postorder\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
			b.nonrec_preorder(root1);
			break;
			case 2:
			b.nonrec_inorder(root1);
			break;
			case 3:
			b.nonrec_postorder(root1);
			break;
			case 4:
			b.level_wise_non_rec(root1);
			break;
			case 5:
			b.level_wise_rec(root1);
			break;
			case 6:int k;
				cout<<"key:";
				cin>>k;
			b.deleteNode(root1,k);
			break;
			case 7:
			b.search(root1);
			break;
			case 8:
			b.preorder(root1);
			break;
			case 9:
			b.inorder(root1);
			break;
			case 10:
			b.postorder(root1);
			break;
		}
	}	
	return 0;
}



/*
output:

Enter data:56
Do you want to add more?(y/n)
Enter data:34
Do you want to add more?(y/n)
Enter data:87
Do you want to add more?(y/n)

Choose.
1.Non-Recursive PreOrder
2.Non-Recursive InOrder
3.Non-Recursive PostOrder
4.Non Recursive Level wise
5.Level wise
6.delete
7.search
8.preorder
9.inorder
10.postorder
1
56 34 87

Choose.
1.Non-Recursive PreOrder
2.Non-Recursive InOrder
3.Non-Recursive PostOrder
4.Non Recursive Level wise
5.Level wise
6.delete
7.search
8.preorder
9.inorder
10.postorder
2
34 56 87

Choose.
1.Non-Recursive PreOrder
2.Non-Recursive InOrder
3.Non-Recursive PostOrder
4.Non Recursive Level wise
5.Level wise
6.delete
7.search
8.preorder
9.inorder
10.postorder
3
34 87 56

Choose.
1.Non-Recursive PreOrder
2.Non-Recursive InOrder
3.Non-Recursive PostOrder
4.Non Recursive Level wise
5.Level wise
6.delete
7.search
8.preorder
9.inorder
10.postorder
4

56
34 87

Choose.
1.Non-Recursive PreOrder
2.Non-Recursive InOrder
3.Non-Recursive PostOrder
4.Non Recursive Level wise
5.Level wise
6.delete
7.search
8.preorder
9.inorder
10.postorder
6
key:34

Choose.
1.Non-Recursive PreOrder
2.Non-Recursive InOrder
3.Non-Recursive PostOrder
4.Non Recursive Level wise
5.Level wise
6.delete
7.search
8.preorder
9.inorder
10.postorder
9
56 87

Choose.
1.Non-Recursive PreOrder
2.Non-Recursive InOrder
3.Non-Recursive PostOrder
4.Non Recursive Level wise
5.Level wise
6.delete
7.search
8.preorder
9.inorder
10.postorder
7
Enter key for search:56
Node Found.


*/
