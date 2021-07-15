#include <iostream>
using namespace std;

class check_ptr_axes
{
	private:
		int *itsX, *itsY;
	public:
		//Parametrized Constructor
		check_ptr_axes (int x, int y)
		{
			itsX = new int;
			*itsX = x;
			itsY = new int;
			*itsY = y;
		}
		
		//Default Constructor	
		check_ptr_axes ()
		{
			itsX = new int; *itsX = 0;
			itsY = new int; *itsY = 0;
		}
		
		//Copy Constructor
		check_ptr_axes (check_ptr_axes &obj)
		{
			itsX = new int;
			*itsX = obj.getX();
			itsY = new int;
			*itsY = obj.getY();
		}
		
		//Getter Function
		int getX(void) {
			return *itsX;
		}
		int getY(void){
			return *itsY;
		}
		
		//Overloading Assignment Operator ' == '
		check_ptr_axes & operator == (check_ptr_axes &obj)
		{
			if (this == &obj) return *this;
			else
			{
				delete itsX; delete itsY;
				itsX = new int;
				*itsX = obj.getX();
				itsY = new int;
				*itsY = obj.getY();
				return *this;
			}
		}
		
		//Print Content
		void print_data(void)
		{
			cout << "\nX-ptr: " << *itsX << "\nY-ptr: " << *itsY << "\n\nAddress X-ptr: " << itsX << "\n\nAddress Y-ptr: " << itsY;
		}
		//Destructor
		~check_ptr_axes ()
		{
			delete itsX;
			delete itsY;
		}
};

int main ()
{
	check_ptr_axes *ptr = new check_ptr_axes(3,5);
	ptr->print_data();
	check_ptr_axes *fptr = new check_ptr_axes(*ptr);
	fptr->print_data();
	check_ptr_axes *var;
	var = fptr;
	var->print_data();
	return 0;
}
