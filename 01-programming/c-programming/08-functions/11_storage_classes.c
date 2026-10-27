#include<stdio.h>

int g = 10;

void demo() {
    auto int a = 1;
    register int r = 2;
    static int s = 0;
    extern int g;
    s++;
    printf("a = %d  r = %d  s = %d  g = %d\n", a, r, s, g);
}

int main() {
    demo();
    demo();
    demo();
    return 0;
}
