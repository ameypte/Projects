#include <stdio.h>
#include <time.h>
#include <stdlib.h>

char randAction(int n);
char winlose(char n, char comAct);

int main()
{
    int chance, action, your_wins = 0, com_wins = 0;

    printf("\nEnter the number of chances: ");
    scanf("%d", &chance);
    getchar();
    char match[chance], comAct;

    for (int i = 0; i < chance; i++)
    {
        printf("\nPress 'r', 'p' or 's': ");
        scanf("%c", &action);
        getchar();
        comAct = randAction(3);
        printf("You: %c\nCom: %c", action, comAct);
        match[i] = winlose(action, comAct);
        switch (match[i])
        {
        case 'w':
            printf("\n***WON!***\n");
            your_wins++;
            break;
        case 'l':
            printf("\n***LOSE!***\n");
            com_wins++;
            break;
        case 't':
            printf("\n***TIE!***\n");
            break;
        }
    }
    printf("Your Wins: %d\nCom Wins %d\nMatch Tie: %d\n", your_wins, com_wins, chance - (your_wins + com_wins));

    return 0;
}

char randAction(int n)
{
    srand(time(NULL));
    int temp = rand() % n;

    switch (temp)
    {
    case 0:
        return 'r';
        break;
    case 1:
        return 'p';
        break;
    case 2:
        return 's';
        break;
    default:
        return 'e'; // e for Error
        break;
    }
}

char winlose(char n, char temp)
{
    char comAct = temp;
    switch (n)
    {
    case 'r':
        switch (comAct)
        {
        case 'r':
            return 't';
            break;
        case 'p':
            return 'l';
            break;
        case 's':
            return 'w';
            break;
        default:
            return 'e'; // e for Error
            break;
        }
        break;

    case 'p':
        switch (comAct)
        {
        case 'r':
            return 'w';
            break;
        case 'p':
            return 't';
            break;
        case 's':
            return 'l';
            break;
        default:
            return 'e'; // e for Error
            break;
        }
        break;

    case 's':
        switch (comAct)
        {
        case 'r':
            return 'l';
            break;
        case 'p':
            return 'w';
            break;
        case 's':
            return 't';
            break;
        default:
            return 'e'; // e for Error
            break;
        }
        break;

    default:
        printf("\nPlease enter valid charectar.");
        return 'e'; // e for Error
        break;
    }
}
