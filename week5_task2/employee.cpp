#include "employee.h"
#include <iostream>
#include <limits>
#include <algorithm>
#include <cctype>
#include <unordered_map>

using namespace std;

Employee::Employee() : name("John Doe"), dateOfBirth("1 January 2002"), salary(10000) {}

string Employee::getName() const {
    return name;
}

string Employee::getDateOfBirth() const {
    return dateOfBirth;
}

int Employee::getSalary() const {
    return salary;
}


void Employee::setName(const string &newName) {
    if (newName.length() > 2) {
        name = newName;
    } else {
        name = "John Doe";
    }
}

void Employee::setDateOfBirth(const string &dob) {
    
    int year = stoi(dob.substr(dob.size() - 4));
    if (year <= 2005) {
        dateOfBirth = dob;
    } else {
        dateOfBirth = "1 January 2002";
    }
}

void Employee::setSalary(int newSalary) {
    if (newSalary >= 10000 && newSalary <= 100000) {
        salary = newSalary;
    } else {
        salary = 10000;
    }
}


void Employee::setInfo() {
    string inputName, inputDOB;
    int inputSalary;

    cout << "Enter employee name: ";
    getline(cin, inputName);
    setName(inputName);

    cout << "Enter date of birth (e.g. 15 August 1990): ";
    getline(cin, inputDOB);
    setDateOfBirth(inputDOB);

    cout << "Enter salary: ";
    while (!(cin >> inputSalary)) {
        cout << "Invalid input. Please enter a valid salary: ";
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    }
    setSalary(inputSalary);

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}



void Employee::getInfo() const {
    cout << "Employee Name: " << getName() << endl;
    cout << "Date of Birth: " << getDateOfBirth() << endl;
    cout << "Salary: " << getSalary() << endl; 
}

int monthToInt(const std::string& month) {
    static const unordered_map<string, int> monthMap = {
        {"JANUARY", 1}, {"FEBRUARY", 2}, {"MARCH", 3}, {"APRIL", 4}, 
        {"MAY", 5}, {"JUNE", 6}, {"JULY", 7}, {"AUGUST", 8}, 
        {"SEPTEMBER", 9}, {"OCTOBER", 10}, {"NOVEMBER", 11}, {"DECEMBER", 12}
    };
    
    auto it = monthMap.find(month);
    if (it != monthMap.end()) {
        return it->second;
    }
    
    return -1;
}

const Employee Employee::compareAge(const Employee &e) const {
    int year1 = stoi(this->dateOfBirth.substr(this->dateOfBirth.size() - 4));
    int year2 = stoi(e.dateOfBirth.substr(e.dateOfBirth.size() - 4));

    int mon1Start = this->dateOfBirth.find(' ');
    int mon1End = this->dateOfBirth.find(' ', mon1Start + 1);

    int mon2Start = e.dateOfBirth.find(' ');
    int mon2End = e.dateOfBirth.find(' ', mon2Start + 1);

    string mon1 = (this->dateOfBirth.substr(mon1Start + 1, (mon1End - mon1Start) - 1));
    transform(mon1.begin(), mon1.end(), mon1.begin(), ::toupper);
    
    int m1 = monthToInt(mon1);

    string mon2 = (e.dateOfBirth.substr(mon2Start + 1, (mon2End - mon2Start) - 1));
    transform(mon2.begin(), mon2.end(), mon2.begin(), ::toupper);

    int m2 = monthToInt(mon2);

    int d1 = stoi(this->dateOfBirth.substr(0, 2));
    int d2 = stoi(e.dateOfBirth.substr(0, 2));

    if (year1 < year2) {
        return *this; 
    } else if(year1 > year2){
        return e; 
    }else {
        if(m1 > m2) {
            return e;
        }else if(m1 < m2) {
            return *this;
        }else {
            if(d1 > d2) {
                return e;
            }else {
                return *this;
            }
        }
    }
}
