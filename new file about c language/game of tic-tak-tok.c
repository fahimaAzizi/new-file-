#include <stdio.h>

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char player = 'X';

void print_board() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        if (i < 2) printf("\n---|---|---\n");
    }
    printf("\n");
}

int check_winner() {
    for (int i = 0; i < 3; i++)
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return 1;

    for (int i = 0; i < 3; i++)
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return 1;

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return 1;

    return 0;
}

void make_move() {
    int choice;
    printf("Player %c, enter your move (1-9): ", player);
    scanf("%d", &choice);
    if (choice >= 1 && choice <= 9) {
        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;
        if (board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = player;
            player = (player == 'X') ? 'O' : 'X';
        } else {
            printf("Position already taken! Try again.\n");
            make_move();
        }
    } else {
        printf("Invalid move! Try again.\n");
        make_move();
    }
}

int main() {
    int moves = 0;
    while (1) {
        print_board();
        make_move();
        moves++;
        if (check_winner()) {
            print_board();
            printf("Player %c wins!\n", (player == 'X') ? 'O' : 'X');
            break;
        }
        if (moves == 9) {
            print_board();
            printf("It's a draw!\n");
            break;
        }
    }
    return 0;
}

