#include "bankAccount.h"

bankAccount::bankAccount()
{
    balance = 0.0;
}

bankAccount::bankAccount(double amount)
{
    balance = amount;
}

bankAccount::~bankAccount()
{}

double bankAccount::withdraw(double amount)
{
    if (amount <= balance)
        balance -= amount;
    
    return balance; 
}

double bankAccount::deposit(double amount)
{
    balance += amount;
    
    return balance; 
}

double bankAccount::getBalance()
{
    return balance;
}

