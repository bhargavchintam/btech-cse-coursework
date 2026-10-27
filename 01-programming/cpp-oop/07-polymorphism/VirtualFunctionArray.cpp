#include<iostream>
using namespace std;

class employee
{
    public:
        virtual void role()
        {
            cout<<"employee"<<endl;
        }
        virtual ~employee() { }
};

class manager : public employee
{
    public:
        void role()
        {
            cout<<"manager"<<endl;
        }
};

class developer : public employee
{
    public:
        void role()
        {
            cout<<"developer"<<endl;
        }
};

class tester : public employee
{
    public:
        void role()
        {
            cout<<"tester"<<endl;
        }
};

int main()
{
    employee *arr[3];
    arr[0] = new manager();
    arr[1] = new developer();
    arr[2] = new tester();

    for(int i = 0; i < 3; i++)
        arr[i]->role();

    for(int i = 0; i < 3; i++)
        delete arr[i];

    return 0;
}
