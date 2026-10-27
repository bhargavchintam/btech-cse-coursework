/* Bindu Bhargava  05-09-19 */
// lab 3 - CRC generation and checking
// append (generator length - 1) zeros to the data and do XOR long division by the
// generator. the remainder is the CRC that gets sent with the data. the receiver
// divides the whole codeword again - a zero remainder means no error was found.
#include<iostream>
#include<string>
using namespace std;

string crc(string data, const string &gen)
{
    int n = gen.size();
    string cur = data.substr(0, n);
    int i = n;
    while(true){
        if(cur[0] == '1')
            for(int j = 0; j < n; j++)
                cur[j] = (cur[j] == gen[j]) ? '0' : '1';   // XOR the generator in
        cur = cur.substr(1);
        if(i < (int)data.size()) cur += data[i++];
        else break;
    }
    return cur;
}

int main()
{
    string data, gen;
    cout << "data bits: ";
    cin >> data;
    cout << "generator: ";
    cin >> gen;

    string rem = crc(data + string(gen.size() - 1, '0'), gen);
    string codeword = data + rem;
    cout << "crc      = " << rem << "\n";
    cout << "codeword = " << codeword << "\n";

    string check = crc(codeword, gen);
    cout << "receiver remainder = " << check << "\n";
    cout << (check.find('1') == string::npos ? "no error detected" : "error detected") << "\n";
    return 0;
}
