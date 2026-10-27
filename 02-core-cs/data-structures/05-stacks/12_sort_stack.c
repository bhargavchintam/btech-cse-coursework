// sort a stack using one extra stack
#include<stdio.h>
#define SIZE 100

int input[SIZE], tmp[SIZE];
int itop = -1, ttop = -1;

void ipush(int x) { input[++itop] = x; }
int ipop() { return input[itop--]; }
void tpush(int x) { tmp[++ttop] = x; }
int tpop() { return tmp[ttop--]; }

int main()
{
    int n, i, x;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &x);
        ipush(x);
    }
    while(itop != -1)
    {
        x = ipop();
        while(ttop != -1 && tmp[ttop] < x)
            ipush(tpop());
        tpush(x);
    }
    printf("Sorted: ");
    while(ttop != -1)
        printf("%d ", tpop());
    printf("\n");
    return 0;
}
