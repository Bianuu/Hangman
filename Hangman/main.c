#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void showHangman(int);

int main(void)
{
    char secretWord[100], displayedWord[100], guessedWord[100];
    int remainingAttempts = 6, matchFound = 0, counter = 0, position = 0, winner, wordLength, i;
    char guessedLetter;

    system("cls");
    printf("\n\n Enter any word in lowercase and hit >>ENTER<<: ");
    scanf("%s", secretWord);
    wordLength = strlen(secretWord);

    system("cls");
    printf("\n\n !!!!!!!!!!!!!!!!!!!Welcome to the HANGMAN GAME!!!!!!!!!!!!!!!!!\n\n\n");
    printf("\n\n You will get 6 chances to guess the right word.\n\n");

    printf("\n\t||===== ");
    printf("\n\t||    | ");
    printf("\n\t||      ");
    printf("\n\t||      ");
    printf("\n\t||      ");
    printf("\n\t||      ");

    printf("\n\n The word has %d alphabets.\n\n", wordLength);

    for(i = 0; i < wordLength; i++)
    {
        displayedWord[i] = '_';
    }
    displayedWord[wordLength] = '\0';

    while(remainingAttempts != 0)
    {
        matchFound = 0;
        printf("\n\n Enter any alphabet from 'a' to 'z': ");
        fflush(stdin);
        scanf(" %c", &guessedLetter);

        if(guessedLetter < 'a' || guessedLetter > 'z')
        {
            system("cls");
            printf("\n\n\t Invalid input! Please enter a lowercase alphabet.\n");
            continue;
        }

        for(counter = 0; counter < wordLength; counter++)
        {
            if(guessedLetter == secretWord[counter])
            {
                matchFound = 1;
                position = counter;
            }
        }

        if(matchFound == 0)
        {
            printf("\n\t :( You have %d tries left.\n", --remainingAttempts);
            getchar();
            showHangman(remainingAttempts);
            getchar();
        }
        else
        {
            for(counter = 0; counter < wordLength; counter++)
            {
                if(guessedLetter == secretWord[counter])
                {
                    displayedWord[counter] = guessedLetter;
                }
            }

            winner = strcmp(displayedWord, secretWord);

            if(winner == 0)
            {
                printf("\n\n\t \t YAHOO!!!!! You are the WINNER !!!!!");
                printf("\n\n\t The Word was %s \n\n\n", secretWord);
                getchar();
                return 0;
            }
        }

        printf("\n\n\t");
        for(i = 0; i < wordLength; i++)
        {
            printf("%c ", displayedWord[i]);
        }
    }

    if(remainingAttempts <= 0)
    {
        printf("\n\n\t The Word was %s ", secretWord);
        printf("\n\n\t The man is dead, better luck next time!!!\n\n");
    }
    getchar();
    return 0;
}

void showHangman(int choice)
{
    system("cls");

    switch(choice)
    {
    case 0:
        printf("\n\t||===== ");
        printf("\n\t||    | ");
        printf("\n\t||   %cO/", '\\');
        printf("\n\t||    | ");
        printf("\n\t||   / %c", '\\');
        printf("\n\t||      ");
        break;
    case 1:
        printf("\n\t||===== ");
        printf("\n\t||    | ");
        printf("\n\t||   %cO/", '\\');
        printf("\n\t||    | ");
        printf("\n\t||     %c", '\\');
        printf("\n\t||      ");
        break;
    case 2:
        printf("\n\t||===== ");
        printf("\n\t||    | ");
        printf("\n\t||   %cO/", '\\');
        printf("\n\t||    | ");
        printf("\n\t||      ");
        printf("\n\t||      ");
        break;
    case 3:
        printf("\n\t||===== ");
        printf("\n\t||    | ");
        printf("\n\t||   %cO/", '\\');
        printf("\n\t||      ");
        printf("\n\t||      ");
        printf("\n\t||      ");
        break;
    case 4:
        printf("\n\t||===== ");
        printf("\n\t||    | ");
        printf("\n\t||   %cO ", '\\');
        printf("\n\t||      ");
        printf("\n\t||      ");
        printf("\n\t||      ");
        break;
    case 5:
        printf("\n\t||===== ");
        printf("\n\t||    | ");
        printf("\n\t||    O ");
        printf("\n\t||      ");
        printf("\n\t||      ");
        printf("\n\t||      ");
        break;
    }
}
