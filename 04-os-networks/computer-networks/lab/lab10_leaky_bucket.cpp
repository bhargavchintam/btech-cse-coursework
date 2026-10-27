// lab 10 - leaky bucket algorithm
// packets pour into a fixed size bucket and leak out at a constant rate every
// tick. whatever arrives while the bucket is already full spills over and is
// dropped, so the output to the network stays smooth.
#include<iostream>
using namespace std;

int main()
{
    int cap, rate, ticks;
    cout << "bucket capacity: ";
    cin >> cap;
    cout << "leak rate per tick: ";
    cin >> rate;
    cout << "number of ticks: ";
    cin >> ticks;

    int bucket = 0;
    for(int t = 1; t <= ticks; t++){
        int in;
        cout << "packets arriving at tick " << t << ": ";
        cin >> in;

        if(bucket + in > cap){
            cout << "   full, dropping " << (bucket + in - cap) << "\n";
            bucket = cap;
        } else bucket += in;

        int out = (bucket < rate) ? bucket : rate;
        bucket -= out;
        cout << "   sent " << out << ", " << bucket << " left in bucket\n";
    }
    return 0;
}
