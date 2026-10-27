// compare bubble vs insertion - count comparisons and swaps on the SAME array
#include<stdio.h>

int main() {
    int a[100], b[100], c[100], n, i, j, temp, key;
    long bcomp = 0, bswap = 0, icomp = 0, ishift = 0;

    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter %d elements\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i];
        c[i] = a[i];
    }

    // bubble sort on b
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - 1 - i; j++) {
            bcomp++;
            if(b[j] > b[j + 1]) {
                temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
                bswap++;
            }
        }
    }

    // insertion sort on c
    for(i = 1; i < n; i++) {
        key = c[i];
        j = i - 1;
        while(j >= 0) {
            icomp++;
            if(c[j] > key) {
                c[j + 1] = c[j];
                ishift++;
                j--;
            }
            else
                break;
        }
        c[j + 1] = key;
    }

    printf("Bubble    : comparisons = %ld, swaps  = %ld\n", bcomp, bswap);
    printf("Insertion : comparisons = %ld, shifts = %ld\n", icomp, ishift);
    return 0;
}
