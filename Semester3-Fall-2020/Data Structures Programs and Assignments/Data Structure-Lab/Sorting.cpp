#include<iostream>
using namespace std;

void swap(int arr[], int i, int min_index) {
	int temp = arr[i];
	arr[i] = arr[min_index];
	arr[min_index] = temp;
}

void SelectionSort(int arr[], int n) {
	for(int i=0; i<n-1; i++) {
		int min_index = i;
		for(int j=i+1; j<n; j++) {
			if(arr[j] < arr[min_index])
				min_index = j;
		}
		if(i != min_index)
			swap(arr, i, min_index);
	}
}


int main() {
	int arr[7] = {3,7,8,9,1,5,2};
	SelectionSort(arr, 7);
	for(int i=0; i<7; i++)
		cout<< arr[i] << " ";
	return 0;
}
