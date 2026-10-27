#include<stdio.h>

/* same memory picture as the worked numerical in notes.md */

int mem[1024];

void show(char *mode, int ea, int op)
{
    if(ea < 0)
        printf("%-18s %-6s %d\n", mode, "--", op);
    else
        printf("%-18s %-6d %d\n", mode, ea, op);
}

int main()
{
    int a = 500;     /* address field of the instruction */
    int pc = 202;    /* after fetching the two-word instruction at 200-201 */
    int r1 = 400;
    int br = 100;    /* base register */
    int sp = 999;
    int ea;

    mem[400] = 700;
    mem[500] = 800;
    mem[600] = 900;
    mem[702] = 325;
    mem[800] = 300;
    mem[999] = 1200;

    printf("address field A = %d, PC = %d, R1 = %d, BR = %d, SP = %d\n\n",
           a, pc, r1, br, sp);
    printf("%-18s %-6s %s\n", "mode", "EA", "operand");

    show("immediate", -1, a);

    ea = a;
    show("direct", ea, mem[ea]);

    ea = mem[a];
    show("indirect", ea, mem[ea]);

    show("register", -1, r1);

    ea = r1;
    show("register indirect", ea, mem[ea]);

    ea = a + br;
    show("displacement", ea, mem[ea]);

    ea = pc + a;
    show("relative", ea, mem[ea]);

    ea = sp;
    show("stack", ea, mem[ea]);

    return 0;
}
