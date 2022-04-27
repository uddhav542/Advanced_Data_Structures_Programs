//Middle element of link list
/*#include<iostream>>
#include <cstring>
#include<stdio.h>
#include<conio.h>
using namespace std; 

class Node
{
	public:
		int num;
		Node *next;
		Node()
		{
			next=NULL;	
		}	
};
class linked_list
{

	public:
		Node *start;
		int count=0;
		linked_list()
		{
			start=NULL;
		}
	
		void create1()
		{
			do
			{
				
				Node *temp=new Node();
				Node *p;
				cout<<"\nEnter numbers:";
				cin>>temp->num;
				if(start==NULL)
				{
					start=temp;
				}
				else
				{
					p=start;
					while(p->next!=NULL)
					{
						p=p->next;
					}
					p->next=temp;
				}
				cout<<"do you want to add more? y/n";
				count++;
		    }while(getch()!='n');
		}
		
		void display()
		{
			cout<<"\nTotal:"<<count;
			Node *t;
			if(start==NULL)
			{
				printf("List is empty.");
			}
			t=start;
			cout<<endl;
			while(t->next!=NULL)
			{
				cout<<t->num<<" ";
				t=t->next;
			}
			cout<<t->num<<" ";
			return;
		}
	    void middle()
	    {
	    	Node *t=start;
	    	cout<<"\nMiddle of list:";
	    	for(int i=0;i<count/2;i++)
	    	{
	    		t=t->next;
			}
			cout<<t->num<<" ";
	    }
		
		
};
int main()
{
	linked_list l;

	l.create1();
	
	l.display();
	l.middle();
	
	return 0;
}
*/

//second largest element in array
/*
#include<iostream>
#include <cstring>
#include<stdio.h>
#include<conio.h>
using namespace std;
second_large(int a[],int n)
{
	int temp;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	cout<<a[n-2];
}
int main()
{
	int n;
	cout<<"Enter Total No:";
	cin>>n;
	cout<<"Enter elements:\n";
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<"\nSecond Largest:";
	second_large(a,n);
} 
*/


