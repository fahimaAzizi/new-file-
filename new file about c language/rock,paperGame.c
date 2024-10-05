#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gameRules() {
    printf("\nRules of the game:\n");
    printf("Rock crushes Scissors\n");
    printf("Scissors cuts Paper\n");
    printf("Paper covers Rock\n");
}

int getComputerChoice() {
    // Generate a random number between 1 and 3
    return rand() % 3 + 1;
}

char* getChoiceName(int choice) {
    switch (choice) {
        case 1:
            return "Rock";
        case 2:
            return "Paper";
        case 3:
            return "Scissors";
        default:
            return "";
    }
}

void determineWinner(int playerChoice, int computerChoice) {
    printf("\nYou chose: %s\n", getChoiceName(playerChoice));
    printf("Computer chose: %s\n", getChoiceName(computerChoice));

    if (playerChoice == computerChoice) {
        printf("It's a tie!\n");
    } else if ((playerChoice == 1 && computerChoice == 3) ||  // Rock beats Scissors
               (playerChoice == 2 && computerChoice == 1) ||  // Paper beats Rock
               (playerChoice == 3 && computerChoice == 2)) {  // Scissors beats Paper
        printf("You win!\n");
    } else {
        printf("You lose!\n");
    }
}


