#include "Ordered_DSA.h"
using namespace std;

Ordered_DSA::Ordered_DSA(){}

Ordered_DSA::Ordered_DSA(int resiz):DSA(resiz){}

Ordered_DSA::Ordered_DSA(const Ordered_DSA& rhs): DSA(rhs){}

Ordered_DSA::~Ordered_DSA(){}

void Ordered_DSA::insertion()
{
	int num = 0;
	cout << "\nEnter elements: ";
	cin >> num;
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
	if(current > 1)
	{
		for(int i=0; i<current; i++)
		{	
			for(int j=0; j<current; j++)
			{
				if(i!=j)
				{
					if(Data[i] < Data[j])
					{
						int temp = 0;
						temp = Data[i];
						Data[i] = Data[j];
						Data[j] = temp;
					}	
				}	
			}	
		}	
	}
}

void Ordered_DSA::searching()
{
	int num = 0;
	cout << "\nEnter Number to search: ";
	cin >> num;
	for(int i=0; i<current; i++)
	{
		if(num==Data[i])
			cout << "\nIndex Position of Element: " <<i<<"\nNumber found: " <<Data[i];
	}
}
