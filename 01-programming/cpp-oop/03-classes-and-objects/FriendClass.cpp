// friend class

#include<iostream>
using namespace std;

class account
{
    int balance;
    public:
        void setbalance(int b)
        {
            balance=b;
        }
        friend class manager;
};

class manager
{
    public:
        void show(account a)
        {
            cout<<"Balance = "<<a.balance<<endl;
        }
};

int main()
{
    account a;
    a.setbalance(5000);
    manager m;
    m.show(a);
    return 0;
}
