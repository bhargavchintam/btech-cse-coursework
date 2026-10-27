// Boyer-Moore, bad-symbol (bad character) heuristic, scanning right to left
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

    int last[256];
    for (int c = 0; c < 256; c++)
        last[c] = -1;                   // character not in pattern
    for (int j = 0; j < m; j++)
        last[(unsigned char)pat[j]] = j;

    int found = 0;
    int i = 0;
    while (i <= n - m) {
        int j = m - 1;
        while (j >= 0 && pat[j] == text[i + j])
            j--;
        if (j < 0) {
            cout << "match at index " << i << "\n";
            found++;
            i++;
        } else {
            int step = j - last[(unsigned char)text[i + j]];
            i += (step > 0 ? step : 1);
        }
    }
    if (!found)
        cout << "pattern not found\n";
    return 0;
}
