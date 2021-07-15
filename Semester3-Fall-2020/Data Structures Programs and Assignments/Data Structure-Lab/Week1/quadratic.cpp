#include "quadratic.hpp"
#include <iostream>
#include <cmath>
using namespace std;

void quadratic::input_data(void)
{
    cout << "\nEnter value of a: "; cin >> a;
    cout << "\nEnter value of b: "; cin >> b;
    cout << "\nEnter value of c: "; cin >> c;
}
void quadratic::calculate_roots(void)
{
    discriminant = ((b*b) - (4*a*c));
    if (discriminant > 0)
    {
        x1 = (-b + (sqrt(discriminant))) / (2*a);
        x2 = (-b - (sqrt(discriminant))) / (2*a);
        cout << "\nx1 = " << x1 << "\nx2 = " << x2 << endl;
    }
    else if (discriminant == 0)
    {
        x1 = x2 = -b / (2*a);
        cout << "\nx1 =  " << x1 << "\nx2 =  " << x2 <<endl;
    }
    else 
    {
        cout << "\nx1 = " << "real : " << -b / (2*a) << " + " << (sqrt(-discriminant))/(2*a) << "i\n";
        cout << "\nx2 = " << "real : " << -b / (2*a) << " - " << (sqrt(-discriminant))/(2*a) << "i\n";
    }
}