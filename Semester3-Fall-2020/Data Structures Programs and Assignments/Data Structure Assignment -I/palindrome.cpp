#include<iostream>
using namespace std;
bool Ispalindrome(int arr[], int size)
{
	int j=size-1, count=0;
	bool var = true;
	for(int i=0; i<size/2; i++)
	{
		if(arr[i] == arr[j]) {
			count++;
		}
		
		else if(arr[i] != arr[j]) {
			int sub = 0;
			if(arr[i] > arr [j])
				sub = arr[i] - arr[j];
			else
				sub = arr[j] - arr[i];
			if(sub%9==0) {
				var = true;
				count++;	
			}
			else {
				var = false;
				break;	
			}
		}
		j--;
	}
	
	if(size%2!=0) {
		//j--;
		if(arr[j]>=9 && arr[j]%11!=0)
			var = false;
	}
	if(var==true)
		return true;
	else
		return false;
}
int main()
{
	int n=0; cin >> n;
	int arr[n];
	for(int i=0; i<n; i++) {
		cin>>arr[i];
	}
	bool exp = Ispalindrome(arr, n);
	if (exp==true) cout << "YES";
	else
		cout << "NO";
	return 0;
}
