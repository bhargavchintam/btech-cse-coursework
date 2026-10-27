/* Bindu Bhargava   14-01-19 */
// sum 1..n by a loop - the addition runs exactly n times, so Theta(n)
#include<iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    long long sum = 0, count = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
        count++;                       // count the basic operation
    }

    cout << "Sum = " << sum << endl;
    cout << "additions performed = " << count << endl;
    cout << "n(n+1)/2 formula    = " << (long long)n * (n + 1) / 2 << endl;
    cout << "operation count is n => this loop is Theta(n)\n";
    return 0;
}
