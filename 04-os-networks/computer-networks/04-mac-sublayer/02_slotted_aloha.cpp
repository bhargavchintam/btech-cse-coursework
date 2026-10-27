// slotted ALOHA throughput  S = G * e^(-G),  peak 1/e ~ 0.368 at G=1
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
    cout << fixed << setprecision(4);
    cout << "  G       S = G*e^(-G)\n";
    cout << "----------------------\n";

    double bestG = 0, bestS = 0;
    for(double G = 0.1; G <= 2.0001; G += 0.1){
        double S = G * exp(-G);
        cout << setw(5) << G << "     " << S << "\n";
        if(S > bestS){ bestS = S; bestG = G; }
    }

    cout << "\nmax throughput " << bestS << " at G = " << bestG << "\n";
    cout << "theory: 1/e = " << 1.0/M_E << " at G = 1\n";
    return 0;
}
