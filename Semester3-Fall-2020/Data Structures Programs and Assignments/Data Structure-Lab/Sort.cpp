#include<iostream>
#include<queue>
using namespace std;

void Swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void Merge(int *arr, int l, int r, int m)
{
	int mid1 = m - l + 1;
	int mid2 = r - m;
	
	int L[mid1] , R[mid2];
	cout << "\nLeft array: ";
	for(int i=0; i<mid1; i++){
		L[i] = arr[l+i];
		cout << L[i] << " ";
	}
		cout << "\nRight Array: ";
	for(int j=0; j<mid2; j++){
		R[j] = arr[m+1+j];
		cout << R[j] << " ";		
	}
	cout << "\n";
	int i = 0, j = 0, k = l;
	while(i < mid1 && j < mid2)
	{
		if(L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	
	while(i < mid1)
	{
		arr[k] = L[i];
		i++; k++;
	}
	while(j < mid2)
	{
		arr[k] = R[j];
		j++; k++;
	}
}

void MergeSort(int *arr, int l, int r)
{
	if(l < r)
	{
		int mid = (l + r-1) / 2;
		MergeSort(arr, l, mid);
		MergeSort(arr, mid+1, r);
		Merge(arr, l, r, mid);
	}
	else return;
}

//Quick Sort
int partition(int *arr, int l, int r)
{
	int i = l-1, pivot = arr[r];
	for(int j=l; j<=r-1; j++)
	{
		if(arr[j] < pivot)
		{
			i++;
			Swap(&arr[i], &arr[j]);
		}
	}
	Swap(&arr[i+1], &arr[r]);
	return i+1;	
}

void QuickSort(int *arr, int l, int r)
{
	if(l < r)
	{
		int pi = partition(arr, l, r);
		QuickSort(arr, l, pi-1);
		QuickSort(arr, pi+1, r);
	}
}

// Count Sort
void CountSort(int *arr, int n)
{
	int i = 0;
	int largest = arr[0];
	
	for(int i=1; i<n; i++)
		if(largest < arr[i])
			largest = arr[i];
	
	int count[largest+1], temp[n];
	
	for(i=0; i<=largest; i++)
	{
		count[i] = 0;
	}
		
	for(i=0; i<n; i++)
		count[ arr[i] ]++;
		
	for(i=0; i<=largest; i++)
		count[i] = count[i-1] + count[i];
			
	for(i=n-1; i>=0; i--){
		temp[ count[ arr[i] ] -1 ] = arr[i];
		count[arr[i]]--;
	}
	
	for(i=0; i<n; i++)
		arr[i] = temp[i];
}

void RadixSort(int *arr, int n)
{
	int digits = 10, radix = 10, factor = 1;
	queue<int>q1[radix];
	for(int d=0; d < digits; d++, factor *=radix)
	{
		for(int j=0; j<n; j++)
			q1[ (arr[j] / factor) %radix].push(arr[j]);	
			
		for(int j=0, k=0; j<radix; j++)
		{
			while(!q1[j].empty())
			{
				arr[k++] = q1[j].front();
				q1[j].pop();
			}
		}
	}	
}

int main()
{
	int arr[5] = { 4,22,434,112,53};
	QuickSort(arr, 0, 5-1);
	//MergeSort(arr, 0, 5-1);
	//RadixSort(arr,5);
	//CountSort(arr, 5);
	for(int i=0; i<5; i++)
		cout << arr[i] << " ";
	return 0;
}
