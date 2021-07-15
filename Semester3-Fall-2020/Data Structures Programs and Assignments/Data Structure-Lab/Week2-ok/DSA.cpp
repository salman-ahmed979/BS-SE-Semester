#include "DSA.h"
using namespace std;
DSA::DSA()
{
	Data = 0; size = 0; current = 0;
}

DSA::DSA(int sizee)
{
	this->size = sizee;
	current = 0;
	Data = new int[size];
	memset(Data,0,sizeof(int)*size);
}

DSA::DSA(const DSA& rhs)
{
	if(this != &rhs)
	{
		size = rhs.size;
		this->Data = new int[size];
		memcpy(Data, rhs.Data, sizeof(int)*this->size);
	}
	current = 0;
}

DSA& DSA::operator=(const DSA& rhs)
{
	if(this != &rhs)
	{
		size = rhs.size;
		Data = 0; 
		delete [] Data;
		
		Data = new int[size];
		memcpy(this->Data, rhs.Data, sizeof(int)*size);
	}
	return *this;	
}

//Ival
int& DSA::operator[](int i)
{
	if(i<0 || i>size-1)
	{
		cout << "\nArray out of bound\n"; return Data[size-1];
	}
	else{
		return Data[i];
	}
}

//Rval
const int& DSA::operator[](int i) const
{
	if(i<0 || i>size-1)
	{
		cout << "\nArray out of bound\n"; return Data[size-1];
	}
	else{
		return Data[i];
	}
}

void DSA::Resize(int resize)
{
	if(size!=resize)
	{
		int *temp = new int[size];
		memcpy(temp, Data, sizeof(int)*size);
		
		Data = 0;
		delete [] Data;
		Data = new int[resize];
		for(int i=0; i<size; i++)
		{
			Data[i] = temp[i];
		}
		size = resize;
		temp = 0; delete [] temp;
	}
}

void DSA::Double_resize(void)
{
	int *temp = new int[size];
	memcpy(temp, Data, sizeof(int)*size);
		
	Data = 0;
	delete [] Data;
	int res = size;
	size *=2;
	Data = new int[size];
	for(int i=0; i<res; i++)
	{
		Data[i] = temp[i];
	}
	temp = 0; delete [] temp;
}

void DSA::print_data()
{
	cout << "\nPrinting Data\n";
	cout << "\nSize of Array: "; cout << size;
	for (int i=0; i<current; i++)
	{
		cout << Data[i] << " ";
	}
}

DSA::~DSA()
{
	Data = 0;
	delete [] Data;
}

void DSA::insertion(){
}

void DSA::searching(){
}
