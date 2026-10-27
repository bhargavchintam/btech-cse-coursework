/* Bindu Bhargava   09-10-18 */
// josephus problem - n people in a circle, every k-th one eliminated
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int id;
    struct node *next;
};

int main()
{
    int n, k, i;
    struct node *head, *prev, *curr, *temp;

    printf("Enter n and k: ");
    scanf("%d %d", &n, &k);

    head = (struct node *)malloc(sizeof(struct node));
    head->id = 1;
    prev = head;
    for (i = 2; i <= n; i++)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->id = i;
        prev->next = temp;
        prev = temp;
    }
    prev->next = head;      // close the circle, prev is now the last node

    curr = head;
    while (curr->next != curr)
    {
        for (i = 1; i < k; i++)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        printf("Eliminated %d\n", curr->id);
        temp = curr;
        curr = curr->next;
        free(temp);
    }
    printf("Survivor is %d\n", curr->id);
    free(curr);
    return 0;
}
