// dynamic constructor - memory allocated at runtime

#include<iostream>
#include<cstring>
using namespace std;

class str
{
    char *name;
    public:
        str(const char *s)
        {
            name=new char[strlen(s)+1];
            strcpy(name,s);
        }
        void show()
        {
            cout<<name<<endl;
        }
        ~str()
        {
            delete[] name;
        }
};

int main()
{
    str s("REVA University");
    cout<<"Name = ";
    s.show();
    return 0;
}
