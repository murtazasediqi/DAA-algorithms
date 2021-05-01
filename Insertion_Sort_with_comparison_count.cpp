#include <bits/stdc++.h>
using namespace std;

int insertionSort(int arr[], int n)
{
	int i, key, j,count;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		while (j >= 0 )
		{if(arr[j] > key){
			arr[j + 1] = arr[j];
			j = j - 1;
			count++;}
			else{
				count++;
				break;
			}
		}
		arr[j + 1] = key;
	}
	return count;
}

void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}


int main()
{ 	int size,comp,ext;
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
	comp = insertionSort(arr, size);
	cout<<"\n\nSorted array is:   ";
	printArray(arr, size);
	cout<<"\nNo of comparisons are :  "<<comp;
	cout<<"\n\nPress 1 to start again / any other key to exit : ";
  	cin>>ext;
  	if(ext == 1)
     	goto begin;
	return 0;
}


