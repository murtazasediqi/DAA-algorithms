#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <time.h>
#include <iostream>
using namespace std;

int compmerge =0,compins =0,compquick =0,compheap =0;

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
			compmerge++;
		}
		else {
			arr[k] = R[j];
			j++;
			compmerge++;
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

void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		while (j >= 0 )
		{if(arr[j] > key){
			arr[j + 1] = arr[j];
			j = j - 1;
			compins++;}
			else{
				compins++;
				break;
			}
		}
		arr[j + 1] = key;
	}
//	return count;
}


int partition(int arr[], int low, int high)
{
	int pivot = arr[high];

	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		
		if (arr[j] <= pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
		compquick++;
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}


int partition_r(int arr[], int low, int high)
{
	
	//srand(time(NULL));
	int random = low + rand() % (high - low);
	
	swap(arr[random], arr[high]);

	return partition(arr, low, high);
}


void quickSort(int arr[], int low, int high)
{
	if (low < high) {

		int pi = partition_r(arr, low, high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}


void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void heapify(int arr[], int n, int i)
{
	int largest = i; // Initialize largest as root
	int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2

	// If left child is larger than root
	if (l < n ){
		if(arr[l] > arr[largest])
		largest = l;
		compheap++;
	}
	// If right child is larger than largest so far
	if (r < n  ){
		if(arr[r] > arr[largest])
		largest = r;
		compheap++;
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


int main()
{
	int ext;
	int randomnum,randomval;
	cout<<"                                 no of comparisons required by \n";
	cout<<"                      -----------------------------------------------------\n";
  	cout<<"no. of values input   merge sort   insertion sort   Rquick sort   heap sort\n";
  	for(int i=0;i<100;i++){
  	  compmerge =0,compins =0,compquick =0,compheap =0;
	  randomnum = 30 + rand() % (970);
	  int arrmerge[randomnum];
	  int arrins[randomnum];
	  int arrquick[randomnum];
	  int arrheap[randomnum];
	  cout<<setw(10)<<randomnum;
	  for(int j= 0;j<randomnum;j++){
	 	 randomval = rand()+1;
	 	 arrmerge[i]=randomval;
	 	 arrins[i]=randomval;
	 	 arrquick[i]=randomval;
	 	 arrheap[i]=randomval;
	 	// cout<<randomval<<endl;
	 }
	 mergeSort(arrmerge, 0, randomnum - 1);
	 cout<<setw(18)<<compmerge;
	 insertionSort(arrins, randomnum);
	 cout<<setw(16)<<compins;
	 quickSort(arrquick, 0, randomnum - 1);
	 cout<<setw(16)<<compquick;
	 heapSort(arrheap, randomnum);
	 cout<<setw(13)<<compheap<<"\n";
}
  	
  	
  	
  	
	return 0;
}

