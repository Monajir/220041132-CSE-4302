#include "SavingsAccount.h"
#include <iostream>
#include <string>

using namespace std;

SavingsAccount::SavingsAccount() 
{
    currentBalance = 0;
    minimumBalance = 0;
}

SavingsAccount::~SavingsAccount()
{

}

void SavingsAccount::setAccountName(string s) {
    AccountName = s;
}

string SavingsAccount::getAccountName() const {
    return AccountName;
}

void SavingsAccount::setAccHoldName(string s) {
    AccountHoldersName = s;
}

string SavingsAccount::getAccHoldName() {
    return AccountHoldersName;
}

void SavingsAccount::setAddress(string s) {
    Address = s;
}

string SavingsAccount::getAddress() {
    return Address;
}

void SavingsAccount::setAnnIntRate(float value) {
    AnnInterestRate = value;
}

double SavingsAccount::getAnnIntRate() {
    return AnnInterestRate;
}

void SavingsAccount::setCurrentBalance(double value) {
    currentBalance = value;
    minimumBalance = value;
}

double SavingsAccount::getCurrentBalance() {
    return currentBalance;
}

void SavingsAccount::deposit(float value) {
    currentBalance += value;
}
void SavingsAccount::withdrawal(float value) {
    if(currentBalance < 5000) 
        return;
    currentBalance -= value;
    minimumBalance = currentBalance;
}

double SavingsAccount::calculateInterest(int periodInMonth) {
    return (minimumBalance * (AnnInterestRate / 100) * periodInMonth / 12);
}

void SavingsAccount::disburseInterest(int periodInMonth) {
    double temp = calculateInterest(periodInMonth);
    currentBalance += temp;
    minimumBalance = currentBalance;
}