/*
Name : Uddhav Rajendra Patil
Roll : 236
Batch : E2
PRN : 0220200126
Problem Statement : Linear probing with and without replacement
*/


#include<iostream>
using namespace std;

#define MAX 10
void HashingReplace (int A[MAX], int n, int key);	//With Replacement
void HashingNoReplace (int A[MAX], int n, int key);	//Without Replacement

int main(){		// Main method

    int A[MAX], B[MAX], n=10, key=10;
    cout<<"Enter total no. of elements  : ";    
	cin>>n;
    cout<<"Enter the Array Elements : " ;
    for (int i=0;i<n;i++){
        cin>>A[i];          //Reading the array from user
    }
    cout<<"\nEnter the hashing key : ";   
	cin>>key;
    HashingNoReplace(A,n,key);  //Without replacement
    cout<<"\n\n";
    HashingReplace(A,n,key);       //With replacement
    return 0;
}

void HashingNoReplace(int A[MAX], int n, int key){

    int LP[MAX];	//LP is the linear probing hashing array
    for (int i =0;i<MAX;i++)   //initialise all indices to -1
        LP[i] = -1;

    for (int i=0;i<n;i++)
	{
        int loc = A[i] % key;    //here key is our mod factor
        //if location is already filled with some element
        if (LP[loc]!=-1){
            for (int k=loc+1;k<MAX;k++)
			{
                if (LP[k]==-1) //find next empty location
				{  
                    loc = k;
                    break;
                }
            }
        }
        LP[loc] = A[i];         //place the element at the required location
    }
    cout<<"\nHashed Result (without replacement) : \n";     //print hashing result
    for (int i=0;i<MAX;i++)
        cout<<LP[i]<<"\t";
}

void HashingReplace(int A[MAX], int n, int key){

    int B[MAX];
    for (int i=0;i<n;i++)
        B[i] = A[i];

    int LP[MAX];	            //LP is the linear probing hashing array
    for (int i =0;i<MAX;i++)      
        LP[i] = -1;                     //initialise all indices to -1

    for (int i=0;i<n;i++)
	{
        int loc = B[i] % key, temp1=-1,flag=false;    //here key is our mod factor

        if (LP[loc]!=-1){   //if location is already filled with some element

            if (LP[loc] % 10 == loc);   //if a valid element already present at given location then skip the replacing
            else{
                    temp1 = LP[loc];
                    LP[loc] = B[i];
                    flag = true;
            }
            //if a valid element already present at given location then replace
            for (int k=loc+1;k<MAX;k++){
                if (LP[k]==-1) {
                    loc = k; break;         //find next empty location
                }
            }
        }
        if (flag == false)  
		{
			LP[loc] = B[i];               //assign the element at the required location
		}    
        else
		{
			LP[loc] = temp1;
		}   
    }
    cout<<"\nHashed Result : (with replacement) : \n";     //print hashing result
    for (int i=0;i<MAX;i++)
        cout<<LP[i]<<"\t";
}


/*
Output :

How many elements ?  : 5
Enter the Array Elements :
80
51
93
101
22

Enter the hashing key :   10

Hashed Result (without replacement) :
   80   51   101   93   22   -1   -1   -1   -1   -1


Hashed Result : (with replacement) :
   80   51   22   93   101   -1   -1   -1   -1   -1



*/
