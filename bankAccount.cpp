#include<bits/stdc++.h>
using namespace std;

class BankAccount
{
public:
    string account_holder;
    string account_holder_address;
    int age;
    int account_number;
protected:
    int balance;
private:
    string password;

public:
    BankAccount(string account_holder, string account_holder_address, int age, string password)
    {
        this -> account_holder = account_holder;
        this -> account_holder_address = account_holder_address;
        this -> age = age;
        this -> password = password;
        this -> account_number = rand()%1000000000; // random create of account number
        this -> balance = 0;

        cout<<"A/C Number: "<<this->account_number<<endl;
    }
    int show_balance(string pass)
    {
        if(this->password == pass)
        {
            return balance;
        }
        else
        {
            return -1;
        }
    }
    void add_money(string pass, int amount)
    {
        if(this->password == pass)
        {
            this->balance += amount;
            cout<<"Balance added successfully."<<endl;
        }
        else
        {
            cout<<"password didn't matched"<<endl;

        }
    }
    void deposit_money(string pass, int amount)
    {
        if(this->balance < amount)
        {
            cout<<"Insufficient Balance."<<endl;
            return;
        }
        if(amount < 0)
        {
            cout<<"Invalid Balance"<<endl;
            return;
        }
        if(this->password == pass)
        {
            this->balance -= amount;
            cout<<"Deposit successfully."<<endl;
        }
        else
        {
            cout<<"password didn't matched"<<endl;
        }
    }
    friend class MyCash;
};

class MyCash
{
protected:
    int balance;
public:
    MyCash()
    {
        this->balance = 0;
    }
    void add_money_from_bank(BankAccount *myAccount, string pass, int amount)
    {
        if(myAccount->balance < amount)
        {
            cout<<"Insufficient Balance."<<endl;
            return;
        }
        if(amount < 0)
        {
            cout<<"Invalid Balance"<<endl;
            return;
        }
        if(myAccount->password == pass)
        {
            this->balance += amount;
            myAccount->balance -= amount;
            cout<<"balance added successfully"<<endl;
        }
        else
        {
            cout<<"password didn't matched"<<endl;
        }
    }
    int show_balance(BankAccount *myAccount, string pass)
    {
        if(myAccount->password == pass)
        {
            return balance;
        }
        else
        {
            return -1;
        }
    }
};

BankAccount* create_account()
{
    string name, address, pass;
    int age;
    cout<<"<<== Create A/C ==>>"<<endl;
    cout<<"Enter account holder name: ";
    cin>>name;
    cout<<"Enter her address: ";
    cin>>address;
    cout<<"Enter her age: ";
    cin>>age;
    cout<<"Enter password: ";
    cin>>pass;
    BankAccount *myAccount = new BankAccount(name, address, age, pass);
    return myAccount;
}

void add_money(BankAccount *myAccount)
{

    string pass;
    int amount;
    cout<<"Add Money:"<<endl;
    cout<<"Enter your password & amount: "<<endl;
    cin>>pass>>amount;
    myAccount-> add_money(pass, amount);
    cout<<"Balance: "<<myAccount->show_balance(pass)<<endl;
}

void deposit_money(BankAccount *myAccount)
{

    string pass;
    int amount;
    cout<<"Deposit Money:"<<endl;
     cout<<"Enter your password & amount: "<<endl;
    cin>>pass>>amount;
    myAccount->deposit_money(pass, amount);
    cout<<"Balance: "<<myAccount->show_balance(pass)<<endl;
}

void add_money_form_bank(MyCash *myCash, BankAccount *myAccount)
{

    string pass;
    int amount;
    cout<<"Add money from bank:"<<endl;
    cout<<"Enter your password & amount: "<<endl;
    cin>>pass>>amount;
    myCash->add_money_from_bank(myAccount, pass, amount);
    cout<<"Bank Balance: "<<myAccount->show_balance(pass)<<endl;
    cout<<"MyCash Balance: "<<myCash->show_balance(myAccount, pass)<<endl;
}
int main()
{
    BankAccount *myAccount = create_account();
    MyCash *myCash = new MyCash();
Flag:
    cout<<"Select Option:"<<endl;
    cout<<"1. Add Money"<<endl;
    cout<<"2. Deposit Money"<<endl;
    cout<<"3. Add Money From Bank"<<endl;
    int option;
    cin>>option;
    if(option == 1)
    {
        add_money(myAccount);
    }
    else if(option == 2)
    {
        deposit_money(myAccount);
    }
    else if(option == 3)
    {
        add_money_form_bank(myCash, myAccount);
    }
    else
    {
        cout<<"Invalid Code."<<endl;
    }
    goto Flag;


    //cout<<"Balance: "<<myAccount->show_balance("332")<<endl;
    /*
    if(myAccount->show_balance("332") == -1)
    {
        cout<<"Password didn't match!"<<endl;
    }
    else
    {
        cout<<"Balance: "<<myAccount->show_balance("332");
    }
    */
    return 0;
}
