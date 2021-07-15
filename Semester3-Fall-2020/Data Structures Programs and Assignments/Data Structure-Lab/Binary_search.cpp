#include<iostream>
using namespace std;
int BinarySearch(int arr[], int l, int r, int key) {
	if(l <= r) {
		int mid = (l + r) / 2;
		if(arr[mid] == key)
			return mid;
		else if(arr[mid] > key)
		    return	BinarySearch(arr, l, mid-1, key);
		else
			return BinarySearch(arr, mid+1, r, key);
	}
	return -1;
}
int main(){
	int arr[5] = {4,5,6,7,8};
	cout << BinarySearch(arr,0,4,5);
	return 0;
}
