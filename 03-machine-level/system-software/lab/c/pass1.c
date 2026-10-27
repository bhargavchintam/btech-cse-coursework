// pass 1 of a two-pass assembler: builds SYMTAB and the intermediate file, prints program length
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char label[20], opcode[20], operand[20], code[20], mnem[20];
    int locctr = 0, start = 0, found;
    FILE *in, *ot, *sym, *inter;

    in = fopen("input.txt", "r");
    inter = fopen("intermediate.txt", "w");
    sym = fopen("symtab.txt", "w");

    fscanf(in, "%s%s%s", label, opcode, operand);
    if(strcmp(opcode, "START") == 0)
    {
        start = strtol(operand, NULL, 16);
        locctr = start;
        fprintf(inter, "%s\t%s\t%s\n", label, opcode, operand);
        fscanf(in, "%s%s%s", label, opcode, operand);
    }

    while(strcmp(opcode, "END") != 0)
    {
        fprintf(inter, "%04X\t%s\t%s\t%s\n", locctr, label, opcode, operand);
        if(strcmp(label, "**") != 0)
            fprintf(sym, "%s\t%04X\n", label, locctr);

        ot = fopen("optab.txt", "r");
        found = 0;
        while(fscanf(ot, "%s%s", mnem, code) != EOF)
            if(strcmp(opcode, mnem) == 0){ found = 1; break; }
        fclose(ot);

        if(found)
            locctr += 3;
        else if(strcmp(opcode, "WORD") == 0)
            locctr += 3;
        else if(strcmp(opcode, "RESW") == 0)
            locctr += 3 * atoi(operand);
        else if(strcmp(opcode, "RESB") == 0)
            locctr += atoi(operand);
        else if(strcmp(opcode, "BYTE") == 0)
            locctr += strlen(operand) - 3;   // C'..' or X'..'

        fscanf(in, "%s%s%s", label, opcode, operand);
    }
    fprintf(inter, "%04X\t%s\t%s\t%s\n", locctr, label, opcode, operand);
    printf("Program length = %04X\n", locctr - start);

    fclose(in); fclose(inter); fclose(sym);
    printf("--- SYMTAB ---\n");
    sym = fopen("symtab.txt", "r");
    while(fscanf(sym, "%s%s", label, operand) != EOF)
        printf("%s\t%s\n", label, operand);
    fclose(sym);
    return 0;
}
