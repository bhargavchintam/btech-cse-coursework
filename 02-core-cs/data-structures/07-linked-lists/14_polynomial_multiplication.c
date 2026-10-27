// polynomial multiplication using linked list
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int coeff;
    int exp;
    struct node *next;
};

struct node* insertEnd(struct node *head, int c, int e)
{
    struct node *p = malloc(sizeof(struct node));
    p->coeff = c;
    p->exp = e;
    p->next = NULL;
    if(head == NULL)
        return p;
    struct node *t = head;
    while(t->next != NULL)
        t = t->next;
    t->next = p;
    return head;
}

// add a term into result, combine if that exp is already there
struct node* addTerm(struct node *head, int c, int e)
{
    struct node *t = head;
    while(t != NULL)
    {
        if(t->exp == e)
        {
            t->coeff += c;
            return head;
        }
        t = t->next;
    }
    return insertEnd(head, c, e);
}

struct node* multiply(struct node *a, struct node *b)
{
    struct node *res = NULL;
    struct node *p, *q;
    for(p = a; p != NULL; p = p->next)
        for(q = b; q != NULL; q = q->next)
            res = addTerm(res, p->coeff * q->coeff, p->exp + q->exp);
    return res;
}

void display(struct node *head)
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

struct node* readPoly()
{
    int t, i, c, e;
    struct node *head = NULL;
    printf("Enter number of terms: ");
    scanf("%d", &t);
    printf("enter coeff and exp of each term\n");
    for(i = 0; i < t; i++)
    {
        scanf("%d %d", &c, &e);
        head = insertEnd(head, c, e);
    }
    return head;
}

int main()
{
    struct node *p1 = readPoly();
    struct node *p2 = readPoly();
    printf("poly1   : ");
    display(p1);
    printf("poly2   : ");
    display(p2);
    struct node *prod = multiply(p1, p2);
    printf("product : ");
    display(prod);
    return 0;
}
