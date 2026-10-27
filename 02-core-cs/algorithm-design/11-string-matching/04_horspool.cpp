// Horspool - shift table on the last-aligned character, compare right to left
#include<iostream>
#include<string>
using namespace std;

int main()
{
    string text, pat;
    cout << "text = ";
    cin >> text;
    cout << "pattern = ";
    cin >> pat;

    int n = text.size(), m = pat.size();

    int shift[256];
    for (int c = 0; c < 256; c++)
        shift[c] = m;
    for (int j = 0; j < m - 1; j++)
        shift[(unsigned char)pat[j]] = m - 1 - j;

    int found = 0;
    int i = m - 1;
    while (i <= n - 1) {
        int k = 0;
        while (k < m && pat[m - 1 - k] == text[i - k])
            k++;
        if (k == m) {
            cout << "match at index " << i - m + 1 << "\n";
            found++;
        }
        i += shift[(unsigned char)text[i]];
    }
    if (!found)
        cout << "pattern not found\n";
    return 0;
}
