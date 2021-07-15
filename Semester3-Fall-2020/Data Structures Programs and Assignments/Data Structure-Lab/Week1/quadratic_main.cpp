#include "quadratic.hpp"
#include <iostream>
using namespace std;
int main()
{
    quadratic *q1 = new quadratic;
    q1.input_data();
    q1.calculate_roots();
    return 0;
}