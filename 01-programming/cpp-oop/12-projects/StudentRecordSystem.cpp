// student record system - menu driven using class and vector
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class student
{
    int rollno;
    string name;
    float marks;
public:
    void input()
    {
        cout<<"enter rollno : ";
        cin>>rollno;
        cin.ignore();
        cout<<"enter name : ";
        getline(cin,name);
        cout<<"enter marks : ";
        cin>>marks;
    }
    void display()
    {
        cout<<rollno<<"\t"<<name<<"\t"<<marks<<endl;
    }
    int getroll()
    {
        return rollno;
    }
};

int main()
{
    vector<student> list;
    int ch;

    while(1)
    {
        cout<<"\n--- student record system ---"<<endl;
        cout<<"1. add student"<<endl;
        cout<<"2. display all"<<endl;
        cout<<"3. search by rollno"<<endl;
        cout<<"4. delete by rollno"<<endl;
        cout<<"5. exit"<<endl;
        cout<<"enter choice : ";
        cin>>ch;

        switch(ch)
        {
            case 1:
            {
                student s;
                s.input();
                list.push_back(s);
                cout<<"student added"<<endl;
                break;
            }
            case 2:
            {
                if(list.empty())
                {
                    cout<<"no records"<<endl;
                    break;
                }
                cout<<"roll\tname\tmarks"<<endl;
                for(int i=0;i<(int)list.size();i++)
                    list[i].display();
                break;
            }
            case 3:
            {
                int r;
                cout<<"enter rollno to search : ";
                cin>>r;
                int found=0;
                for(int i=0;i<(int)list.size();i++)
                {
                    if(list[i].getroll()==r)
                    {
                        list[i].display();
                        found=1;
                        break;
                    }
                }
                if(!found)
                    cout<<"not found"<<endl;
                break;
            }
            case 4:
            {
                int r;
                cout<<"enter rollno to delete : ";
                cin>>r;
                int found=0;
                for(int i=0;i<(int)list.size();i++)
                {
                    if(list[i].getroll()==r)
                    {
                        list.erase(list.begin()+i);
                        found=1;
                        cout<<"deleted"<<endl;
                        break;
                    }
                }
                if(!found)
                    cout<<"not found"<<endl;
                break;
            }
            case 5:
                cout<<"bye"<<endl;
                return 0;
            default:
                cout<<"wrong choice"<<endl;
        }
    }
    return 0;
}
