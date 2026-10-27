// Rabin-Karp - hash the pattern and roll the hash along the text
#include<iostream>
#include<string>
using namespace std;

const int d = 256;      // alphabet size
const int q = 101;      // a prime for the modulus

int main()
{
    string text, pat;
    cout << "text: ";
    cin >> text;
    cout << "pattern: ";
    cin >> pat;

    int n = text.size(), m = pat.size();
    if (m > n) {
        cout << "pattern not found\n";
        return 0;
    }

    long long h = 1;
    for (int i = 0; i < m - 1; i++)
        h = (h * d) % q;                // d^(m-1) % q

    long long p = 0, t = 0;
    for (int i = 0; i < m; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + text[i]) % q;
    }

    int found = 0;
    for (int s = 0; s <= n - m; s++) {
        if (p == t) {                   // hash hit, now confirm it is real
            int j = 0;
            while (j < m && text[s + j] == pat[j])
                j++;
            if (j == m) {
                cout << "match at index " << s << "\n";
                found++;
            }
        }
        if (s < n - m) {
            t = (d * (t - text[s] * h) + text[s + m]) % q;
            if (t < 0)
                t += q;
        }
    }
    if (!found)
        cout << "pattern not found\n";
    return 0;
}
