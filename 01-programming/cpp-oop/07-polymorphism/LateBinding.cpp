#include<iostream>
using namespace std;

class animal
{
    public:
        virtual void sound()
        {
            cout<<"some sound"<<endl;
        }
};

class dog : public animal
{
    public:
        void sound()
        {
            cout<<"dog barks"<<endl;
        }
};

class cat : public animal
{
    public:
        void sound()
        {
            cout<<"cat meows"<<endl;
        }
};

int main()
{
    animal *a;
    dog d;
    cat c;

    a = &d;
    a->sound();

    a = &c;
    a->sound();     // late binding decides at run time

    return 0;
}
