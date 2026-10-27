// sparse matrix using linked list - store only the non zero terms
#include<stdio.h>
#include<stdlib.h>

struct node {
    int row;
    int col;
    int val;
    struct node *next;
};

struct node* insertEnd(struct node *head, int r, int c, int v) {
    struct node *p = malloc(sizeof(struct node));
    p->row = r;
    p->col = c;
    p->val = v;
    p->next = NULL;
    if(head == NULL)
        return p;
    struct node *t = head;
    while(t->next != NULL)
        t = t->next;
    t->next = p;
    return head;
}

int main() {
    int m, n, i, j, x;
    struct node *head = NULL;
    printf("Enter rows and columns: ");
    scanf("%d %d", &m, &n);
    printf("enter the matrix\n");
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &x);
            if(x != 0)
                head = insertEnd(head, i, j, x);
        }
    }
    printf("row col value\n");
    struct node *t = head;
    while(t != NULL) {
        printf(" %d   %d    %d\n", t->row, t->col, t->val);
        t = t->next;
    }
    return 0;
}
