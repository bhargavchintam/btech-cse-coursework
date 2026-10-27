#include<stdio.h>

union data {
    int i;
    float f;
    char ch;
};

int main() {
    union data d;

    d.i = 65;
    printf("i = %d\n", d.i);

    d.f = 3.14;
    printf("f = %.2f\n", d.f);

    d.ch = 'A';
    printf("ch = %c\n", d.ch);

    return 0;
}
