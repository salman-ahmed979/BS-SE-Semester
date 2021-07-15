#ifndef CAR_H
#define CAR_H
#include <iostream>
using namespace std;
class Car
{
	private:
		int tyres, model_year;
		string manufactured_company;
	public:
		Car();
		Car(const Car& rhs);
		Car& operator=(Car rhs);
		void set_data(void);
		void print_data(void);
		~Car();
};

#endif
