#include <iostream>
using namespace std;
class Node {
	public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

void printPostorder(Node *temp)
{
    if (temp == NULL)
        return;
    printPostorder(temp->left);
    printPostorder(temp->right);
    cout << temp->data << " ";
}

void printInorder(Node* temp)
{
    if (temp == NULL)
        return;
    printInorder(temp->left);
    cout << temp->data << " ";
    printInorder(temp->right);
}

void printPreorder(Node* temp)
{
    if (temp == NULL)
        return;
    cout << temp->data << " ";
    printPreorder(temp->left);
    printPreorder(temp->right);
}
 
int main()
{
    Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
 
    cout << "\nPreorder traversal of binary tree is \n";
    printPreorder(root);
 
    cout << "\nInorder traversal of binary tree is \n";
    printInorder(root);
 
    cout << "\nPostorder traversal of binary tree is \n";
    printPostorder(root);
 
    return 0;
}
