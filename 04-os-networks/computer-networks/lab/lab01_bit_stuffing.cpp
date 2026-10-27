/* Bindu Bhargava  22-08-19 */
// lab 1 - bit stuffing and de-stuffing
// the frame delimiter is the flag 01111110. after five 1s in a row inside the
// data we stuff a 0 so the flag can never appear by accident. the receiver
// strips the flags and removes the stuffed 0 to get the original bits back.
#include<iostream>
#include<string>
using namespace std;

int main()
{
    string data;
    cout << "enter bit string: ";
    cin >> data;

    string flag = "01111110";
    string stuffed;
    int ones = 0;
    for(char c : data){
        stuffed += c;
        if(c == '1'){
            ones++;
            if(ones == 5){ stuffed += '0'; ones = 0; }
        } else ones = 0;
    }
    cout << "stuffed frame: " << flag << stuffed << flag << "\n";

    string out;
    ones = 0;
    for(size_t i = 0; i < stuffed.size(); i++){
        out += stuffed[i];
        if(stuffed[i] == '1'){
            ones++;
            if(ones == 5){ i++; ones = 0; }   // skip the stuffed 0
        } else ones = 0;
    }
    cout << "recovered:     " << out << "\n";
    return 0;
}
