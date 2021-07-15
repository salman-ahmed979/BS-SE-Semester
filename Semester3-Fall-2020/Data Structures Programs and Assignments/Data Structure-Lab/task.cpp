#include<bits/stdc++.h>
#include<cstdlib>
using namespace std;

//Exception Handling
class ArrayIndexOutOfBound: public exception
{
	virtual const char* what() const throw()
	{
		return "Index Out of Bound";
	}	
} ArrayBoundException;

class LowerIndexBound: public ArrayIndexOutOfBound
{
	virtual const char* what() const throw()
	{
		return "Lower Index Out of Bound";
	}	
} LowerBoundException;

class UpperIndexBound: public ArrayIndexOutOfBound
{
	virtual const char*  what() const throw()
	{
		return "Upper Index Out of Bound";
	}
} UpperBoundException;

//Dynamic Safe Array
class DSA {
	private:
		int *Data;
		unsigned int size, current;
	public:
		DSA() {
			Data = 0; size = 0; current = 0;
		}
		//Parameterized Constructor
		DSA(int n) {
			size = n; current = 0;
			Data = new int[size];
			memset(Data, 0, sizeof(int)*size);
		}
		//Copy Constructor
		DSA(const DSA &rhs) {
			size = rhs.size; current = rhs.current;
			Data = new int[size];
			memcpy(Data, rhs.Data, sizeof(int)*size);
		}
		//Assignment Operator '=' Overload
		DSA& operator=(const DSA &rhs) {
			if(this!=&rhs)
			{
				size = rhs.size; current = rhs.current;
				if(Data!=0)
				{
					delete [] Data;
					Data = 0;
				}
				Data = new int[size];
				memcpy(Data, rhs.Data, sizeof(int)*size);
			}
			return *this;
		}
		//Destructor
		~DSA() {
			if(Data!=0)
			{
				delete [] Data;
				Data = 0; size = 0;
			}
		}
		//Ival
		int& operator[](int i) {
			if(i < 0)
				throw LowerBoundException;
			else if(i > size)
				throw UpperBoundException;
			else
				return *(Data+i);
		}
		//Rval
		const int& operator[](int i) const {
			if(i < 0)
				throw LowerBoundException;
			else if(i > size)
				throw UpperBoundException;
			else
				return *(Data+i);
		}
		void Resize(int siz) {
			if(size!=siz)
			{
				int *temp = new int[size];
				for(int i=0; i<size; i++) {
					temp[i] = *(Data+i);
				}
				delete [] Data;
				Data = 0;
				Data = new int[siz];
				memset(Data, 0, sizeof(int)*siz);
  				for(int i=0; i<size ; i++){
			    	
			    	*(Data+i)=temp[i];
			    }
			    size= siz;
			    delete [] temp;
			    temp=0;
			}
		}
		//Add Values in Array
		void input_data(int val) {
			if(current > size-1)
				Resize(size*2);
			Data[current] = val;
			current++;				
		}
		//Printing Data
		void print_data(void) {
			for (int i=0; i<size; i++)
				cout << Data[i] << " ";
		}
		//Sub
		bool sub_match(int i, int &num)
		{
			if(i==1)
				num -=2;
			else if(i==7)
				num -=3;
			else if(i==4)
				num -=4;
			else if(i==0 || i==6)
				num -=6;
			else if(i==8)
				num -=7;
			else
				num -=5;
			if(num < 0)
				return false;
			else
				return true;
		}
		bool chop_value(int i, int &num) {
			int r; bool check;
			while (i > 0)
			{
				r = i%10;
				check = sub_match(r, num);
				if (check==false) {
					return check;
				}
				i = i/10;
			}
			return check;
		}
		//Match Stick Problem
		void match_stick(int n) {
			bool var;
			for(int i=0; i<current; i++)
			{
				if(Data[i] <= 9)
				{
					var = sub_match(Data[i], n);
				}
				else {
					var = chop_value(Data[i], n);
				}
				if (var==false) {
					cout << "\nUnable to make at: " << Data[i];
					break;
				}
			}
			if(var==true)
				cout << "\nAble to make\n";
		}
};
int main()
{
	DSA d1(4);
	//for(int i=1; i<=4; i++)
		d1.input_data(1); d1.input_data(2); d1.input_data(10); d1.input_data(0);
	d1.match_stick(11);
	return 0;
}
