// pass 2 of a two-pass assembler: generates the object program (H/T/E records)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int lookup(char *s, int *addr)
{
    char l[20], a[20];
    FILE *sym = fopen("symtab.txt", "r");
    while(fscanf(sym, "%s%s", l, a) != EOF)
        if(strcmp(l, s) == 0){ *addr = strtol(a, NULL, 16); fclose(sym); return 1; }
    fclose(sym);
    return 0;
}

int optab(char *op, char *code)
{
    char m[20], c[20];
    FILE *ot = fopen("optab.txt", "r");
    while(fscanf(ot, "%s%s", m, c) != EOF)
        if(strcmp(op, m) == 0){ strcpy(code, c); fclose(ot); return 1; }
    fclose(ot);
    return 0;
}

int main()
{
    char addrs[20], label[20], opcode[20], operand[20], code[20], name[20], start[20];
    int addr, txtlen = 0, txtstart = 0;
    char text[100][10]; int nt = 0;
    FILE *in = fopen("intermediate.txt", "r");
    FILE *ob = fopen("output.txt", "w");

    fscanf(in, "%s%s%s", label, opcode, operand);   // START line
    strcpy(name, label); strcpy(start, operand);
    fprintf(ob, "H^%-6s^%06X^", name, (int)strtol(start, NULL, 16));

    // program length is on the END line's locctr - start; scan once to get it
    // simpler: recompute by reading through; here we stream and buffer text records
    fscanf(in, "%s%s%s%s", addrs, label, opcode, operand);
    txtstart = strtol(addrs, NULL, 16);
    // we need length: read whole file for last address
    long pos = ftell(in);
    char la[20], lb[20], lc[20], ld[20], lastaddr[20] = "0";
    FILE *scan = fopen("intermediate.txt", "r");
    fscanf(scan, "%s%s%s", la, lb, lc);
    while(fscanf(scan, "%s%s%s%s", la, lb, lc, ld) != EOF)
        strcpy(lastaddr, la);
    fclose(scan);
    fprintf(ob, "%06X\n", (int)(strtol(lastaddr, NULL, 16) - strtol(start, NULL, 16)));

    fprintf(ob, "T^%06X^", txtstart);
    do {
        if(strcmp(opcode, "END") == 0) break;
        code[0] = '\0';
        if(optab(opcode, code))
        {
            int a = 0;
            if(strcmp(operand, "**") != 0) lookup(operand, &a);
            sprintf(text[nt], "%s%04X", code, a);
            txtlen += 3; nt++;
        }
        else if(strcmp(opcode, "WORD") == 0)
        {
            sprintf(text[nt], "%06X", atoi(operand));
            txtlen += 3; nt++;
        }
        // RESW / RESB produce no object code
    } while(fscanf(in, "%s%s%s%s", addrs, label, opcode, operand) != EOF);

    fprintf(ob, "%02X", txtlen);
    for(int i = 0; i < nt; i++)
        fprintf(ob, "^%s", text[i]);
    fprintf(ob, "\n");
    fprintf(ob, "E^%06X\n", (int)strtol(start, NULL, 16));
    fclose(in); fclose(ob);

    FILE *o = fopen("output.txt", "r");
    char line[200];
    printf("--- Object program ---\n");
    while(fgets(line, sizeof line, o)) printf("%s", line);
    fclose(o);
    (void)pos;
    return 0;
}
