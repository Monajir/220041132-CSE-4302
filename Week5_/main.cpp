#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>
#include <algorithm>
#include "SavingsAccount.h"

using namespace std;

void EditInformationByKeyboard(SavingsAccount &acc) {
    string s, Address;
    double interest, balance;
    cout << "Account Name : ";
    getline(cin, s);
    acc.setAccountName(s);

    cout << "Account Holder Name : ";
    getline(cin, s);
    acc.setAccHoldName(s);

    cout << "Address : ";
    
    getline(cin, Address, '.');
    acc.setAddress(Address);

    cout << "Annual Interest Rate : ";
    cin >> interest;
    acc.setAnnIntRate(interest);

    cout << "Current Balance : ";
    cin >> balance;
    acc.setCurrentBalance(balance);
}

string generateRandomString(int length)
{
    const string CHARACTERS
        = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuv"
          "wxyz0123456789";

    random_device rd;
    mt19937 generator(rd());

    uniform_int_distribution<> distribution(
        0, CHARACTERS.size() - 1);

    string random_string;
    for (int i = 0; i < length; ++i) {
        random_string
            += CHARACTERS[distribution(generator)];
    }

    return random_string;
}

int randomLength() {
    srand(time(0));
    return rand() % 7 + 4;
}

int Random() {
    srand(time(0));
    return rand() % 10;
}

void generateInformationRandom(SavingsAccount &acc){

    string firstName;
    string lastName;
    firstName = generateRandomString(randomLength());
    lastName = generateRandomString(randomLength());

    acc.setAccountName(firstName + " " + lastName);

    firstName = generateRandomString(randomLength());
    lastName = generateRandomString(randomLength());
    acc.setAccHoldName(firstName + " " + lastName);

    string word;
    string s;
    int i = 5;
    while(i > 0) {
        word  = generateRandomString(randomLength());
        s += "\n" + word;

        i--;
    }

    acc.setAnnIntRate((rand() % 3 + 2) + .10 * Random());

    acc.setCurrentBalance(rand() % 49001 + 1000);
}

void ShowInterestAll(SavingsAccount arr[], int num) {
    int period, x;
    cout << "Period : ";
    cin >> period;

    for(int i = 0; i < num; ++i) {
        cout << "Interest amount : " << arr[i].calculateInterest(period) << endl;
        cout << "Disburse Interest ? [1 for yes and 0 for No] " << endl;
        cin >> x;

        if(x == 1) {
            arr[i].disburseInterest(period);
        }
    }
}

void ShowAllAlphabetically(SavingsAccount ar[], int size) {
    
    std::sort(ar, ar + size, [](const SavingsAccount &a, const SavingsAccount &b) {
        return a.getAccountName() < b.getAccountName();
    });

    for (int i = 0; i < size; ++i) {
        std::cout << "Account Name: " << ar[i].getAccountName() 
                  << ", Balance: $" << ar[i].getCurrentBalance() << std::endl;
    }
}

int main() {
    SavingsAccount s[2];

    EditInformationByKeyboard(s[0]);

    generateInformationRandom(s[1]);

    ShowInterestAll(s, 2);

    ShowAllAlphabetically(s, 2);
}