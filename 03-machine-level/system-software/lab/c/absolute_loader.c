// absolute loader: loads an object program (H/T/E records) into memory and prints it
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    FILE *in = fopen("obj.txt", "r");
    char rec[200];
    char mem[70000][3];
    int start = 0, i;

    for(i = 0; i < 70000; i++) strcpy(mem[i], "xx");

    while(fgets(rec, sizeof rec, in))
    {
        if(rec[0] == 'H')
        {
            char name[20]; int len;
            sscanf(rec, "H^%[^^]^%X^%X", name, &start, &len);
        }
        else if(rec[0] == 'T')
        {
            int taddr, tlen;
            char *p = rec + 2;               // skip "T^"
            sscanf(p, "%X", &taddr);
            p = strchr(p, '^') + 1;
            sscanf(p, "%X", &tlen);
            p = strchr(p, '^') + 1;          // first object code byte-pair group
            int addr = taddr;
            char *tok = strtok(p, "^\n");
            while(tok)
            {
                for(int k = 0; k < (int)strlen(tok); k += 2)
                {
                    char b[3] = { tok[k], tok[k+1], '\0' };
                    strcpy(mem[addr++], b);
                }
                tok = strtok(NULL, "^\n");
            }
        }
        else if(rec[0] == 'E')
            break;
    }
    fclose(in);

    printf("--- Memory after loading (from %04X) ---\n", start);
    printf("%04X  ", start);
    int col = 0;
    for(i = start; strcmp(mem[i], "xx") != 0; i++)
    {
        printf("%s ", mem[i]);
        if(++col % 8 == 0){ printf("\n%04X  ", i + 1); }
    }
    printf("\n");
    return 0;
}
