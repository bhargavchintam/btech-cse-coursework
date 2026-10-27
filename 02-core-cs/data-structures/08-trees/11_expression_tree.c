// expression tree - build from postfix, evaluate, print inorder
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define SIZE 100

struct node {
    char data;
    struct node *left, *right;
};

struct node* create(char c) {
    struct node *n = malloc(sizeof(struct node));
    n->data = c;
    n->left = n->right = NULL;
    return n;
}

struct node* build(char *postfix) {
    struct node *stack[SIZE];
    int top = -1;
    int i;
    for (i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];
        struct node *n = create(c);
        if (isdigit(c)) {
            stack[++top] = n;
        }
        else {
            n->right = stack[top--];
            n->left = stack[top--];
            stack[++top] = n;
        }
    }
    return stack[top];
}

int evaluate(struct node *root) {
    if (root->left == NULL && root->right == NULL)
        return root->data - '0';
    int l = evaluate(root->left);
    int r = evaluate(root->right);
    switch (root->data) {
        case '+': return l + r;
        case '-': return l - r;
        case '*': return l * r;
        case '/': return l / r;
    }
    return 0;
}

void inorder(struct node *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%c ", root->data);
    inorder(root->right);
}

int main() {
    char postfix[] = "23+4*";
    struct node *root = build(postfix);

    printf("Postfix    : %s\n", postfix);
    printf("Inorder    : ");
    inorder(root);
    printf("\nValue      : %d\n", evaluate(root));
    return 0;
}
