// banking system - deposit, withdraw with overdraft check
#include<iostream>
#include<string>
using namespace std;

class account
{
    int accno;
    string name;
    double bal;
public:
    void open()
    {
        cout<<"enter account number : ";
        cin>>accno;
        cin.ignore();
        cout<<"enter name : ";
        getline(cin,name);
        cout<<"enter opening balance : ";
        cin>>bal;
    }
    void deposit()
    {
        double amt;
        cout<<"enter amount to deposit : ";
        cin>>amt;
        if(amt<=0)
        {
            cout<<"invalid amount"<<endl;
            return;
        }
        bal=bal+amt;
        cout<<"deposited. balance = "<<bal<<endl;
    }
    void withdraw()
    {
        double amt;
        cout<<"enter amount to withdraw : ";
        cin>>amt;
        if(amt>bal)
        {
            cout<<"insufficient balance"<<endl;   // overdraft not allowed
            return;
        }
        bal=bal-amt;
        cout<<"withdrawn. balance = "<<bal<<endl;
    }
    void display()
    {
        cout<<"account : "<<accno<<endl;
        cout<<"name : "<<name<<endl;
        cout<<"balance : "<<bal<<endl;
    }
};

int main()
{
    account a;
    a.open();
    int ch;

    while(1)
    {
        cout<<"\n1. deposit"<<endl;
        cout<<"2. withdraw"<<endl;
        cout<<"3. balance"<<endl;
        cout<<"4. exit"<<endl;
        cout<<"enter choice : ";
        cin>>ch;

        switch(ch)
        {
            case 1:
                a.deposit();
                break;
            case 2:
                a.withdraw();
                break;
            case 3:
                a.display();
                break;
            case 4:
                return 0;
            default:
                cout<<"wrong choice"<<endl;
        }
    }
    return 0;
}
