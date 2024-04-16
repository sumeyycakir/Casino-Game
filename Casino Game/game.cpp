#include <stdio.h>
#include <stdlib.h>  
#include <time.h>    

int rules();
void playGame();

int main()
{
    srand(time(NULL));  

    rules(); 
     
    printf("\n");

    playGame();  

    printf("\nThank you for playing!\n");

    return 0;
}

void playGame()
{
    char name[50];
    printf("Enter your name: ");
    scanf("%s", name);  
    printf("\n");

    int deposit = 100;  

    for (int turn = 1; turn <= 3; turn++) {
        printf("=== Turn %d ===\n", turn);
        printf("Current balance: $%d\n", deposit);

        int bet;
        printf("%s, enter the amount to bet for this turn: $", name);
        scanf("%d", &bet);  

        if (bet > deposit) {
            printf("Bet amount exceeds your balance. Please enter a valid bet.\n");
            turn--;  
            continue;
        }

        int guess;
        printf("Guess a number from 1 to 10: ");
        scanf("%d", &guess);  

        if (guess < 1 || guess > 10) {
            printf("Invalid guess. Please enter a number between 1 and 10.\n");
            turn--;  
            continue;
        }

        int computer = rand() % 10 + 1;  
        printf("Computer's number: %d\n", computer);

        if (guess == computer) {
            int winnings = bet * 10;
            printf("Congratulations! You won $%d\n", winnings);
            deposit += winnings;  
        } else {
            printf("Sorry, you lost $%d\n", bet);
            deposit -= bet;  
        }

        printf("\n");
    }

    printf("End of the game. Final balance: $%d\n", deposit);
}

int rules()
{
    printf("-----------------------------------------------------------\n");
    printf("GAME RULES\n");
    printf("-----------------------------------------------------------\n");
    printf("1. You start with an initial balance of $100.\n");
    printf("2. During each turn, place a bet and guess a number between 1 and 10.\n");
    printf("3. If your guess matches the computer's number, you win 10 times the bet amount.\n");
    printf("4. If your guess is wrong, you lose the bet amount.\n");
    printf("5. You will play 3 turns in total.\n");
    printf("-----------------------------------------------------------\n");

    return 0;
}
