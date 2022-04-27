/*
Name : Uddhav Rajendra Patil
Roll : 236
Batch : E2
PRN : 0220200126
Problem Statement : cuckoo filter
*/


#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define MAXN 9
#define ver 2
 
int hashtable[ver][MAXN];
int pos[ver];
 

void initTable()
{
    for (int j=0; j<MAXN; j++)
    {
    	for (int i=0; i<ver; i++)
            hashtable[i][j] = INT_MIN;        //initialiase dummy value
	}       
}

int hash(int function, int key)
{
    switch (function)
    {
        case 1: return key%MAXN;
        case 2: return (key/MAXN)%MAXN;
    }
}
 

void place(int key, int tableID, int cnt, int n)
{
    if (cnt==n)
    {
        cout<<"unpositioned\n"<< key;
        cout<<"Cycle present. REHASH.\n";
        return;
    }
 
    
    for (int i=0; i<ver; i++)
    {
        pos[i] = hash(i+1, key);
        if (hashtable[i][pos[i]] == key)
           return;
    }
 
    /* check if another key is already present at the
       position for the new key in the table
     * If YES: place the new key in its position
     * and place the older key in an alternate position
       for it in the next table */
    if (hashtable[tableID][pos[tableID]]!=INT_MIN)
    {
        int dis = hashtable[tableID][pos[tableID]];     //copy existing element to dis
        hashtable[tableID][pos[tableID]] = key;      //place element at proper place
        place(dis, (tableID+1)%ver, cnt+1, n);      //place in second table
    }
    else 
       hashtable[tableID][pos[tableID]] = key;    //else: place the new key in its position
}
 

void printTable()
{
    cout<<"Final hash tables:\n";
 
    for (int i=0; i<ver; i++, cout<<"\n")
    {
    	for (int j=0; j<MAXN; j++)
    	{
                if(hashtable[i][j]==INT_MIN)
               		cout<<"N ";
				else
					cout<<hashtable[i][j];
		}     
	}
}
 

void cuckoo(int keys[], int n)
{
    initTable();
    int cnt=0;
    for (int i=0; i<n; i++)
        place(keys[i], 0, cnt, n);
 
    printTable();
}
 

int main()
{
	int n;
    cout<<"Enter total no of  elements:";
    cin>>n;
    int keys_1[n] ;
    cout<<"Enter elements:";
 	for(int i=0;i<n;i++)
 	{
 		cin>>keys_1[i];	
	}
	cout<<"\nMod factor:"<<MAXN<<endl;
    cuckoo(keys_1, n);
    return 0;
}

/*
Enter total no of  elements:6
Enter elements:32 99 76 33 12 85

Mod factor:9
Final hash tables:
99 N N 12 85 32 33 N N
N N N N N N N N 76

*/
