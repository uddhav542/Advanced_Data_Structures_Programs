#include<iostream>
#define MAX 10
#include <conio.h>
using namespace std;

class Hash_without_replacement{
    public:
    int a[MAX][2];
    Hash_without_replacement();
    int create(int);
    int hash(int,int);
    void display();
};

Hash_without_replacement :: Hash_without_replacement(){
    int i;
    for(i=0;i<MAX;i++){
        a[i][0]=-1;
        a[i][1]=-1;
    }
}

int Hash_without_replacement::create(int num){
    int key;
    key=num%10;
    return key;

}


int Hash_without_replacement::hash(int key,int num){
    int flag,i,count=0,ch;
    flag=0;
    i=0;
    while(i<MAX){
        if(a[i][0]!=-1)
            count++;
        i++;
    }
    if(count==MAX) {
        cout<<"\nHash Table Is Full";
        display();
        getch();
    }
    if(a[key][0]==-1)
        a[key][0]=num;
    else{
        ch=a[key][1];
        if(ch==-1){
            for(i=key+1;i<MAX;i++){
                if(a[i][0]==-1){
                    a[i][0]=num;
                    a[key][1]=i;
                    flag=1;
                    break;
                }
            }
        }
        else{
            while((a[ch][0]!=-1)&&(a[ch][1]!=-1))
                ch=a[ch][1];
            for(i=ch+1;i<MAX;i++){
                if(a[i][0]==-1){
                    a[i][0]=num;
                    a[ch][1]=i;
                    flag=1;
                    break;
                }
            }
        }
        if(flag!=1){
            if(ch==-1){
                for(i=0;i<key;i++){
                    if(a[i][0]==-1){
                        a[i][0]=num;
                        a[key][1]=i;
                        flag=1;
                        break;
                    }
                }
            }
            else{
                while((a[ch][0]!=-1)&&(a[ch][1]!=-1))
                ch=a[ch][1];
                for(i=ch+1;i<key;i++){
                    if(a[i][0]==-1){
                        a[i][0]=num;
                        a[ch][1]=i;
                        flag=1;
                        break;
                    }
                }
            }
        }
    }
}
void Hash_without_replacement::display(){
    int i;
    cout<<"\nThe Hash Table is --> ";
    for(i=0;i<MAX;i++)
    cout<<"\n  "<<i<<" --> "<<a[i][0];
}

int main(){
    int num,key,i;
    char ans;
    Hash_without_replacement h;
    cout<<"\n********************* Linear Probing Without Replacement **********************";
    do{
        cout<<"\nEnter The Number --> ";
        cin>>num;
        key=h.create(num);
        h.hash(key,num);
        cout<<"Do U Wish To Continue?(y/n) : ";
        cin>>ans;
    }while(ans=='y');
    h.display();
    return 0;
}
