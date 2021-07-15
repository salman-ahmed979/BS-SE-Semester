#include "UnOrdered_DSA.h"
using namespace std;
UnOrdered_DSA::UnOrdered_DSA()
{
}

UnOrdered_DSA::~UnOrdered_DSA()
{
}

UnOrdered_DSA::UnOrdered_DSA(int resiz):DSA(resiz){
}

UnOrdered_DSA::UnOrdered_DSA(const UnOrdered_DSA& rhs): DSA(rhs){
}

void UnOrdered_DSA::searching(void)
{
	int search = 0;
	cout << "\nEnter element to search: ";
	cin >> search;
	for(int i=0; i<this->size; i++)
	{
		if(search==Data[i])
		{
			cout << "\nIndex Position of Element: " << i << "\nElement found: " << Data[i];
		}
	}
}

void UnOrdered_DSA::insertion(void)
{
	int num=0;
	cout << "\nEnter Number: "; cin >> num;
	if(current < size-1)
	{
		Data[current] = num;
	}
	else
	{
		this->Double_resize();
		Data[current] = num;
	}
	current +=1;
}
