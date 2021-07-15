#include <iostream>
#include "emp_salary.hpp"
void salary::input_data(void)
{
        cout << "\nEnter Age of Employee: "; cin >> this->age;
        cout << "\nEnter Experience of Employee: "; cin >> this->experience;
        cout << "\nEnter Working Hours of Employee: "; cin >> this->working_hours;
}
void salary::salary_compute(void)
{
    bool var = true;
    if (age > 50 && experience >10 && working_hours > 240)
        this->salary_amount = this->working_hours * 500;
    else if (age <= 50 && age > 40 && experience > 6 && experience <=10 && working_hours > 200 && working_hours <= 240)
        this->salary_amount = this->working_hours * 425;
    else if (age <= 40 && age > 30 && experience > 3 && experience <=6 && working_hours > 160 && working_hours <= 200)
        this->salary_amount = this->working_hours * 375;
    else if (age <= 30 && age > 22 && experience > 1 && experience <=3 && working_hours > 120 && working_hours <= 160)
        this->salary_amount = this->working_hours * 300;
    else
    {
        cout << "\nInvalid Parameter\n";
        var=false;
    }
    if (var == true)
        cout << "\nSalary Amount of Employee is computed\n";
    }
void salary::print_data(void)
{
    cout << "\nAge: " << age << "\nExperience: " << experience << "\nWorking Hours: " << working_hours << "\nSalary: " << salary_amount <<endl;
}

