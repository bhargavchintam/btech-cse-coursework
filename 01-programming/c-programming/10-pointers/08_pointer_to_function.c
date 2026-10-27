// calculator using function pointers
#include<stdio.h>

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
int divide(int a, int b) { return a / b; }

int main()
{
    int (*op[4])(int, int) = {add, sub, mul, divide};
    int a, b, ch;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    printf("0.add  1.sub  2.mul  3.div\n");
    printf("Enter choice: ");
    scanf("%d", &ch);
    printf("Result = %d\n", op[ch](a, b));
    return 0;
}
