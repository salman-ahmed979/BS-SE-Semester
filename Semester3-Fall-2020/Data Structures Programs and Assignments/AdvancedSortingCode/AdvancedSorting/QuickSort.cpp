#include<iostream>

using namespace std;

template<class T>
void exch(T a, T b){
	
	T temp;
	temp=a;
	a=b;
	b=temp;
	
}

template <class T>
int partition(T a[], int l, int r)
  { int i = l-1, j = r; T v = a[r];
    for (;;)
      { 
        while (a[++i] < v) ;
        while (v < a[--j]) if (j == l) break;
        if (i >= j) break;
        exch(a[i], a[j]);
      }
    exch(a[i], a[r]);
    return i;
  }


template <class T>
void quicksort(T a[], int l, int r)
  {
    if (r <= l) return;
    int i = partition(a, l, r);
    cout<< i <<endl;
    quicksort(a, l, i-1);
    quicksort(a, i+1, r);
  }


  
int main(){
	
long int myarray[8]={1,4,6,2,3,5,8,7} ;
long int num=8;
    
    quicksort(myarray,0,num-1);
    cout<<"Sorted Result:"<<endl;
    for (int i = 0; i < num; i++)
    {
        cout<<myarray[i]<<"  ";
    }	
	
	return 0;
}
