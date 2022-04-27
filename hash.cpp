
#include<iostream>
#define MAX 10

using namespace std;

class linear_probing_without_replacement{

    public:
    int a[MAX][2];
    int create(int);
    int hash(int,int);
    void display();
    linear_probing_without_replacement()
	{
        int i;
        for(i=0;i<MAX;i++)
        {
            a[i][0]=-1;
            a[i][1]=-1;
        }
    }
};

int linear_probing_without_replacement::create(int num)
{
    int key;
    key=num%10;
    return key;
}

int linear_probing_without_replacement::hash(int key,int num)
{
	int count=0,ch;
 	int flag=0;
  	int i=0;
  	while(i<MAX)
  	{
 		if(a[i][0]!=-1)
 		count++;
 		i++;
  	}
 	if(count==MAX)
 	{
  		cout<<"\nHash Table Is Full";
  		display();
  		exit(1);
  	}
 	if(a[key][0]==-1){
 		a[key][0]=num;
	}
 	else
 	{
  		ch=a[key][1];
  		if(ch==-1)
  		{
 			for(i=key+1;i<MAX;i++)
 			{
  				if(a[i][0]==-1)
  				{
   					a[i][0]=num;
   					a[key][1]=i;
   					flag=1;
   					break;
  				}	
 			}	
  		}
  		else
  		{
 			while((a[ch][0]!=-1)&&(a[ch][1]!=-1))
  			ch=a[ch][1];
 			for(i=ch+1;i<MAX;i++)
 			{
  				if(a[i][0]==-1)
  				{
				   a[i][0]=num;
				   a[ch][1]=i;
				   flag=1;
				   break;
				}
			}
		}
		
		if(flag!=1)
		{
			if(ch==-1)
		  	{
		 		for(i=0;i<key;i++)
		 		{
		  			if(a[i][0]==-1)
		  			{
		   				a[i][0]=num;
		   				a[key][1]=i;
		   				flag=1;
		   				break;
		  			}
		 		}
		  	}
		  	else
		  	{
		 		while((a[ch][0]!=-1)&&(a[ch][1]!=-1))
				{
		  			ch=a[ch][1];
		 			for(i=ch+1;i<key;i++)
		 			{
						if(a[i][0]==-1)
						{
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
}

void linear_probing_without_replacement::display()
{
 	int i;
 	cout<<"\n The Hash Table is...\n";
 	for(i=0;i<MAX;i++)
  	cout<<"\n  "<<i<<" "<<a[i][0]<<" "<<a[i][1];
}


class Hash
{
 private:
  int a[MAX];
  public:
  Hash();
  int create(int);
  void linear_prob(int,int);
  void display1();
};


Hash::Hash()
{
 int i;
 for(i=0;i<MAX;i++)
  a[i]=-1;
}


int Hash::create(int num)
{
 int key;
 key=num%10;
 return key;
}



void Hash::linear_prob(int key,int num)
{
 int flag,i,count=0;
 flag=0;
 if(a[key]==-1)//if the location indicated by hash key is empty
 a[key]=num;//place the number in the hash table
 else
 {
  i=0;
  while(i<MAX)
  {
 	if(a[i]!=-1)
  	count++;
 	i++;
  }
  if(count==MAX)        //checking for the hash full
  {
 	cout<<"\nHash Table Is Full Hence "<<num<<" Can not Be Inserted";
    display1();
    exit(1);
 }
 	for(i=key+1;i<MAX;i++)//moving linearly down
 	if(a[i]==-1)    // searching for empty location
 	{
  		a[i]=num;  //placing the number at empty location
  		flag=1;
  		break;
 	}

//From key position to the end of array we have searched empty location

//and now we want to check empty location in the upper part of the array

 	for(i=0;i<key&&flag==0;i++)//array from 0th to keyth loaction will be scanned

 	if(a[i]==-1)
	
 	{	
  	a[i]=num;
  flag=1;

  break;

 }

 } //outer else

}//end




void Hash::display1()

{

 int i;
 cout<<"\n The Hash Table is..."<<endl;
 for(i=0;i<MAX;i++)
 cout<<"\n  "<<i<<"  "<<a[i];
}

int main()
{
	int ch;
	cout<<"Enter choice:\n1. Linear probing Without Replacement.\n2. Linear probing With Replacement.\n";
	cin>>ch;
	linear_probing_without_replacement h;
 	switch(ch)
	{
		case 1: 
			int num,key,i;
		 	char ans;
		 	cout<<"\n---------------Linear Probing without Replacement-----------";
		 	do
		 	{
		  		cout<<"Enter The Number:";
		  		cin>>num;
		  		key=h.create(num);
		  		h.hash(key,num);
		  		cout<<"Do U Wish To Continue?(y/n)";
		  		cin>>ans;
 			}
			while(ans=='y');
 			h.display();
		break;
		
		case 2: 
			int num1,key1;
			char ans1;
			Hash h1;
			cout<<"\n---------------Linear Probing with Replacement-----------\n";
			do
			{
			  cout<<"Enter The Number:";
			  cin>>num1;
			  key1=h.create(num1);//returns hash key
			  h1.linear_prob(key1,num1);//collision handled by linear probing
			  cout<<"Do U Wish To Continue?(y/n)";
			  cin>>ans1;
			 }while(ans1=='y');
			h1.display1();
		break;
	}
}


