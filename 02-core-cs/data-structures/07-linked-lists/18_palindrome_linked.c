// check if a linked list is a palindrome
// find middle, reverse the second half, compare the two halves
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* insertEnd(struct node *head, int x) {
    struct node *p = malloc(sizeof(struct node));
    p->data = x;
    p->next = NULL;
    if(head == NULL)
        return p;
    struct node *t = head;
    while(t->next != NULL)
        t = t->next;
    t->next = p;
    return head;
}

struct node* reverse(struct node *head) {
    struct node *prev = NULL, *curr = head, *next;
    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int isPalindrome(struct node *head) {
    if(head == NULL || head->next == NULL)
        return 1;
    struct node *slow = head, *fast = head;
    while(fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct node *second = reverse(slow->next);
    struct node *p1 = head, *p2 = second;
    int ok = 1;
    while(p2 != NULL) {
        if(p1->data != p2->data) {
            ok = 0;
            break;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    slow->next = reverse(second);       // put the list back
    return ok;
}

void display(struct node *head) {
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct node *head = NULL;
    int n, i, x;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("enter %d elements\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &x);
        head = insertEnd(head, x);
    }
    display(head);
    if(isPalindrome(head))
        printf("palindrome\n");
    else
        printf("not palindrome\n");
    return 0;
}
