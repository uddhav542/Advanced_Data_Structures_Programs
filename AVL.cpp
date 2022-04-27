#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
// An AVL tree node
class node
{
    public:
    int data;
    node *left;
    node *right;
    int height;
};
class AVL
{
	public: 
	node * root;
	AVL()
	{
		this->root=NULL;
	}
	int callheight(node *t);
	int bf(node *temp);
	node *llrotation(node *temp);
	node *rrrotation(node *temp);
	node *lrrotation(node *temp);
	node *rlrotation(node *temp);
	node *insert(node *r,int data);
	void inorder(node *root);
	void preorder(node *root);
	void postorder(node *root);
};

int AVL::callheight(node *t)
{
	if(t->left && t->right)
	{
		if(t->left->height < t->right->height)
		{
			return t->right->height + 1;
		}
		else
		{
			return t->left->height + 1;
		}
	}
	else if(t->left && t->right==NULL)
	{
		return t->left->height + 1;
	}
	else if(t->left==NULL && t->right)
	{
		return t->right->height + 1;
	}
	return 0;
}

int AVL::bf(node *temp)
{
	if(temp->left && temp->right)
	{
		return temp->left->height - temp->right->height;
	}
	else if(temp->left && temp->right==NULL)
	{
		return temp->left->height;
	}
	else if(temp->left==NULL && temp->right)
	{
		return temp->right->height;
	}
}

node * AVL::llrotation(node *root)
{
	cout<<"LL Rotation\n";
	node *p=root;
	node *p1=root->left;
	p->left=p1->right;
	p1->right=p;
	return p1;
}

node * AVL::rrrotation(node *root)
{
	cout<<"RR Rotation\n";
	node *p=root;
	node *p1=root->right;
	p->right=p1->left;
	p1->left=p;
	return p1;
}

node * AVL::lrrotation(node *root)
{
	cout<<"LR Rotation\n";
	node * p=root;
	node * p1=root->left;
	node * p2=root->left->right;
	
	p1->right=p2->left;
	p->left=p2->right;
	p2->left=p1;
	p2->right=p;
	return(p2);
}
node * AVL::rlrotation(node *root)
{
	cout<<"RL Rotation\n";
	node * p=root;
	node * p1=root->right;
	node * p2=p1->left;
	
	p1->left=p2->right;
	p->right=p2->left;
	p2->left=p;
	p2->right=p1;
	return(p2);
}
node *AVL::insert(node *r,int data)
{
	if(r==NULL)
	{
		node *temp=new node();
		temp->data=data;
		r=temp;
		r->left=r->right=NULL;
		r->height=1;
	//	return r;
	}
	else
	{
		if(data<r->data)
		r->left=insert(r->left,data);
		else
		r->right=insert(r->right,data);
	}
	r->height=callheight(r);
	if(bf(r)==2 && bf(r->left)==1)
	{
		r=llrotation(r);
	}
	else if(bf(r)==-2 && bf(r->right)==-1)
	{
		r=rrrotation(r);
	}
	else if(bf(r)==-2 && bf(r->right)==1)
	{
		r=rlrotation(r);
	}
	else if(bf(r)==2 && bf(r->left)==-1)
	{
		r=lrrotation(r);
	}
	return r;
}

void AVL::inorder(node *root)
{
	if (root != NULL)
	{
		inorder(root->left); //left child
    	cout<<root->data<<" ";	//node
    	inorder(root->right); //right child
	} 	
}

void AVL::preorder(node *root)
{
	if (root != NULL)
	{
		cout<<root->data<<" ";	//node
    	preorder(root->left); //left child
    	preorder(root->right); //right child
	}	
}

void AVL::postorder(node *root)
{
	if (root != NULL)
	{
		postorder(root->left); //left child
    	postorder(root->right); //right child
    	cout<<root->data<<" ";	//node
	}		
}

int main()
{
	AVL l;
	node *root=NULL;
	int n,x;
	cout<<"enter no of elements:";
	cin>>n;
	cout<<"Enter "<<n<<" elements:\n";
	for(int i=0;i<n;i++)
	{
		cin>>x;
		root=l.insert(root,x);
	}
	cout<<"\nInoredr:";
	l.inorder(root);
	cout<<"\nPostorder:";
	l.postorder(root);
	cout<<"\nPreorder:";
	l.preorder(root);
	return 0;
}
