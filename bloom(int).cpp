/*
Name : Uddhav Rajendra Patil
Roll : 236
Batch : E2
PRN : 0220200126
Problem Statement :implement Blooms  Filter
*/


#include <bits/stdc++.h>
#define ll long long
using namespace std;
 

int h1(int s, int arrSize)
{
    ll int hash = 0;
   
        hash = (hash + ((int)s));
        hash = hash % arrSize;
    
    return hash;
}
 

int h2(int s, int arrSize)
{
    ll int hash = 1;
   
        hash = hash + pow(10, s) * s;
        hash = hash % arrSize;
   
    return hash % arrSize;
}
 

int h3(int s, int arrSize)
{
    ll int hash = 33;
    
        hash = (hash * 3 + s) % arrSize;
    
    return hash % arrSize;
}
 

int h4(int s, int arrSize)
{
    ll int hash = 100;
    int p = 7;
   
        hash += hash * 7 + s * pow(p, s);
        hash = hash % arrSize;
    
    return hash;
}
 
 
// loookup operation
bool lookup(bool* bitarray, int arrSize, int s)
{
    int a = h1(s, arrSize);
    int b = h2(s, arrSize);
    int c = h3(s, arrSize);
    int d = h4(s, arrSize);
 
    if (bitarray[a] && bitarray[b] && bitarray[c] && bitarray[d])
        return true;
    else
        return false;
}
 
// insert operation
void insert(bool* bitarray, int arrSize, int s)
{
    // check if the element in already present or not
    if (lookup(bitarray, arrSize, s))
        cout << s << " is Probably already present" << endl;
    else
    {
        int a = h1(s, arrSize);
        int b = h2(s, arrSize);
        int c = h3(s, arrSize);
        int d = h4(s, arrSize);
 
        bitarray[a] = true;
        bitarray[b] = true;
        bitarray[c]= true;
        bitarray[d] = true;
 
        cout << s << " inserted" << endl;
    }
}
 
// Driver Code
int main()
{
	int n;
    bool bitarray[100] = { false };
    int arrSize = 100;
    cout<<"How many elements do you want to enter?:";
    cin>>n;
    int sarray[n];
    cout<<"Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin>>sarray[i];
    }
    cout<<endl<<endl;
    for (int i = 0; i < n; i++) {
        insert(bitarray, arrSize, sarray[i]);
    }
    return 0;
}


	
