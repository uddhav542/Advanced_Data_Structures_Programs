#include<bits/stdc++.h>
#include<conio.h>
#define MAX 10
using namespace std;
class Hash{
private:
    int a[MAX];
public:
    Hash();
    int create(int);
    void linear_prob(int,int),display();
};
Hash::Hash(){
    int i;
    for(i=0;i<MAX;i++)
        a[i]=-1;
}
int Hash::create(int num){
    int key;
    key=num%10;
    return key;
}
void Hash::linear_prob(int key,int num){
    int flag,i,count=0;
    flag=0;
    if(a[key]==-1)                                                         //if the location indicated by hash key is empty
        a[key]=num;                                                        //place the number in the hash table
    else{
            i=0;
            while(i<MAX){
                if(a[i]!=-1)
                    count++;
                i++;
            }
        if(count==MAX){                                                         //checking for the hash full
            cout<<"\nHash Table Is Full Hence "<<num<<" Can not Be Inserted";
            display();
            exit(1);
        }
        for(i=key+1;i<MAX;i++){                                                    //moving linearly down
            if(a[i]==-1){                                                           // searching for empty location
                a[i]=num;                                                          //placing the number at empty location
                flag=1;
                break;
            }
         }                                                               //From key position to the end of array we have searched empty location
                                                                        //and now we want to check empty location in the upper part of the array
        for(i=0;i<key&&flag==0;i++){                                           //array from 0th to keyth loaction will be scanned
            if(a[i]==-1){
                a[i]=num;
                flag=1;
                break;
            }
        }
    }
}

void Hash::display(){
    int i;
    cout<<"\nThe Hash Table is --> "<<endl;
    for(i=0;i<MAX;i++)
        cout<<"\n  "<<i<<" --> "<<a[i];
}
int main()
{
    int num,key;
    char ans;
    Hash h;
    cout<<"\n********************* Linear Probing without Replacement **********************";
    do{
        cout<<"\nEnter The Numbe --> ";
        cin>>num;
        key=h.create(num);                                  //returns hash key
        h.linear_prob(key,num);                             //collision handled by linear probing
        cout<<"Do U Wish To Continue?(y/n) : ";
        cin>>ans;
    }while(ans=='y');
    h.display();
    cout<<endl;                                            //displays hash table
    return 0;
}


