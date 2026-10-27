// lab 2 - character (byte) stuffing and de-stuffing
// the frame is DLE STX <data> DLE ETX. if the data itself contains DLE we double
// it (DLE -> DLE DLE) so the closing DLE ETX is not read too early. receiver
// drops the framing and collapses the doubled DLEs.
#include<iostream>
#include<string>
using namespace std;

int main()
{
    string data;
    cout << "enter data: ";
    getline(cin, data);

    string stuffed;
    for(size_t i = 0; i < data.size(); ){
        if(data.compare(i, 3, "DLE") == 0){ stuffed += "DLEDLE"; i += 3; }
        else { stuffed += data[i]; i++; }
    }

    string frame = "DLESTX" + stuffed + "DLEETX";
    cout << "framed: " << frame << "\n";

    string body = frame.substr(6, frame.size() - 12);   // drop DLESTX and DLEETX
    string out;
    for(size_t i = 0; i < body.size(); ){
        if(body.compare(i, 6, "DLEDLE") == 0){ out += "DLE"; i += 6; }
        else { out += body[i]; i++; }
    }
    cout << "recovered: " << out << "\n";
    return 0;
}
