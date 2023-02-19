#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define points 100

int success(int attemptValue, int magicNumber)
{
    if (attemptValue == magicNumber)
        return 1;
    return 0;
}

int gameOver(int attemptNumber)
{
    if (attemptNumber == 5)
        return 1;
    return 0;
}

int verify(int attemptValue, int magicNumber, int attemptNumber)
{
    int over = 0;
    if (success(attemptValue, magicNumber))
    {
        printf("_____________\n* Success! *\n");
        printf("Points: %i \n", points / attemptNumber);
        over = 1;
    }

    else if (gameOver(attemptNumber))
    {
        printf("______________\n* Game Over! *\n");
        over = 1;
    }
    if (over)
        return 1;
    return 0;
}

int tip(int attemptValue, int magicNumber)
{
    if (attemptValue < magicNumber)
        printf("\nMagic number is bigger\n_______________________\n");
    else
    {
        printf("\nMagic number is smaller\n_______________________\n");
    }
}

int main(void)
{
    srand(time(0));

    int magicNumber = rand() % 51;
    int attemptNumber = 0;
    int attemptValue;

    printf("* The Magic Number 0-50 *\n_____________________\n");

    while (1)
    {
        attemptNumber++;
        printf("Attempt number %i: ", attemptNumber);
        scanf("%i", &attemptValue);
        if (verify(attemptValue, magicNumber, attemptNumber))
            break;
        tip(attemptValue, magicNumber);
    }
}