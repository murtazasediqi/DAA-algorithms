#include <iostream>
using namespace std;

int comp =0;

void merge(int arr[], int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2];

	for (int i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	int i = 0;
	int j = 0;
	int k = l;

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
			comp++;
		}
		else {
			arr[k] = R[j];
			j++;
			comp++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[],int l,int r){
	if(l>=r){
		return;
	}
	int m =l+ (r-l)/2;
	mergeSort(arr,l,m);
	mergeSort(arr,m+1,r);
	merge(arr,l,m,r);
}

void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
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
	mergeSort(arr, 0, size - 1);

	cout<<"\n\nSorted array is:   ";
	printArray(arr, size);
	cout<<"\nNo of comparisons are :  "<<comp;
	cout<<"\n\nPress 1 to start again / any other key to exit : ";
  	cin>>ext;
  	if(ext == 1)
     	goto begin;
	return 0;
}

