#include<stdio.h>

/* 0-address evaluation of X = (A+B)*(C-D), RPN: AB+CD-* */

int stk[10];
int sp = 0;

void push(int v)
{
    stk[sp++] = v;
}

int pop()
{
    return stk[--sp];
}

void show(char *instr)
{
    int i;
    printf("%-10s", instr);
    if(sp == 0)
        printf(" (empty)");
    for(i = 0; i < sp; i++)
        printf(" %d", stk[i]);
    /* printf("  sp=%d", sp); */
    printf("\n");
}

int main()
{
    int a = 8, b = 5, c = 9, d = 3, x, t;

    printf("A=%d B=%d C=%d D=%d, X = (A+B)*(C-D)\n\n", a, b, c, d);
    printf("%-10s %s\n", "instr", "stack (top at right)");

    push(a);            show("PUSH A");
    push(b);            show("PUSH B");
    t = pop(); push(pop() + t);  show("ADD");
    push(c);            show("PUSH C");
    push(d);            show("PUSH D");
    t = pop(); push(pop() - t);  show("SUB");
    t = pop(); push(pop() * t);  show("MUL");
    x = pop();          show("POP X");

    printf("\nX = %d\n", x);
    return 0;
}
