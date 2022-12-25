#include <iostream>

#include "Polynomial.hpp"

using namespace std;


int main(){
    Polynomial a;
    a.input();
    a.print();
    Polynomial b;
    b.input();
    b.print();
    cout << a*b << endl;
    return 0;
}