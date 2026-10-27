// vigenere cipher - repeating key polyalphabetic shift
#include<iostream>
#include<string>
using namespace std;

string clean(string s)
{
    string r;
    for (char c : s)
        if (isalpha(c)) r += toupper(c);
    return r;
}

string encrypt(string t, string key)
{
    string r;
    for (int i = 0; i < (int)t.size(); i++) {
        int k = key[i % key.size()] - 'A';
        r += (t[i] - 'A' + k) % 26 + 'A';
    }
    return r;
}

string decrypt(string t, string key)
{
    string r;
    for (int i = 0; i < (int)t.size(); i++) {
        int k = key[i % key.size()] - 'A';
        r += (t[i] - 'A' - k + 26) % 26 + 'A';
    }
    return r;
}

int main()
{
    string msg, key;
    cout << "Enter message: ";
    getline(cin, msg);
    cout << "Enter key: ";
    getline(cin, key);

    string t = clean(msg), k = clean(key);
    string c = encrypt(t, k);
    cout << "Encrypted: " << c << "\n";
    cout << "Decrypted: " << decrypt(c, k) << "\n";
    return 0;
}
