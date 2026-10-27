// library management - issue and return books
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class book
{
    int id;
    string title;
    string author;
    int issued;   // 0 = available, 1 = issued
public:
    void input()
    {
        cout<<"enter book id : ";
        cin>>id;
        cin.ignore();
        cout<<"enter title : ";
        getline(cin,title);
        cout<<"enter author : ";
        getline(cin,author);
        issued=0;
    }
    void display()
    {
        cout<<id<<"\t"<<title<<"\t"<<author<<"\t";
        if(issued)
            cout<<"issued"<<endl;
        else
            cout<<"available"<<endl;
    }
    int getid()
    {
        return id;
    }
    void issue()
    {
        if(issued)
            cout<<"already issued"<<endl;
        else
        {
            issued=1;
            cout<<"book issued"<<endl;
        }
    }
    void giveback()
    {
        if(issued)
        {
            issued=0;
            cout<<"book returned"<<endl;
        }
        else
            cout<<"book was not issued"<<endl;
    }
};

int main()
{
    vector<book> lib;
    int ch;

    while(1)
    {
        cout<<"\n--- library management ---"<<endl;
        cout<<"1. add book"<<endl;
        cout<<"2. display all"<<endl;
        cout<<"3. issue book"<<endl;
        cout<<"4. return book"<<endl;
        cout<<"5. exit"<<endl;
        cout<<"enter choice : ";
        cin>>ch;

        if(ch==1)
        {
            book b;
            b.input();
            lib.push_back(b);
        }
        else if(ch==2)
        {
            if(lib.empty())
                cout<<"no books"<<endl;
            else
            {
                cout<<"id\ttitle\tauthor\tstatus"<<endl;
                for(int i=0;i<(int)lib.size();i++)
                    lib[i].display();
            }
        }
        else if(ch==3)
        {
            int id;
            cout<<"enter book id to issue : ";
            cin>>id;
            int found=0;
            for(int i=0;i<(int)lib.size();i++)
            {
                if(lib[i].getid()==id)
                {
                    lib[i].issue();
                    found=1;
                    break;
                }
            }
            if(!found)
                cout<<"book not found"<<endl;
        }
        else if(ch==4)
        {
            int id;
            cout<<"enter book id to return : ";
            cin>>id;
            int found=0;
            for(int i=0;i<(int)lib.size();i++)
            {
                if(lib[i].getid()==id)
                {
                    lib[i].giveback();
                    found=1;
                    break;
                }
            }
            if(!found)
                cout<<"book not found"<<endl;
        }
        else if(ch==5)
            return 0;
        else
            cout<<"wrong choice"<<endl;
    }
    return 0;
}
