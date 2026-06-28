#include <iostream>
#include <fstream>
#include <map>
#include <stdexcept>
using namespace std;

#define MIN_BALANCE 500

class InsufficientFunds {};

class Account {
    long accountNumber{};
    string firstName, lastName;
    float balance{};
    static long NextAccountNumber;

public:
    Account() = default;

    Account(string fname, string lname, float bal)
        : firstName(fname), lastName(lname), balance(bal)
    {
        accountNumber = ++NextAccountNumber;
    }

    long getAccNo() const { return accountNumber; }
    string getFirstName() const { return firstName; }
    string getLastName() const { return lastName; }
    float getBalance() const { return balance; }

    void Deposit(float amount) { balance += amount; }

    void Withdraw(float amount) {
        if(balance - amount < MIN_BALANCE)
            throw InsufficientFunds();
        balance -= amount;
    }

    static void setLastAccountNumber(long n){ NextAccountNumber = n; }

    friend ofstream& operator<<(ofstream& ofs,const Account& acc){
        ofs<<acc.accountNumber<<"\n"
           <<acc.firstName<<"\n"
           <<acc.lastName<<"\n"
           <<acc.balance<<"\n";
        return ofs;
    }

    friend ifstream& operator>>(ifstream& ifs,Account& acc){
        ifs>>acc.accountNumber
           >>acc.firstName
           >>acc.lastName
           >>acc.balance;
        return ifs;
    }

    friend ostream& operator<<(ostream& os,const Account& acc){
        os<<"First Name: "<<acc.firstName<<"\n";
        os<<"Last Name: "<<acc.lastName<<"\n";
        os<<"Account Number: "<<acc.accountNumber<<"\n";
        os<<"Balance: "<<acc.balance<<"\n";
        return os;
    }
};

long Account::NextAccountNumber = 0;

class Bank{
    map<long,Account> accounts;

    void Save(){
        ofstream out("Bank.data",ios::trunc);
        for(auto &p:accounts)
            out<<p.second;
    }

public:
    Bank(){
        ifstream in("Bank.data");
        if(!in) return;

        Account acc;
        while(in>>acc)
            accounts[acc.getAccNo()] = acc;

        if(!accounts.empty())
            Account::setLastAccountNumber(accounts.rbegin()->first);
    }

    Account OpenAccount(string f,string l,float bal){
        if(bal<MIN_BALANCE)
            throw runtime_error("Minimum opening balance is 500.");

        Account acc(f,l,bal);
        accounts[acc.getAccNo()] = acc;
        Save();
        return acc;
    }

    Account BalanceEnquiry(long no){
        auto it=accounts.find(no);
        if(it==accounts.end())
            throw runtime_error("Account not found.");
        return it->second;
    }

    Account Deposit(long no,float amt){
        auto it=accounts.find(no);
        if(it==accounts.end())
            throw runtime_error("Account not found.");
        it->second.Deposit(amt);
        Save();
        return it->second;
    }

    Account Withdraw(long no,float amt){
        auto it=accounts.find(no);
        if(it==accounts.end())
            throw runtime_error("Account not found.");
        it->second.Withdraw(amt);
        Save();
        return it->second;
    }

    void CloseAccount(long no){
        auto it=accounts.find(no);
        if(it==accounts.end())
            throw runtime_error("Account not found.");
        cout<<"Account Deleted\n"<<it->second;
        accounts.erase(it);
        Save();
    }

    void ShowAllAccounts(){
        for(auto &p:accounts)
            cout<<p.second<<"\n";
    }
};

int main()
{
    Bank b;
    Account acc;
    int choice;
    string fname, lname;
    long accountNumber;
    float balance;
    float amount;
    cout << "***Banking System***" << endl;
    do
    {
        cout << "\n\tSelect one option below ";
        cout << "\n\t1 Open an Account";
        cout << "\n\t2 Balance Enquiry";
        cout << "\n\t3 Deposit";
        cout << "\n\t4 Withdrawal";
        cout << "\n\t5 Close an Account";
        cout << "\n\t6 Show All Accounts";
        cout << "\n\t7 Quit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter First Name: ";
            cin >> fname;
            cout << "Enter Last Name: ";
            cin >> lname;
            cout << "Enter initil Balance: ";
            cin >> balance;
            acc = b.OpenAccount(fname, lname, balance);
            cout << endl
                 << "Congradulation Account is Created" << endl;
            cout << acc;
            break;
        case 2:
            cout << "Enter Account Number:";
            cin >> accountNumber;
            acc = b.BalanceEnquiry(accountNumber);
            cout << endl
                 << "Your Account Details" << endl;
            cout << acc;
            break;
        case 3:
            cout << "Enter Account Number:";
            cin >> accountNumber;
            cout << "Enter Balance:";
            cin >> amount;
            acc = b.Deposit(accountNumber, amount);
            cout << endl
                 << "Amount is Deposited" << endl;
            cout << acc;
            break;
        case 4:
            cout << "Enter Account Number:";
            cin >> accountNumber;
            cout << "Enter Balance:";
            cin >> amount;
            acc = b.Withdraw(accountNumber, amount);
            cout << endl
                 << "Amount Withdrawn" << endl;
            cout << acc;
            break;
        case 5:
            cout << "Enter Account Number:";
            cin >> accountNumber;
            b.CloseAccount(accountNumber);
            cout << endl
                 << "Account is Closed" << endl;
            cout << acc;
        case 6:
            b.ShowAllAccounts();
            break;
        case 7:
            break;
        default:
            cout << "\nEnter corret choice";
            exit(0);
        }
    } while (choice != 7);
    return 0;
}
