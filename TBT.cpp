#include<bits/stdc++.h>
using namespace std;

class Node
{
public :
    int data;
    Node * left;
    Node * right;
    int lth;
    int rth;
};

class TBT
{
    public :
    Node * mainroot;
    Node * dummy;
    TBT()
    {
       mainroot=NULL;
       dummy==NULL;
    }

    Node * create()
    {
        int n,i;
        cout<<"How many nodes do you want to enter:";
        cin>>n;
        for(i=0;i<n;i++)
        {
            Node * temp;
            temp=new Node;
            cout<<"Enter data=";
            cin>>temp->data;
            temp->left=NULL;
            temp->right=NULL;
            temp->rth=1;
            temp->lth=1;

            if(mainroot==NULL)
            {
                dummy=new Node;
                dummy->data=9999;
                dummy->left=mainroot;
                dummy->right=dummy;
                dummy->lth=0;
                dummy->rth=1;

                mainroot=temp;
                mainroot->left=dummy;
                mainroot->right=dummy;
            }
            else
            {
                Node *root=mainroot;
                while(1)
                {
                    if(temp->data<root->data)//left child
                    {
                        if(root->lth==1)      //no left child
                        {
                            temp->left=root->left;
                            root->left=temp;
                            root->lth=0;
                            temp->right=root;
                            break;
                        }
                        else
                        {
                            root=root->left;
                        }
                    }
                    else				//right child
                    {
                        if(root->rth==1)//no right child
                        {
                            temp->right=root->right;
                            root->right=temp;
                            root->rth=0;
                            temp->left=root;
                            break;
                        }
                        else
                        {
                            root=root->right;
                        }
                    }
                }
            }
        }
        return mainroot;
    }

    void rec_Inorder(Node *mainroot)//recursive
    {
        Node *root=mainroot;
        if(root!=dummy)
        {
            if(root->lth==0)//left child is present
                rec_Inorder(root->left);//first traverse left child
            cout<<root->data<<"\t"; // visit node
            if(root->rth==0)
                rec_Inorder(root->right);//traverse right child
        }
    }
    void rec_Preorder(Node *mainroot)
    {
        Node *root=mainroot;
        if(root!=dummy)
        {
            cout<<root->data<<"\t"; // visit node
            if(root->lth==0)
                rec_Preorder(root->left);//first traverse left child
            if(root->rth==0)
                rec_Preorder(root->right);//traverse right child
        }
    }

    void rec_postorder(Node *mainroot)//recursive
    {
         Node *root=mainroot;
        if(root!=dummy)
        {
            if(root->lth==0)
                rec_postorder(root->left);//first traverse left child
            if(root->rth==0)
                rec_postorder(root->right);//traverse right child
            cout<<mainroot->data<<"\t"; // visit node
        }
    }
    Node *find_inorder_successor(Node *root)
    {
        if(root->rth == 1)       //if right thread is present
            root = root->right;
        else
        {
            root = root->right;
            while(root->lth == 0)
                root = root->left;
        }
        return root;
    }
    void itr_Inorder(Node *mainroot)
    {
        Node *root=mainroot->left;
        while(root->lth==0)    //if left chid is present000000000000
            root=root->left;
        while(root!=dummy)
        {
            cout<<root->data<<"\t";
            root=find_inorder_successor(root);
        }
    }

    Node *find_preorder_successor(Node *root)
    {
        if(root->lth == 0)
            root = root->left;
        else if(root->rth == 0)
            root = root->right;
        else
        {
            while(root->rth == 1)
            {
                root = root->right;
                if(root == root)
                break;
            }
            root = root->right;
        }
        return root;
    }

    void itr_Preorder(Node *mainroot)
    {
        Node *root = mainroot;
        cout<<root->data<<"\t";
        while(1)
        {
            root = find_preorder_successor(root);
            if(root==dummy)
                break;
            cout<<root->data<<"\t";
        }
    }
    
    void search(Node *mainroot,int key)
    {
        Node *temp = new Node;
        temp = mainroot;
        // Run the loop untill temp points to a NULL pointer.
        while(temp != dummy)
        {

            if(temp->data == key)
            {
                cout<<"Data found : "<<temp->data;
                return;
            }
            // Shift pointer to left child.
            else if(temp->data > key)
                temp = temp->left;
            // Shift pointer to right child.
            else
                temp = temp->right;
        }
        cout<<"\n Data not found";
        return;
    }

  
};
int main()
{
    int ch,key;
    TBT tbt;
    Node *mainroot;
    do
    {
        
        cout<<"\n1.Create Node\n2.Recursive Inorder\n3.Recursive Preorder\n4.Recursive Postorder\n";
        cout<<"5.Iterative Inorder\n6.Iterative Preorder\n7.Search";
        cout<<"\nEnter your choice:";
        cin>>ch;

        switch(ch)
        {
            case 1:
                cout<<"\nCreating\n";
                mainroot=tbt.create();
                break;

            case 2:
                cout<<"\nRecursive Inorder\n";
                tbt.rec_Inorder(mainroot);
                cout<<"\n";
                break;

            case 3:
                cout<<"\nRecursive preorder\n";
                tbt.rec_Preorder(mainroot);
                cout<<"\n";
                break;
            case 4:
                cout<<"\nRecursive postorder\n";
                tbt.rec_postorder(mainroot);
                cout<<"\n";
                break;
            case 5:
                cout<<"\nIterative Inorder\n";
                tbt.itr_Inorder(mainroot);
                cout<<"\n";
                break;

            case 6:
                cout<<"\nIterative Preorder\n";
                tbt.itr_Preorder(mainroot);
                cout<<"\n";
                break;

 			case 7:
                cout<<"enter element to search";
                cin>>key;
                tbt.search(mainroot,key);
                cout<<"\n";
                break;
            default:
                cout<<"\nEnter valid choice\n";
        }
    }while(ch!=0);
    return 0;
}
