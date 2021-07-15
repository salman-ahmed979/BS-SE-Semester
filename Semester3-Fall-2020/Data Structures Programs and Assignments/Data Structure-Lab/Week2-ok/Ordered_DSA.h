#ifndef ORDERED_DSA_H
#define ORDERED_DSA_H

#include "DSA.h"

class Ordered_DSA: public DSA
{
    public:
        Ordered_DSA();
        Ordered_DSA(int resiz);
        Ordered_DSA(const Ordered_DSA& rhs);
        ~Ordered_DSA();
        void searching(void);
        void insertion(void);
};

#endif