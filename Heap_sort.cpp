/*
Name :    Uddhav Rajendra patil
Roll no:  236
Batch:    E2
PRN no:   0220200126
Exam no:  S204153
Title: Write a program in C++ to implement Heap sort
*/

#include<iostream>
using namespace std;
void Max_heapify(int arr[], int n, int i)
{
    int largest = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 
  
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
  
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
  
    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
  
        // Recursively heapify the affected sub-tree
        Max_heapify(arr, n, largest);
    }
}
void Min_heapify(int arr[], int n, int i)
{
    int smallest = i; // Initialize smalles as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is smaller than root
    if (l < n && arr[l] < arr[smallest])
        smallest = l;
 
    // If right child is smaller than smallest so far
    if (r < n && arr[r] < arr[smallest])
        smallest = r;
 
    // If smallest is not root
    if (smallest != i) {
        swap(arr[i], arr[smallest]);
 
        // Recursively heapify the affected sub-tree
        Min_heapify(arr, n, smallest);
    }
}
void Max_heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)   //   i=n/2 because in heapify we calculate l and r  
        Max_heapify(arr, n, i);
  
   
    for (int i = n - 1; i >= 0; i--) 
	{      								// One by one extract an element from heap     
        swap(arr[0], arr[i]);               // Move current root to end      
        Max_heapify(arr, i, 0);			// call max heapify on the reduced heap
    }
}
void Min_heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
    	
        Min_heapify(arr, n, i);
 
    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call min heapify on the reduced heap
        Min_heapify(arr, i, 0);
    }
}
int main()
{
    
    int n ;
    cout<<"-----------Heap Sort--------------\n";
  	cout<<"Enter total no. of elements:";
  	cin>>n;
  	int arr[n] ;
  	cout<<"Enter "<<n<<" Elements:";
  	for(int i=0;i<n;i++)
  	{
  		cin>>arr[i];
	}
	
    Max_heapSort(arr, n);
    cout << "Sorted Ascending oredr:\n";
    for (int i = 0; i < n; ++i)
    {
    	cout << arr[i] << "  ";
	}
	
	
	Min_heapSort(arr, n);
    cout << "\nSorted Descending oredr:\n";
    for (int i = 0; i < n; ++i)
    {
    	cout << arr[i] << "  ";
	}
    return 0;
}



/*
output:--
---------Heap Sort--------------
Enter total no. of elements:5
Enter 5 Elements:4 5 1 2 3
Sorted Ascending oredr:
1  2  3  4  5
Sorted Descending oredr:
5  4  3  2  1
*/
