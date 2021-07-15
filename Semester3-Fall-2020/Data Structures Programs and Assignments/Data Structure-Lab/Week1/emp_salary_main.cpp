#include "emp_salary.hpp"
#include <iostream>
using namespace std;
int main()
{
    //Dynamic Allocation of "N" Objects
    int n=0;
    cout << "\nEnter Number of employee objects to be created: ";
    cin >> n;
    salary *ptr = new salary[n];
    //ptr = new salary[n];
    for (int i=0; i<n; i++)
    {
        cout << "\nEntering Data in Object " << i <<endl;
        ptr[i].input_data();
    }
    for (int i=0; i<n; i++)
    {
        cout << "\nComputing salaries of employee\n";
        ptr[i].salary_compute();
    }
    for (int i=0; i<n; i++)
    {
        cout << "\nPrinting Data of all employees\n";
        ptr[i].print_data();
    }
    delete [] ptr;
    return 0;
}
