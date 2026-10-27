#include<iostream>
using namespace std;

int main()
{
    int choice;
    do
    {
        cout<<"1. Say Hello"<<endl;
        cout<<"2. Say Bye"<<endl;
        cout<<"3. Exit"<<endl;
        cout<<"Enter choice : ";
        cin>>choice;

        if(choice == 1)
            cout<<"Hello"<<endl;
        else if(choice == 2)
            cout<<"Bye"<<endl;
        else if(choice == 3)
            cout<<"Exiting"<<endl;
        else
            cout<<"Wrong choice"<<endl;
    }
    while(choice != 3);
    return 0;
}
