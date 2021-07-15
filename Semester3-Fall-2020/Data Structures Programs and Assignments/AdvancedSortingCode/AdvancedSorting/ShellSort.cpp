#include <iostream>

using namespace std;


template <class T>
void ShellSort(T a[], int l, int r)
  { int h; 
    for (h = 1; h <= (r-l)/9; h = 3*h+1) ;
    
	for ( ; h > 0; h /= 3)
      for (int i = l+h; i <= r; i++)
        { int j = i; T v = a[i]; 
          while (j >= l+h && v < a[j-h])
            { a[j] = a[j-h]; j -= h; }
          a[j] = v; 
        } 
  }
  
void Shell_Sort(int arr[], int n)
{
	int gap = 0;
	for(gap = n/2; gap > 0; gap /= 2)
	{
		for(int i=gap; i < n; i++)
		{
			int temp = arr[i];
			int j = i;
			while(j >= gap && temp < arr[j-gap])
			{
				arr[j] = arr[j-gap];
				j -= gap;
			}
			arr[j] = temp;
		}
	}
}
int main()
{
    int myarray[8]={1,4,6,2,3,55,8,7} ;
	int num=8;
    
    Shell_Sort(myarray,num);
    cout<<"Sorted Result:"<<endl;
    for (int i = 0; i < num; i++)
    {
        cout<<myarray[i]<<"  ";
    }
}
