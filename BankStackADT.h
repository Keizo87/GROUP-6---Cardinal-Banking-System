#ifndef H_BankStackADT
#define H_BankStackADT

template <class Type>
class BankStackADT {
public:
    virtual void initializeBankStack() = 0;
    virtual bool isBankStackEmpty() const = 0;
    virtual bool isBankStackFull() const = 0;
    virtual void pushToBankStack(const Type& transaction) = 0;
    virtual Type viewTopTransaction() const = 0;
    virtual void removeTopTransaction() = 0;
};

#endif
