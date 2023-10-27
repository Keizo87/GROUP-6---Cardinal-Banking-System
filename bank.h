#ifndef BANK_H
#define BANK_H

#include "account.h"
#include "transaction.h"
#include "myLinkedList.h"
#include "myStack.h"
#include <vector>
#include <map>

class Bank {
private:
    std::map<std::string, Account> accounts;
    Stack<Transaction*> transactionStack;

public:
    void openAccount(const std::string& accNumber, const std::string& accName, double initialBalance, const std::string& pin) {
        Account newAccount(accNumber, accName, initialBalance, pin);
        accounts[accNumber] = newAccount;
    }

    void closeAccount(const std::string& accNumber) {
        auto account = accounts.find(accNumber);
        if (account != accounts.end()) {
            accounts.erase(account);
        }
    }

    Account* findAccount(const std::string& accNumber) {
        auto account = accounts.find(accNumber);
        if (account != accounts.end()) {
            return &account->second;
        }
        return nullptr;
    }

    void processDeposit(Account& account, double amount) {
        DepositTransaction* depositTransaction = new DepositTransaction(amount, account.getAccountNumber());
        depositTransaction->execute(account);
        transactionStack.push(depositTransaction);
    }

    void processWithdrawal(Account& account, double amount) {
        WithdrawalTransaction* withdrawalTransaction = new WithdrawalTransaction(amount, account.getAccountNumber());
        withdrawalTransaction->execute(account);
        transactionStack.push(withdrawalTransaction);
    }

    void undoLastTransaction() {
        if (!transactionStack.isEmpty()) {
            Transaction* lastTransaction = transactionStack.pop();
            lastTransaction->undo(accounts[lastTransaction->getAccountNumber()]);
            delete lastTransaction;
        }
    }
};

#endif
