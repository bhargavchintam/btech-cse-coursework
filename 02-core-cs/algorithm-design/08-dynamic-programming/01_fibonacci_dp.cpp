// fibonacci - bottom up table and memoized
#include<iostream>
#include<vector>
using namespace std;

long long memo[100];

long long fibmemo(int n)
{
    if(n <= 1)
        return n;
    if(memo[n] != -1)
        return memo[n];
    memo[n] = fibmemo(n-1) + fibmemo(n-2);
    return memo[n];
}

long long fibtable(int n)
{
    vector<long long> f(n+1);
    f[0] = 0;
    if(n >= 1)
        f[1] = 1;
    for(int i = 2; i <= n; i++)
        f[i] = f[i-1] + f[i-2];
    return f[n];
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    for(int i = 0; i < 100; i++)
        memo[i] = -1;

    cout << "bottom-up  fib(" << n << ") = " << fibtable(n) << endl;
    cout << "memoized   fib(" << n << ") = " << fibmemo(n) << endl;
    return 0;
}
