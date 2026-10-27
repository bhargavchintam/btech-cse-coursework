/* polynomial addition using linked list */
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int coeff;
    int exp;
    struct node *next;
} NODE;

NODE* create(int c, int e)
{
    NODE *p = (NODE *)malloc(sizeof(NODE));
    p->coeff = c;
    p->exp = e;
    p->next = NULL;
    return p;
}

NODE* insertEnd(NODE *head, int c, int e)
{
    NODE *p = create(c, e);
    if(head == NULL)
        return p;
    NODE *t = head;
    while(t->next != NULL)
        t = t->next;
    t->next = p;
    return head;
}

NODE* add(NODE *a, NODE *b)
{
    NODE *res = NULL;
    while(a != NULL && b != NULL)
    {
        if(a->exp > b->exp)
        {
            res = insertEnd(res, a->coeff, a->exp);
            a = a->next;
        }
        else if(a->exp < b->exp)
        {
            res = insertEnd(res, b->coeff, b->exp);
            b = b->next;
        }
        else
        {
            int sum = a->coeff + b->coeff;
            if(sum != 0)
                res = insertEnd(res, sum, a->exp);
            a = a->next;
            b = b->next;
        }
    }
    while(a != NULL)
    {
        res = insertEnd(res, a->coeff, a->exp);
        a = a->next;
    }
    while(b != NULL)
    {
        res = insertEnd(res, b->coeff, b->exp);
        b = b->next;
    }
    return res;
}

void display(NODE *head)
{
    if(head == NULL)
    {
        printf("0\n");
        return;
    }
    while(head != NULL)
    {
        printf("%dx^%d", head->coeff, head->exp);
        if(head->next != NULL)
            printf(" + ");
        head = head->next;
    }
    printf("\n");
}

NODE* readPoly()
{
    int t, i, c, e;
    NODE *head = NULL;
    printf("Enter number of terms: ");
    scanf("%d", &t);
    printf("enter coeff and exp of each term (highest exp first)\n");
    for(i = 0; i < t; i++)
    {
        scanf("%d %d", &c, &e);
        head = insertEnd(head, c, e);
    }
    return head;
}

int main()
{
    NODE *p1 = readPoly();
    NODE *p2 = readPoly();
    printf("poly1 : ");
    display(p1);
    printf("poly2 : ");
    display(p2);
    NODE *sum = add(p1, p2);
    printf("sum   : ");
    display(sum);
    return 0;
}
