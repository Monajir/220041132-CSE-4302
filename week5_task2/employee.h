#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

using namespace std;

class Employee {
private:
    string name;
    string dateOfBirth;
    int salary;

public:
    
    Employee();

    string getName() const;
    string getDateOfBirth() const;
    int getSalary() const;

    void setName(const string &name);
    void setDateOfBirth(const string &dob);
    void setSalary(int salary);

    
    void setInfo();
    void getInfo() const; 

    const Employee compareAge(const Employee &e) const;
};

#endif
