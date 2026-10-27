// matrix class - addition, multiplication and transpose
#include<iostream>
using namespace std;

const int MAX=10;

class matrix
{
    int r,c;
    int a[MAX][MAX];
public:
    matrix()
    {
        r=0;
        c=0;
    }
    void setsize(int row,int col)
    {
        r=row;
        c=col;
    }
    void read()
    {
        cout<<"enter "<<r*c<<" elements row by row :"<<endl;
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                cin>>a[i][j];
    }
    void display()
    {
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
                cout<<a[i][j]<<"\t";
            cout<<endl;
        }
    }
    matrix operator+(matrix m)
    {
        matrix t;
        t.setsize(r,c);
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                t.a[i][j]=a[i][j]+m.a[i][j];
        return t;
    }
    matrix operator*(matrix m)
    {
        matrix t;
        t.setsize(r,m.c);
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<m.c;j++)
            {
                t.a[i][j]=0;
                for(int k=0;k<c;k++)
                    t.a[i][j]=t.a[i][j]+a[i][k]*m.a[k][j];
            }
        }
        return t;
    }
    matrix transpose()
    {
        matrix t;
        t.setsize(c,r);
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                t.a[j][i]=a[i][j];
        return t;
    }
};

int main()
{
    int n;
    cout<<"enter order of square matrices : ";
    cin>>n;

    matrix m1,m2;
    m1.setsize(n,n);
    m2.setsize(n,n);

    cout<<"matrix 1 :"<<endl;
    m1.read();
    cout<<"matrix 2 :"<<endl;
    m2.read();

    matrix sum = m1+m2;
    matrix prod = m1*m2;
    matrix tr = m1.transpose();

    cout<<"\nsum :"<<endl;
    sum.display();
    cout<<"\nproduct :"<<endl;
    prod.display();
    cout<<"\ntranspose of matrix 1 :"<<endl;
    tr.display();

    return 0;
}
