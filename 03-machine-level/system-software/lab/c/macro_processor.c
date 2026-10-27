// one-pass macro processor: stores macro definitions and expands invocations
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char names[10][20];
char prm[10][10][20];
int nprm[10];
char body[10][50][120];
int nbody[10];
int nmac = 0;

int findmac(char *s)
{
    int i;
    for(i = 0; i < nmac; i++)
        if(strcmp(names[i], s) == 0) return i;
    return -1;
}

void splitcsv(char *s, char out[][20], int *n)
{
    char buf[120];
    strcpy(buf, s);
    *n = 0;
    char *t = strtok(buf, ",");
    while(t){ strcpy(out[*n], t); (*n)++; t = strtok(NULL, ","); }
}

int main()
{
    FILE *in = fopen("macro_input.txt", "r");
    FILE *out = fopen("expanded.txt", "w");
    char line[200], label[40], op[40], operand[120];

    while(fgets(line, sizeof line, in))
    {
        if(line[strlen(line)-1] == '\n') line[strlen(line)-1] = '\0';
        int haslabel = !(line[0] == '\t' || line[0] == ' ');
        label[0] = op[0] = operand[0] = '\0';
        if(haslabel) sscanf(line, "%s %s %s", label, op, operand);
        else       { sscanf(line, "%s %s", op, operand); }

        if(strcmp(op, "MACRO") == 0)
        {
            strcpy(names[nmac], label);
            splitcsv(operand, prm[nmac], &nprm[nmac]);
            nbody[nmac] = 0;
            while(fgets(line, sizeof line, in))
            {
                if(line[strlen(line)-1] == '\n') line[strlen(line)-1] = '\0';
                if(strstr(line, "MEND")) break;
                strcpy(body[nmac][nbody[nmac]++], line);
            }
            nmac++;
            continue;
        }

        int m = findmac(op);
        if(m >= 0)
        {
            char args[10][20]; int na;
            splitcsv(operand, args, &na);
            for(int b = 0; b < nbody[m]; b++)
            {
                char l[200]; strcpy(l, body[m][b]);
                for(int p = 0; p < nprm[m]; p++)
                {
                    char *pos;
                    while((pos = strstr(l, prm[m][p])) != NULL)
                    {
                        char nl[200];
                        int off = pos - l;
                        strncpy(nl, l, off); nl[off] = '\0';
                        strcat(nl, args[p]);
                        strcat(nl, pos + strlen(prm[m][p]));
                        strcpy(l, nl);
                    }
                }
                fprintf(out, "%s\n", l);
            }
            continue;
        }
        fprintf(out, "%s\n", line);
    }
    fclose(in); fclose(out);

    FILE *o = fopen("expanded.txt", "r");
    printf("--- Expanded program ---\n");
    while(fgets(line, sizeof line, o)) printf("%s", line);
    fclose(o);
    return 0;
}
