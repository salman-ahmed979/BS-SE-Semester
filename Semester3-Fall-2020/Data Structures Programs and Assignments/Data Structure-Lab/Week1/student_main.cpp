#include "student.h"
using namespace std;
int main()
{
    student *ptr = new student[5];
    for (int i=0; i<5; i++)
    {
        cout << "\nEntering data in student " << i << endl;
        ptr[i].input_data();
        fflush(stdin);
    }
    string str="", stm="";
    //Using concepts of Selection Sort Algorithm
    for (int i=0; i<5; i++)
    {
        str = ptr[i].fetch_name();
        for (int j=0; j<5; j++)
        {
            if (i!=j)
            {
                stm = ptr[j].fetch_name();
                if (str[0] > stm[0])
                    ptr[i].swap_objects(ptr[j]);
            }
        }
    }
    for (int i=0; i<5; i++)
    {
        cout << "\nPrinting data of student " << i << endl;
        ptr[i].print_data();
    }
    delete []ptr;
    return 0;
}
