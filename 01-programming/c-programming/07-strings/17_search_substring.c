// search for a substring inside a string
#include<stdio.h>
#include<string.h>

int main() {
    char str[100], sub[100];
    int i, j, n, m, pos = -1;

    printf("Enter the main string: ");
    scanf("%s", str);
    printf("Enter the substring to search: ");
    scanf("%s", sub);

    n = strlen(str);
    m = strlen(sub);

    for(i = 0; i <= n - m; i++) {
        j = 0;
        while(j < m && str[i + j] == sub[j])
            j++;
        //printf("i = %d j = %d\n", i, j);
        if(j == m) {
            pos = i;
            break;
        }
    }

    if(pos != -1)
        printf("Substring found at position %d\n", pos);
    else
        printf("Substring not found\n");

    return 0;
}
