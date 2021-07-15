#ifndef DSA_H
#define DSA_H

#include<bits/stdc++.h>
class DSA
{
	protected:
		int *Data;
		int size, current;
	public:
		DSA();
		DSA(int sizee);
		DSA(const DSA& rhs);
		DSA& operator=(const DSA& rhs);
		void Resize(int resize);
		void Double_resize(void);
		void print_data(void);
		int& operator[](int i); //Ival
		const int& operator[](int i) const; //Rval
        void insertion(void);
		void searching(void);
		~DSA();

};

#endif
