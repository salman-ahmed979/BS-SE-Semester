#include "Ordered_DSA.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) 
{
	/* Car Class
	Car c1;
	c1.set_data();
	Car c2(c1);
	Car c3 = c2;
	cout << "\nPrinting Data of Object 2\n";
	c2.print_data();
	cout << "\nPrinting Data of Object 3\n";
	c3.print_data();
	*/
	
	/* UnOrdered Class DSA
	UnOrdered_DSA d1(4);
	for(int i=0; i<4; i++)
		d1.insertion();
	cout << "\nOut of for loop\n";
	d1.insertion();
	
	d1.print_data();
	
	d1.searching();
	*/
	
	//Ordered Class DSA
	Ordered_DSA d1(4);
	for(int i=0; i<4; i++)
		d1.insertion();
	cout << "\nOut of for loop\n";
	d1.insertion();
	
	d1.print_data();
	
	d1.searching();
	return 0;
}
