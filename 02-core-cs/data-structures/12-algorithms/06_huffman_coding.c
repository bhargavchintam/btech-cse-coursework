/* Bindu Bhargava   18-10-18 */
// huffman coding - build the tree and print the code of each character
#include<stdio.h>
#include<stdlib.h>

struct node
{
    char ch;
    int freq;
    struct node *left, *right;
};

struct node *newnode(char ch, int freq)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->ch = ch;
    p->freq = freq;
    p->left = p->right = NULL;
    return p;
}

// left edge = 0, right edge = 1, a leaf prints its accumulated code
void printcodes(struct node *root, int code[], int top)
{
    if(root->left)
    {
        code[top] = 0;
        printcodes(root->left, code, top + 1);
    }
    if(root->right)
    {
        code[top] = 1;
        printcodes(root->right, code, top + 1);
    }
    if(!root->left && !root->right)
    {
        int i;
        printf("%c : ", root->ch);
        for(i = 0; i < top; i++)
            printf("%d", code[i]);
        printf("\n");
    }
}

int main()
{
    int n, i;
    printf("Enter number of characters: ");
    scanf("%d", &n);

    struct node *arr[100];
    printf("Enter character and frequency:\n");
    for(i = 0; i < n; i++)
    {
        char ch;
        int f;
        scanf(" %c %d", &ch, &f);
        arr[i] = newnode(ch, f);
    }

    int size = n;
    while(size > 1)
    {
        // pull out the smallest
        int m = 0;
        for(i = 1; i < size; i++)
            if(arr[i]->freq < arr[m]->freq)
                m = i;
        struct node *a = arr[m];
        arr[m] = arr[size - 1];
        size--;

        // pull out the next smallest
        m = 0;
        for(i = 1; i < size; i++)
            if(arr[i]->freq < arr[m]->freq)
                m = i;
        struct node *b = arr[m];
        arr[m] = arr[size - 1];
        size--;

        struct node *z = newnode('$', a->freq + b->freq);
        z->left = a;
        z->right = b;
        arr[size] = z;
        size++;
    }

    int code[100];
    printcodes(arr[0], code, 0);
    // dont forget to free
    return 0;
}
