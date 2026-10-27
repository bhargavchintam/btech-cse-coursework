// channel utilisation from frame time, propagation and offered load
// a = Tp/Tf,  stop-and-wait efficiency = 1/(1+2a),  utilisation = load * efficiency
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    double tf, tp, load;
    cout << "frame transmission time Tf (ms): ";
    cin >> tf;
    cout << "propagation time Tp (ms): ";
    cin >> tp;
    cout << "offered load (0.0 - 1.0): ";
    cin >> load;

    if(tf <= 0){ cout << "Tf must be > 0\n"; return 1; }
    if(load < 0) load = 0;
    if(load > 1) load = 1;

    double a = tp / tf;
    double eff = 1.0 / (1.0 + 2*a);
    double util = load * eff;

    cout << fixed << setprecision(4);
    cout << "\na = Tp/Tf          = " << a << "\n";
    cout << "efficiency 1/(1+2a) = " << eff << "\n";
    cout << "utilisation         = " << util << "  (" << util*100 << " %)\n";
    return 0;
}
