// pure ALOHA throughput  S = G * e^(-2G),  peak 1/(2e) ~ 0.184 at G=0.5
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
    cout << fixed << setprecision(4);
    cout << "  G       S = G*e^(-2G)\n";
    cout << "-----------------------\n";

    double bestG = 0, bestS = 0;
    for(double G = 0.1; G <= 2.0001; G += 0.1){
        double S = G * exp(-2*G);
        cout << setw(5) << G << "     " << S << "\n";
        if(S > bestS){ bestS = S; bestG = G; }
    }

    cout << "\nmax throughput " << bestS << " at G = " << bestG << "\n";
    cout << "theory: 1/(2e) = " << 1.0/(2*M_E) << " at G = 0.5\n";
    return 0;
}
