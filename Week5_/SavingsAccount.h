#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#pragma once
#include <string>

using namespace std;

class SavingsAccount
{
public:
    SavingsAccount();
    ~SavingsAccount();

    void setAccountName(string s);
    string getAccountName() const;
    void setAccHoldName(string s);
    string getAccHoldName();
    void setAddress(string s);
    string getAddress();
    void setAnnIntRate(float value);
    double getAnnIntRate();
    void setCurrentBalance(double value);
    double getCurrentBalance();

    void deposit(float value);
    void withdrawal(float value);
    double calculateInterest(int periodInMonth);
    void disburseInterest(int periodInMonth);
private:
    string AccountName;
    string AccountHoldersName;
    string Address;
    double AnnInterestRate;
    double currentBalance;
    double minimumBalance;
};

#endif