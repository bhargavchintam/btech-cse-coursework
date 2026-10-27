/* Lab Program 15
   Write a C++ program to add and multiply two matrices using a class.
   g++ -std=c++14 Lab15_MatrixOperations.cpp -o lab15 */

#include<iostream>
using namespace std;

class matrix
{
    int a[3][3];
    int n;
    public:
        void setsize(int x)
        {
            n = x;
        }
        void read()
        {
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    cin>>a[i][j];
        }
        matrix add(matrix m)
        {
            matrix res;
            res.setsize(n);
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    res.a[i][j] = a[i][j] + m.a[i][j];
            return res;
        }
        matrix mul(matrix m)
        {
            matrix res;
            res.setsize(n);
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                {
                    res.a[i][j] = 0;
                    for(int k=0;k<n;k++)
                        res.a[i][j] += a[i][k] * m.a[k][j];
                }
            return res;
        }
        void show()
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                    cout<<a[i][j]<<" ";
                cout<<endl;
            }
        }
};

int main()
{
    int n;
    cout<<"Enter order of square matrix : ";
    cin>>n;

    matrix a, b;
    a.setsize(n);
    b.setsize(n);
    cout<<"Enter first matrix :"<<endl;
    a.read();
    cout<<"Enter second matrix :"<<endl;
    b.read();

    matrix s = a.add(b);
    matrix p = a.mul(b);

    cout<<"Sum :"<<endl;
    s.show();
    cout<<"Product :"<<endl;
    p.show();
    return 0;
}
