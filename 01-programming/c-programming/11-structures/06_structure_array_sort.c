// sort students by marks in descending order
#include<stdio.h>

struct student {
    char name[30];
    int roll;
    float marks;
};

int main()
{
    struct student s[50], temp;
    int i, j, n;

    printf("Enter number of students : ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter name roll marks : ");
        scanf("%s %d %f", s[i].name, &s[i].roll, &s[i].marks);
    }

    for(i = 0; i < n-1; i++)
    {
        for(j = 0; j < n-1-i; j++)
        {
            if(s[j].marks < s[j+1].marks)
            {
                temp = s[j];        // swap
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }

    printf("\nAfter sorting :\n");
    for(i = 0; i < n; i++)
        printf("%s\t%d\t%.2f\n", s[i].name, s[i].roll, s[i].marks);

    return 0;
}
