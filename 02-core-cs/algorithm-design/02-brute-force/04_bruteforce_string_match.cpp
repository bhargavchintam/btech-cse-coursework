// brute force string matching - try the pattern at every shift over the text
#include<iostream>
#include<string>
using namespace std;

int main()
{
    string text, pat;
    cout << "Enter text: ";
    getline(cin, text);
    cout << "Enter pattern: ";
    getline(cin, pat);

    int n = text.size(), m = pat.size();
    int found = -1;
    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && text[i + j] == pat[j])
            j++;
        if (j == m) {
            found = i;
            break;
        }
    }

    if (found == -1)
        cout << "pattern not found\n";
    else
        cout << "pattern found at shift " << found << endl;
    return 0;
}
