#include<bits/stdc++.h>
using namespace std;

class Searching {
	private:
		int *arr, size;
	public:
		
		Searching(int n)
		{
			size = n;
			arr = new int[size];
			memset(arr, 0, sizeof(int)*size);
		}
		
		void Input_data(void)
		{
			for(int i=0; i<size; i++)
				cin >> arr[i];
		}
		
		int BinarySearch(int low, int high, int key)
		{
			if(low <= high)
			{
				int mid = low + (high - low) / 2;
				
				if(arr[mid] ==  key) return mid;
				
				if(arr[mid] > key)
					return BinarySearch(low, mid-1, key);
				else 
					return BinarySearch(mid+1, high, key);
			}
			return -1;
		}
		
		int TernarySearch(int low, int high, int key)
		{
			
			if(low <= high)
			{
				int Onethird =  low + ( high - low )  / 3;
				int Twothird =  high - ( high - low )  / 3;
				
				if(arr[Onethird] == key)
					return Onethird;
				if(arr[Twothird] == key)
					return Twothird;
				if(arr[Onethird] > key)
					return TernarySearch(low, Onethird-1, key);
				else if(arr[Twothird] < key)
					return TernarySearch(Twothird+1, high, key);
				else
					return TernarySearch(Onethird+1, Twothird-1, key);
			}
			return -1;
		}
		
		int Interpolation_Search(int low, int high, int key)
		{
			if(arr[low] == key) return low;
			else if(arr[high] == key) return high;
			
			while(low <= high && key >= arr[low] && key <= arr[high])
			{
				if(low == high) {
					if(arr[low] == key) return low;
				}
				int pos = low + ( (high-low) / ( (arr[high] - arr[low]) * (key - arr[low]) ) );
				
				if(arr[pos] == key) return pos;
				if(arr[pos] < key) low = pos + 1;
				else
					high = pos -1;
			}
			return -1;
		}
};

int main()
{
	int n;
	cin >> n;
	Searching s1(n);
	s1.Input_data();
	cout << "\nEnter Key value to search: ";
	int key; cin >> key;
	
	//Binary Search
	cout << "\nBy Binary Search position is: " << s1.BinarySearch(0, n-1, key);
	
	//Ternary Search
	cout << "\nBy Ternary Search position is: " << s1.TernarySearch(0, n-1, key);
	
	//Interpolation Search
	cout << "\nBy Interpolation Search position is: " << s1.Interpolation_Search(0, n-1, key);
	return 0;
}
