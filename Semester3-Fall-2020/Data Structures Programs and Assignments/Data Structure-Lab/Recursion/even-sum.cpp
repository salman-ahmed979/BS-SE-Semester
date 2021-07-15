#include<iostream>
using namespace std;

long long even_number(long long n)
{
	
	if (n==0)
		return 0;
	if(n%2==0) 
		return n+even_number(n-1);  
	else
		return even_number(n-1);
}

//Largest element in array using recursion
int largest(int *arr, int max, int n)
{
	if(n==0)
		return max;
	else{
		if(arr[n-1] > max)
			max = arr[n-1];
		largest(arr, max, n-1);
	}
}
//First Capital letter in string using recursion
char first_capital(char *arr, int n, int s)
{
	if(n==0)
		return 'N';
	if(arr[s] >= 65 && arr[s] <=90)
		return arr[s];
	else
	{
		first_capital(arr, n-1, s+1);
	}
}

int main()
{
	long long n; cout << "\nEnter any number: "; cin >> n;
	cout << "\nEven Sum of numbers of digits: " << even_number(n) << endl;
	int arr[5] = {100, 180, 2, 4, 1};
	cout << "\nLargest: " << largest(arr, 0, 5);
	char ara[25] = "ilovemyPakistanCountry";
	cout << "\nCapital Letter is: " << first_capital(ara, 25, 0);
	return 0;
}
