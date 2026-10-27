// caesar cipher - shift each letter by k
#include<iostream>
#include<string>
using namespace std;

string encrypt(string s, int k)
{
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] = (s[i] - 'a' + k) % 26 + 'a';
        else if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = (s[i] - 'A' + k) % 26 + 'A';
    }
    return s;
}

string decrypt(string s, int k)
{
    return encrypt(s, 26 - k % 26);
}

int main()
{
    string msg;
    int k;
    cout << "Enter message: ";
    getline(cin, msg);
    cout << "Enter shift key: ";
    cin >> k;

    string c = encrypt(msg, k);
    cout << "Encrypted: " << c << "\n";
    cout << "Decrypted: " << decrypt(c, k) << "\n";
    return 0;
}
