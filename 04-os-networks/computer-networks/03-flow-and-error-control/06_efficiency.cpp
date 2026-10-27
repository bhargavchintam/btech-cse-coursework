// link utilisation - stop-and-wait vs sliding window for a few link speeds.
// a = Tprop / Ttrans is how many frame-times fit in the pipe one way.
#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;

double sw_eff(double a){ return 1.0 / (1.0 + 2*a); }
double slide_eff(int N, double a){ return min(1.0, N / (1.0 + 2*a)); }

int main()
{
    double tt[] = {1, 1, 1, 2};             // Ttrans
    double tp[] = {1, 5, 9, 10};            // Tprop
    int n = 4;

    cout << "utilisation: stop-and-wait vs sliding window\n\n";
    cout << fixed << setprecision(3);
    cout << "Ttrans  Tprop     a   stop-wait  slide(N=4)  slide(N=7)\n";

    for(int i = 0; i < n; i++){
        double a = tp[i] / tt[i];
        cout << setw(5) << tt[i] << setw(8) << tp[i] << setw(7) << a
             << setw(11) << sw_eff(a)
             << setw(12) << slide_eff(4, a)
             << setw(12) << slide_eff(7, a) << "\n";
    }

    cout << "\n(slide caps at 1.000 when the window is larger than 1+2a)\n";
    cout << "check: a=1 -> stop-and-wait = 1/(1+2) = " << sw_eff(1) << "\n";
    return 0;
}
