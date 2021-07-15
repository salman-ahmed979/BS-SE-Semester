#ifndef QUAD_H
#define QUAD_H

#include <iostream>
using namespace std;
class quadratic
{
    private:
    int a, b, c;
    float discriminant, x1, x2;

    public:
    void input_data(void);
    void calculate_roots(void);
};
#endif