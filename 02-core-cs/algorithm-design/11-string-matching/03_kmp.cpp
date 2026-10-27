// KMP - build the prefix (failure) function, then scan without backing up in the text
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
    string text, pat;
    cout << "Enter text: ";
    cin >> text;
    cout << "Enter pattern: ";
    cin >> pat;

    int n = text.size(), m = pat.size();
    vector<int> pi(m, 0);
    int k = 0;
    for (int i = 1; i < m; i++) {
        while (k > 0 && pat[i] != pat[k])
            k = pi[k - 1];
        if (pat[i] == pat[k])
            k++;
        pi[i] = k;
    }

    int found = 0, q = 0;
    for (int i = 0; i < n; i++) {
        while (q > 0 && text[i] != pat[q])
            q = pi[q - 1];
        if (text[i] == pat[q])
            q++;
        if (q == m) {
            cout << "match at index " << i - m + 1 << "\n";
            found++;
            q = pi[q - 1];
        }
    }
    if (!found)
        cout << "pattern not found\n";
    return 0;
}
