#include "employee.h"
#include <iostream>

using namespace std;

int main() {
    Employee emp1, emp2;

    cout << "Enter details for Employee 1:\n";
    emp1.setInfo();

    cout << "\nEnter details for Employee 2:\n";
    emp2.setInfo();

    cout << "\nEmployee 1 Information:\n";
    emp1.getInfo();

    cout << "\nEmployee 2 Information:\n";
    emp2.getInfo();

    Employee elder = emp1.compareAge(emp2);
    cout << "\nThe elder employee is:\n";
    elder.getInfo();

    return 0;
}
