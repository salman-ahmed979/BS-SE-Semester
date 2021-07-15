#include<iostream>
using namespace std;

void Tower_Hanoi(int n, char from_rod, char to_rod, char middle_rod)
{
	if(n==1)
	{
		cout << "\nMove disk " << n << " from rod " << from_rod << " to rod " << to_rod << endl;
		return;
	}
	Tower_Hanoi(n-1,from_rod, middle_rod, to_rod);
	cout << "\nMove disk " << n << " from rod " << from_rod << " to rod " << to_rod << endl;
	Tower_Hanoi(n-1,middle_rod, to_rod, from_rod);
}

int main()
{
	Tower_Hanoi(3,'A', 'C', 'B');
	return 0;
}
