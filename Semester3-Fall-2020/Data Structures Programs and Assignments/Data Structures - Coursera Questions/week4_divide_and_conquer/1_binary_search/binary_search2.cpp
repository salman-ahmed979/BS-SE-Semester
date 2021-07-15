#include <iostream>
using namespace std;

int binary_search (int arr[], int low, int high, int key_value)
{
	int mid_point = 0;
	while (low <= high)
	{
		mid_point = (low+high)/2;
		if (arr[mid_point] == key_value)
			return mid_point;
		if (arr[mid_point] < key_value)
			low = mid_point+1;
		else
			high = mid_point-1;
	}
	return -1;
}
int main()
{
	int a=0, b=0;
	cin >> a;
	int arr[a]={0};
	for (int i=0; i<a; i++)
	{
		cin >> arr[i];
	}
	cin >> b;
	int key_val[b]={0};
	for (int i=0; i<b; i++)
	{
		cin >> key_val[i];
	}
	for (int i=0; i<b; i++)
	{
		int answer = binary_search(arr, 0, a-1, key_val[i]);
		cout << answer << " ";
	}
	return 0;
}
