// gcc 03_student_record_system.c -o student
#include<stdio.h>

#define MAX 50

struct student
{
    int roll;
    char name[30];
    float marks;
};

int main()
{
    struct student s[MAX];
    int n = 0;
    int choice, i, roll, found;

    while(1)
    {
        printf("\n1.Add\n2.Display\n3.Search by roll\n4.Delete\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter roll, name, marks: ");
                scanf("%d %s %f", &s[n].roll, s[n].name, &s[n].marks);
                n++;
                break;

            case 2:
                printf("Roll\tName\tMarks\n");
                for(i = 0; i < n; i++)
                    printf("%d\t%s\t%.2f\n", s[i].roll, s[i].name, s[i].marks);
                break;

            case 3:
                printf("Enter roll to search: ");
                scanf("%d", &roll);
                found = 0;
                for(i = 0; i < n; i++)
                {
                    if(s[i].roll == roll)
                    {
                        printf("%d %s %.2f\n", s[i].roll, s[i].name, s[i].marks);
                        found = 1;
                    }
                }
                if(!found)
                    printf("Not found\n");
                break;

            case 4:
                printf("Enter roll to delete: ");
                scanf("%d", &roll);
                found = 0;
                for(i = 0; i < n; i++)
                {
                    if(s[i].roll == roll)
                        found = 1;
                    if(found && i < n-1)
                        s[i] = s[i+1];
                }
                if(found)
                {
                    n--;
                    printf("Deleted\n");
                }
                else
                    printf("Not found\n");
                break;

            case 5:
                return 0;

            default:
                printf("Wrong choice\n");
        }
    }
    return 0;
}
