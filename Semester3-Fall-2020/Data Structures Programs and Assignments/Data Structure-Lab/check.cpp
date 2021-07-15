#include<iostream>
using namespace std;
int main() {
    int a = 10;
    int *p = new int;
    *p = a;
    delete p;
    cout << sizeof(p);
    return 0;
}