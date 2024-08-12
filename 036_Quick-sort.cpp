#include<iostream>
using namespace std;

int partition(int arr[], int s, int e){
	int pivot = arr[s];

	int count = 0;
	for(int i=s+1; i<=e; i++){
		if(arr[i] <= pivot)
			count++;
	}

	// place pivot at right place
	int pivotIndex = s + count;
	swap(arr[pivotIndex], arr[s]);

	//left and right sorting
	int i = s, j = e;

	while(i < pivotIndex && j > pivotIndex){

		while(arr[i] <= pivot){
			i++;
		}
		while(arr[j] > pivot){
			j--;
		}

		if(i < pivotIndex && j > pivotIndex){
			swap(arr[i++], arr[j--]);
		}
	}
	return pivotIndex;
}

void quickSort(int arr[], int s, int e){
	// base case
	if(s >= e)
		return;

	// partition
	int p = partition(arr, s, e);

	// left part
	quickSort(arr, s, p-1);

	// right part
	quickSort(arr, p+1, e);
}

int main(){
	int arr[14] = {2, 4, 1, 6, 9, 99, 15, 3, 17, 19, 11, 56, 24, 10};
	int n = 14;

	cout << "Unsorted array : ";

	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}cout << endl;

	quickSort(arr, 0, n-1);

	cout << "Sorted array : ";

	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}cout << endl;

}