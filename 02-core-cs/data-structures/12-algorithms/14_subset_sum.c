// subset sum - backtracking, is there a subset that adds up to the target
#include<stdio.h>

int arr[100];
int n;

int subset(int i, int target) {
    if(target == 0)
        return 1;
    if(i == n || target < 0)
        return 0;
    // either take arr[i] into the subset or leave it out
    if(subset(i + 1, target - arr[i]))
        return 1;
    return subset(i + 1, target);
}

int main() {
    int i, target;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("enter %d elements\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter target sum: ");
    scanf("%d", &target);

    if(subset(0, target))
        printf("Yes, a subset with sum %d exists\n", target);
    else
        printf("No such subset\n");
    return 0;
}
