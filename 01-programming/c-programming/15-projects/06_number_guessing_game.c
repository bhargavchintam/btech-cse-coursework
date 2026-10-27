// gcc 06_number_guessing_game.c -o guess
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int num, guess, count = 0;

    srand(time(NULL));
    num = rand() % 100 + 1;

    printf("Guess a number between 1 and 100\n");
    while(1)
    {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        count++;

        if(guess > num)
            printf("Too high\n");
        else if(guess < num)
            printf("Too low\n");
        else
        {
            printf("Correct! You took %d attempts\n", count);
            break;
        }
    }
    return 0;
}
