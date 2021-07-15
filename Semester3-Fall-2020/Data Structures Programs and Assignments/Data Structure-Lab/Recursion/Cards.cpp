#include<iostream>
using namespace std;

int main()
{
	string inp; bool var = false;
	cin >> inp;
	string arr[5];
	for(int i=0; i<5; i++)
	{
		cin >> arr[i];
		if(arr[i][0] == inp[0] || arr[i][1] == inp[1])
			var = true;
	}
	if(var)
	{
		cout<<"YES";
	}
	else 
		cout<<"NO";
	return 0;
}
