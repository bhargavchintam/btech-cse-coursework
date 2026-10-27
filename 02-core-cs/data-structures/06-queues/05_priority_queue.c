// priority queue using arrays - higher priority value served first
#include<stdio.h>
#define SIZE 100

int data[SIZE];
int prio[SIZE];
int n = 0;

void insert(int x, int p) {
    data[n] = x;
    prio[n] = p;
    n++;
    printf("Inserted\n");
}

void delete() {
    int i, max;
    if (n == 0) {
        printf("Queue is empty\n");
        return;
    }
    max = 0;
    for (i = 1; i < n; i++)
        if (prio[i] > prio[max])
            max = i;
    printf("Served %d (priority %d)\n", data[max], prio[max]);
    for (i = max; i < n - 1; i++) {
        data[i] = data[i + 1];
        prio[i] = prio[i + 1];
    }
    n--;
}

void display() {
    int i;
    if (n == 0) {
        printf("Queue is empty\n");
        return;
    }
    printf("Element\tPriority\n");
    for (i = 0; i < n; i++)
        printf("%d\t%d\n", data[i], prio[i]);
}

int main() {
    int ch, x, p;
    while (1) {
        printf("\n1.Insert  2.Delete  3.Display  4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter element and priority: ");
                scanf("%d %d", &x, &p);
                insert(x, p);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Wrong choice\n");
        }
    }
    return 0;
}
