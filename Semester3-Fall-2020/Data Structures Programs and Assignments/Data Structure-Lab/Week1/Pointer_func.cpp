#include <iostream>
using namespace std;

int add (int x, int y, int z)
{
	return (x+y+z);
}
int sub (int x, int y, int z)
{
	return (x-y-z);
}
//Function Pointer
// Return Type  (*Function_name_ptr) (parameter)
int (*Arithmatic_Pointer_function)(int x, int y, int z);

//Arithmatic Rapper Take 4 arguments, 3 int's and a function pointer
//   int (*)(int, int), which takes two int's and return an int
int Arithmatic_Rapper(int x, int y, int z, int (*Arth_pointr_func)(int x, int y, int z))
{
	return (*Arth_pointr_func)(x,y,z);
}

int main()
{
	int x=2, y=6, z=8;
	Arithmatic_Pointer_function = add;
	cout << "Add function: " << (*Arithmatic_Pointer_function)(x, y, z);
	cout << "\nArithmatic Rapper: " << Arithmatic_Rapper (x,y,z, sub);
}
