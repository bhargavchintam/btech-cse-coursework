// simple calculator using switch
#include<iostream>
using namespace std;

int main()
{
    float a, b;
    char op;
    cout<<"Enter expression (a op b) : ";
    cin>>a>>op>>b;

    switch(op)
    {
        case '+': cout<<"Result = "<<a+b<<endl; break;
        case '-': cout<<"Result = "<<a-b<<endl; break;
        case '*': cout<<"Result = "<<a*b<<endl; break;
        case '/':
            if(b != 0)
                cout<<"Result = "<<a/b<<endl;
            else
                cout<<"Division by zero"<<endl;
            break;
        default: cout<<"Invalid operator"<<endl;
    }
    return 0;
}
