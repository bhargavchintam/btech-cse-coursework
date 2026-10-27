// rtt estimation - jacobson/karels: smoothed rtt, mean deviation, and the retransmit timeout
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
    double sample[] = {100, 110, 95, 130, 90, 105, 200, 100};   // measured rtt, ms
    int n = sizeof(sample)/sizeof(sample[0]);

    double alpha = 0.125, beta = 0.25;
    double srtt = 0, devrtt = 0, rto = 0;

    printf("alpha=%.3f  beta=%.2f\n\n", alpha, beta);
    printf("sample  srtt    devrtt   rto\n");

    for(int i = 0; i < n; i++){
        double r = sample[i];
        if(i == 0){
            srtt = r;
            devrtt = r / 2;
        } else {
            devrtt = (1 - beta) * devrtt + beta * fabs(r - srtt);   // deviation uses the old srtt
            srtt   = (1 - alpha) * srtt + alpha * r;
        }
        rto = srtt + 4 * devrtt;
        printf("%5.0f  %6.2f  %6.2f  %7.2f\n", r, srtt, devrtt, rto);
    }
    return 0;
}
