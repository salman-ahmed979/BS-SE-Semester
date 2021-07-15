#include "Car.h"
using namespace std;

Car::Car()
{
}

Car::Car(const Car& rhs)
{
	if(this != &rhs)
	{
		this->model_year = rhs.model_year;
		this->manufactured_company = rhs.manufactured_company;
		this->tyres = rhs.tyres;
	}
	cout << "\nDuplicate object created\n";
}

Car& Car::operator=(Car rhs)
{
	if(this!=&rhs)
	{
		this->model_year = rhs.model_year;
		this->manufactured_company = rhs.manufactured_company;
		this->tyres = rhs.tyres;
	}
	return *this;
}

Car::~Car()
{
	cout << "\nDestructor Called\n";
}

void Car::set_data()
{
	cout << "\nEnter Manufactured Company Name: ";
	cin >> this->manufactured_company;
	cout << "\nEnter Model Year: ";
	cin >> this->model_year;
	cout << "\nEnter Number of tyres: "; cin >> this->tyres;
	cout << "\n\nData Set\n\n";
}

void Car::print_data()
{
	cout << "\nManufactured Company: " << this->manufactured_company;
	cout << "\nModel Year: " << this->model_year;
	cout << "\nNumber of tyres: " << this->tyres;
}
