#ifndef H_BankStackType
#define H_BankStackType

#include <iostream>
#include <cassert>
#include "BankStackADT.h"

using namespace std;

template <class Type>
class BankStackType : public BankStackADT<Type> {
public:
    const BankStackType<Type>& operator=(const BankStackType<Type>& otherBankStack);
    void initializeBankStack();
    bool isBankStackEmpty() const;
    bool isBankStackFull() const;
    void pushToBankStack(const Type& transaction);
    Type viewTopTransaction() const;
    void removeTopTransaction();

    BankStackType(int stackSize = 100);
    BankStackType(const BankStackType<Type>& otherBankStack);
    ~BankStackType();

private:
    int maxStackSize;
    int stackTop;
    Type *transactionArray;

    void copyBankStack(const BankStackType<Type>& otherBankStack);
};

template <class Type>
void BankStackType<Type>::initializeBankStack() {
    stackTop = 0;
}

template <class Type>
bool BankStackType<Type>::isBankStackEmpty() const {
    return (stackTop == 0);
}

template <class Type>
bool BankStackType<Type>::isBankStackFull() const {
    return (stackTop == maxStackSize);
}

template <class Type>
void BankStackType<Type>::pushToBankStack(const Type& transaction) {
    if (!isBankStackFull()) {
        transactionArray[stackTop] = transaction;
        stackTop++;
    } else {
        cout << "Transaction stack is full. Cannot add more transactions." << endl;
    }
}

template <class Type>
Type BankStackType<Type>::viewTopTransaction() const {
    assert(stackTop > 0);
    return transactionArray[stackTop - 1];
}

template <class Type>
void BankStackType<Type>::removeTopTransaction() {
    if (!isBankStackEmpty()) {
        stackTop--;
    } else {
        cout << "Transaction stack is empty. Cannot remove transactions." << endl;
    }
}

template <class Type>
BankStackType<Type>::BankStackType(int stackSize) {
    if (stackSize <= 0) {
        cout << "Transaction stack size must be positive. Defaulting to 100." << endl;
        maxStackSize = 100;
    } else {
        maxStackSize = stackSize;
    }
    stackTop = 0;
    transactionArray = new Type[maxStackSize];
}

template <class Type>
BankStackType<Type>::~BankStackType() {
    delete [] transactionArray;
}

template <class Type>
void BankStackType<Type>::copyBankStack(const BankStackType<Type>& otherBankStack) {
    delete [] transactionArray;
    maxStackSize = otherBankStack.maxStackSize;
    stackTop = otherBankStack.stackTop;
    transactionArray = new Type[maxStackSize];
    for (int i = 0; i < stackTop; i++) {
        transactionArray[i] = otherBankStack.transactionArray[i];
    }
}

template <class Type>
const BankStackType<Type>& BankStackType<Type>::operator=(const BankStackType<Type>& otherBankStack) {
    if (this != &otherBankStack) {
        copyBankStack(otherBankStack);
    }
    return *this;
}

#endif
