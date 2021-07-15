#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
using namespace std;

class student
{
    public:
        student();
        virtual ~student();
        void input_data(void);
        void print_data(void);
        string fetch_name(void);
        void swap_objects(student &s1);


    protected:

    private:
        string name, depart;
        int rollno;

};

#endif // STUDENT_H
