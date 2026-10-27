// brute force string matching - try the pattern at every shift
#include<iostream>
#include<string>
using namespace std;

int main()
{
    string text, pat;
    cout << "Enter text: ";
    cin >> text;
    cout << "Enter pattern: ";
    cin >> pat;

    int n = text.size(), m = pat.size();
    int found = 0;
    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && text[i + j] == pat[j])
            j++;
        if (j == m) {
            cout << "match at index " << i << "\n";
            found++;
        }
    }
    if (!found)
        cout << "pattern not found\n";
    return 0;
}
