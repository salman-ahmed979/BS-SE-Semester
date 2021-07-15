#include <iostream>
using namespace std;
void merge(int *,int, int , int );
void printCall(int *, int l, int h);

void printCall(int *arr, int low, int high)
{
  int i=0;
  
  cout<<"In MergeSort Call";
  cout<< "(Low is :" <<low << "- high is : " << high << ")" <<endl;
  for(i=low; i<=high; i++)
  {
  	cout<< arr[i] << "  ";
  	
  }	
  cout << endl;

	
}


void printCall2(int *arr, int low,int mid, int high)
{
  int i=0;
  cout<<"In Merging";
  cout<< "(Low is :" <<low << ",- mid is : " << mid << ", - high is : " << high << ")" <<endl;
  for(i=low; i<=high; i++)
  {
  	cout<< arr[i] << "  ";
  	
  }	
  cout << endl;

	
}


void merge_sort(int *arr, int low, int high)
{
    int mid;
    if (low < high){
        //if more than 2 elements-divide the array at mid and sort independently using merge sort
        mid=(low+high)/2;
        printCall(arr, low, mid);
        merge_sort(arr,low,mid);
        printCall(arr, mid, high);
        merge_sort(arr,mid+1,high);
        printCall2(arr, low,mid, high);
        //merge or conquer sorted arrays
        merge(arr,low,high,mid);
        printCall2(arr, low,mid, high);
    }
}
// Merge sort 
void merge(int *arr, int low, int high, int mid)
{
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            c[k] = arr[i];
            k++;
            i++;
        }
        else  {
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        c[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high) {
        c[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)  {
        arr[i] = c[i];
    }
}
// read input array and call mergesort
int main()
{
    int myarray[8]={1,4,6,2,3,5,8,7} ;
	int num=8;
    
    merge_sort(myarray, 0, num-1);
    cout<<"Sorted Result:"<<endl;
    for (int i = 0; i < num; i++)
    {
        cout<<myarray[i]<<"  ";
    }
}
