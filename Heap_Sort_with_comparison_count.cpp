#include <iostream>

using namespace std;

int comp =0;

void heapify(int arr[], int n, int i)
{
	int largest = i; // Initialize largest as root
	int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2

	// If left child is larger than root
	if (l < n ){
		if(arr[l] > arr[largest])
		largest = l;
		comp++;
	}
	// If right child is larger than largest so far
	if (r < n  ){
		if(arr[r] > arr[largest])
		largest = r;
		comp++;
	}
	
	if (largest != i) {
		swap(arr[i], arr[largest]);

		heapify(arr, n, largest);
	}
}

void heapSort(int arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	for (int i = n - 1; i > 0; i--) {
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}


void printArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

int main()
{
	int size,ext;
  begin:
  	comp=0;
	cout<<"Enter the size of array : ";
	cin>>size;
	int arr[size];
	cout<<"\n\n";
	for(int i=0;i<size;i++)
	{
		cout<<"Enter element "<<i+1<<" in an array : ";
		cin>>arr[i];
	}
	
    cout << "\n\nGiven array is :    ";
	printArray(arr, size);
	
	heapSort(arr, size);

	cout<<"\n\nSorted array is:   ";
	printArray(arr, size);
	cout<<"\nNo of comparisons are :  "<<comp;
	cout<<"\n\nPress 1 to start again / any other key to exit : ";
  	cin>>ext;
  	if(ext == 1)
     	goto begin;
	return 0;
}

