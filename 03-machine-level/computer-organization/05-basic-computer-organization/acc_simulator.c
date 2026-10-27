/* acc_simulator.c
   simulator for a tiny accumulator machine from unit 5
   8 instructions, 32 word memory, 3 bit opcode + 5 bit address
   traces PC, IR, ACC after every instruction like tracing on paper */

#include<stdio.h>

#define LDA 0
#define STA 1
#define ADD 2
#define SUB 3
#define JMP 4
#define JZ  5
#define OUT 6
#define HLT 7

#define ENC(op,ad) (((op)<<5)|(ad))

int mem[32];
int pc, ir, acc, mar, mdr;
int running;

char *mnem[8] = {"LDA","STA","ADD","SUB","JMP","JZ","OUT","HLT"};

void load_program()
{
    /* multiply mem[20] x mem[21] by repeated addition, result in mem[22]
       while count != 0 { count = count - 1; result = result + m; } */
    mem[0]  = ENC(LDA,21);      /* acc = count */
    mem[1]  = ENC(JZ, 8);       /* count == 0 -> done */
    mem[2]  = ENC(SUB,23);      /* acc = count - 1 */
    mem[3]  = ENC(STA,21);      /* count = acc */
    mem[4]  = ENC(LDA,22);      /* acc = result */
    mem[5]  = ENC(ADD,20);      /* acc = result + m */
    mem[6]  = ENC(STA,22);      /* result = acc */
    mem[7]  = ENC(JMP,0);       /* next pass of the loop */
    mem[8]  = ENC(LDA,22);      /* acc = result */
    mem[9]  = ENC(OUT,0);       /* print acc */
    mem[10] = ENC(HLT,0);

    mem[20] = 6;                /* m */
    mem[21] = 7;                /* count */
    mem[22] = 0;                /* result */
    mem[23] = 1;                /* constant 1 */
}

void fetch()
{
    mar = pc;                   /* MAR <- PC     */
    mdr = mem[mar];             /* MDR <- M[MAR] */
    ir  = mdr;                  /* IR  <- MDR    */
    pc  = pc + 1;               /* PC  <- PC + 1 */
}

void execute()
{
    int op = (ir >> 5) & 7;
    int ad = ir & 31;
    /* printf("op=%d ad=%d\n", op, ad); */

    switch(op) {
        case LDA:
            acc = mem[ad];
            break;
        case STA:
            mem[ad] = acc;
            break;
        case ADD:
            acc = acc + mem[ad];
            break;
        case SUB:
            acc = acc - mem[ad];
            break;
        case JMP:
            pc = ad;
            break;
        case JZ:
            if(acc == 0)
                pc = ad;
            break;
        case OUT:
            printf("            OUT --> %d\n", acc);
            break;
        case HLT:
            running = 0;
            break;
    }
}

void trace_line(int cpc)
{
    int op = (ir >> 5) & 7;
    int ad = ir & 31;

    if(op == JMP || op == JZ || op == LDA || op == STA || op == ADD || op == SUB)
        printf("%02d   %-4s%-3d  %4d\n", cpc, mnem[op], ad, acc);
    else
        printf("%02d   %-4s     %4d\n", cpc, mnem[op], acc);
}

int main()
{
    int cpc, count = 0;

    load_program();
    printf("accumulator machine simulator\n");
    printf("program: multiply mem[20] x mem[21] by repeated addition\n");
    printf("m = %d, count = %d, expected result = %d\n\n", mem[20], mem[21], mem[20]*mem[21]);
    printf("PC   IR        ACC\n");
    printf("-------------------\n");

    pc = 0;
    acc = 0;
    running = 1;
    while(running) {
        cpc = pc;               /* pc of the instruction being traced */
        fetch();
        execute();
        trace_line(cpc);
        count++;
    }

    printf("-------------------\n");
    printf("halted after %d instructions\n", count);
    printf("mem[22] (result) = %d\n", mem[22]);
    return 0;
}
