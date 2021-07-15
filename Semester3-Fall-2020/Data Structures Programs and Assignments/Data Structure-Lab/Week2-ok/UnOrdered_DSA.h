#ifndef UNORDERED_DSA_H
#define UNORDERED_DSA_H

#include "DSA.h"

class UnOrdered_DSA : public DSA
{
	public:
		UnOrdered_DSA();
		UnOrdered_DSA(int resiz);
		UnOrdered_DSA(const UnOrdered_DSA& rhs);
		~UnOrdered_DSA();
		void searching(void);
		void insertion(void);
	protected:
};

#endif
