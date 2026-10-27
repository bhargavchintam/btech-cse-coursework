/* Bindu Bhargava  03-12-18 */

/* toy microprogrammed control unit driving the unit-05 accumulator machine.
   every micro-step: read control word at microPC from the control store,
   assert its signal bits on the datapath, then sequence (uPC+1, or DECODE
   jumps to the opcode's microroutine, or END returns to fetch at 0).

   machine: 32 words of memory, AC, PC, IR, MAR, MDR.
   instruction word: opcode in bits 7..5, address in bits 4..0. */

#include<stdio.h>
#include<string.h>

#define PC_OUT     (1u<<0)
#define MAR_IN     (1u<<1)
#define READ       (1u<<2)
#define MDR_OUT    (1u<<3)
#define IR_IN      (1u<<4)
#define PC_INC     (1u<<5)
#define IRADDR_OUT (1u<<6)
#define AC_OUT     (1u<<7)
#define AC_IN      (1u<<8)
#define MDR_IN     (1u<<9)
#define WRITE      (1u<<10)
#define ALU_ADD    (1u<<11)
#define ALU_PASS   (1u<<12)
#define DECODE     (1u<<13)
#define ENDBIT     (1u<<14)
#define HALT       (1u<<15)

const char *signame[16] = {
    "PC_OUT", "MAR_IN", "READ", "MDR_OUT", "IR_IN", "PC_INC",
    "IRADDR_OUT", "AC_OUT", "AC_IN", "MDR_IN", "WRITE",
    "ALU_ADD", "ALU_PASS", "DECODE", "END", "HALT"
};

const char *opname[4] = { "HLT", "LDA", "ADD", "STA" };

/* control store. fetch at 0, then one microroutine per opcode. */
unsigned cstore[20] = {
    /* fetch */
    [0]  = PC_OUT | MAR_IN | READ,
    [1]  = MDR_OUT | IR_IN | PC_INC,
    [2]  = DECODE,
    /* LDA: AC <- M[addr] */
    [4]  = IRADDR_OUT | MAR_IN | READ,
    [5]  = MDR_OUT | ALU_PASS | AC_IN,
    [6]  = ENDBIT,
    /* ADD: AC <- AC + M[addr] */
    [8]  = IRADDR_OUT | MAR_IN | READ,
    [9]  = MDR_OUT | ALU_ADD | AC_IN,
    [10] = ENDBIT,
    /* STA: M[addr] <- AC */
    [12] = IRADDR_OUT | MAR_IN,
    [13] = AC_OUT | MDR_IN | WRITE,
    [14] = ENDBIT,
    /* HLT */
    [16] = HALT
};

/* starting address of each opcode's microroutine (the dispatch ROM) */
int map[4] = { 16, 4, 8, 12 };

int pc, ac, ir, mar, mdr;
int mem[32];

/* names of the bits set in a control word */
void cwbits(unsigned cw, char *s)
{
    int i;
    s[0] = '\0';
    for (i = 0; i < 16; i++)
        if (cw & (1u << i))
            sprintf(s + strlen(s), "%s ", signame[i]);
}

/* assert one control word on the datapath, describe the transfers in t */
void datapath(unsigned cw, char *t)
{
    int bus = 0;

    t[0] = '\0';
    /* bus source first, then destinations, then memory */
    if (cw & PC_OUT)
        bus = pc;
    if (cw & MDR_OUT)
        bus = mdr;
    if (cw & AC_OUT)
        bus = ac;
    if (cw & IRADDR_OUT)
        bus = ir & 31;

    if (cw & MAR_IN) {
        mar = bus;
        sprintf(t + strlen(t), "MAR<-%d  ", mar);
    }
    if (cw & IR_IN) {
        ir = bus;
        sprintf(t + strlen(t), "IR<-%d (%s %d)  ", ir, opname[ir >> 5], ir & 31);
    }
    if (cw & MDR_IN) {
        mdr = bus;
        sprintf(t + strlen(t), "MDR<-%d  ", mdr);
    }
    if (cw & AC_IN) {
        if (cw & ALU_ADD) {
            sprintf(t + strlen(t), "AC<-%d+%d=%d  ", ac, bus, ac + bus);
            ac = ac + bus;
        } else {
            ac = bus;
            sprintf(t + strlen(t), "AC<-%d  ", ac);
        }
    }
    if (cw & READ) {
        mdr = mem[mar];
        sprintf(t + strlen(t), "MDR<-M[%d]=%d  ", mar, mdr);
    }
    if (cw & WRITE) {
        mem[mar] = mdr;
        sprintf(t + strlen(t), "M[%d]<-%d  ", mar, mdr);
    }
    if (cw & PC_INC) {
        pc = pc + 1;
        sprintf(t + strlen(t), "PC<-%d  ", pc);
    }
}

int main()
{
    int upc = 0, halted = 0, i;
    unsigned cw;
    char bits[128], t[128];

    /* program: LDA 20 / ADD 21 / STA 22 / HLT */
    mem[0] = (1 << 5) | 20;
    mem[1] = (2 << 5) | 21;
    mem[2] = (3 << 5) | 22;
    mem[3] = 0;
    mem[20] = 25;
    mem[21] = 17;

    printf("program:\n");
    for (i = 0; i < 4; i++)
        printf("  M[%d] = %3d   %s %d\n", i, mem[i],
               opname[mem[i] >> 5], mem[i] & 31);
    printf("data: M[20]=%d  M[21]=%d\n\n", mem[20], mem[21]);
    printf("uPC   control word bits           transfers\n");
    printf("---------------------------------------------------------\n");

    while (!halted) {
        cw = cstore[upc];
        if (upc == 0)
            printf("---- fetch, PC=%d ----\n", pc);
        datapath(cw, t);
        cwbits(cw, bits);
        printf("%3d   %-27s %s\n", upc, bits, t);

        /* sequencing */
        if (cw & DECODE) {
            upc = map[ir >> 5];
            printf("      dispatch: opcode %d (%s) -> uPC=%d\n",
                   ir >> 5, opname[ir >> 5], upc);
        } else if (cw & ENDBIT) {
            upc = 0;
        } else if (cw & HALT) {
            halted = 1;
        } else {
            upc = upc + 1;
        }
    }

    printf("---------------------------------------------------------\n");
    printf("halted. AC=%d  M[22]=%d\n", ac, mem[22]);
    return 0;
}
