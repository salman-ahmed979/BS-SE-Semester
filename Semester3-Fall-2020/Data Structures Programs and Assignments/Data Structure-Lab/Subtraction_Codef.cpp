#include<iostream>
using namespace std;
int sub(int n, int k)
{
	while(k > 0)
	{
		if(n > 9)
		{
			int r = n;
			int l = r % 10;
			if(l > 0)
				n--;
			else
				n /= 10;
		}
		else if(n > 0)
			n--;
		else
			n /= 10;
		k--;
	}
	return n;
}
int main()
{
	int n, k;
	cin >> n >> k;
	cout << sub(n,k);
	return 0;
}
