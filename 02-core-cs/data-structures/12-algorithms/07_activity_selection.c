// activity selection - greedy, pick the one that finishes earliest
#include<stdio.h>

int main() {
    int n, i, j;
    printf("Enter number of activities: ");
    scanf("%d", &n);

    int s[100], f[100];
    printf("Enter start and finish time of each activity:\n");
    for(i = 0; i < n; i++)
        scanf("%d %d", &s[i], &f[i]);

    // sort by finish time
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - 1 - i; j++) {
            if(f[j] > f[j + 1]) {
                int t = f[j]; f[j] = f[j + 1]; f[j + 1] = t;
                t = s[j]; s[j] = s[j + 1]; s[j + 1] = t;
            }
        }
    }

    printf("Selected activities:\n");
    printf("(%d, %d)\n", s[0], f[0]);
    int last = 0;
    for(i = 1; i < n; i++) {
        if(s[i] >= f[last]) {
            printf("(%d, %d)\n", s[i], f[i]);
            last = i;
        }
    }
    return 0;
}
