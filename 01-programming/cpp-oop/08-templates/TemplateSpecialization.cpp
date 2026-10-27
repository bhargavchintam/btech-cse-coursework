#include<iostream>
#include<cstring>
using namespace std;

template<class T>
bool isEqual(T a, T b)
{
    return a == b;
}

// specialization for char*
template<>
bool isEqual<char*>(char *a, char *b)
{
    return strcmp(a, b) == 0;
}

int main()
{
    cout<<isEqual(5, 5)<<endl;
    cout<<isEqual(3, 7)<<endl;

    char s1[] = "hello";
    char s2[] = "hello";
    cout<<isEqual<char*>(s1, s2)<<endl;

    return 0;
}
