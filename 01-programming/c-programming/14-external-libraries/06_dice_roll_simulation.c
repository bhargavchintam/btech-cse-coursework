// gcc 06_dice_roll_simulation.c -o dice
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int i, face;
    int count[7] = {0};

    srand(time(NULL));
    for(i = 0; i < 100; i++)
    {
        face = rand() % 6 + 1;
        count[face]++;
    }

    for(i = 1; i <= 6; i++)
    {
        printf("Face %d came %d times\n", i, count[i]);
    }
    return 0;
}
