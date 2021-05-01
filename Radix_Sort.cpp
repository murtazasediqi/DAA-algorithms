#include <iostream>
using namespace std;

int getMax(int arr[], int n)
{
	int mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}

void countSort(int arr[], int n, int exp)
{
	int output[n]; 
	int i, count[10] = { 0 };
	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = n - 1; i >= 0; i--) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}
	
	for (i = 0; i < n; i++)
		arr[i] = output[i];
}

void radixsort(int arr[], int n)
{

	int m = getMax(arr, n);

	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(arr, n, exp);
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
	
	radixsort(arr, size);

	cout<<"\n\nSorted array is:   ";
	printArray(arr, size);
	cout<<"\n\nPress 1 to start again / any other key to exit : ";
  	cin>>ext;
  	if(ext == 1)
     	goto begin;
	return 0;
}

