#include <stdio.h>
#include <stdlib.h>

char matrix[3][3]; // 3x3 matrix representing the game board
char currentPlayer; // 'X' or 'O', representing the current player

void draw() {
    printf(" %c | %c | %c\n", matrix[0][0], matrix[0][1], matrix[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", matrix[1][0], matrix[1][1], matrix[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", matrix[2][0], matrix[2][1], matrix[2][2]);
}

void initMatrix() {
    int i, j;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            matrix[i][j] = ' ';
}

void getPlayerMove() {
    int x, y;

    printf("Enter X,Y for your move (i.e. 2,3): ");
    scanf("%d,%d", &x, &y);
    x--;
    y--;

    if (matrix[x][y] != ' ') {
        printf("Invalid move, try again.\n");
        getPlayerMove();
    } else
        matrix[x][y] = currentPlayer;
}

char checkForWin() {
    int i;

    // check rows
    for (i = 0; i < 3; i++)
        if (matrix[i][0] == matrix[i][1] &&
            matrix[i][1] == matrix[i][2])
            return matrix[i][0];

    // check columns
    for (i = 0; i < 3; i++)
        if (matrix[0][i] == matrix[1][i] &&
            matrix[1][i] == matrix[2][i])
            return matrix[0][i];

    // check diagonals
    if (matrix[0][0] == matrix[1][1] &&
        matrix[1][1] == matrix[2][2])
        return matrix[0][0];

    if (matrix[2][0] == matrix[1][1] &&
        matrix[1][1] == matrix[0][2])
        return matrix[2][0];

    return ' ';
}

int main() {
    int i;

    initMatrix();
    currentPlayer = 'X';
    for (i = 0; i < 9; i++) {
        draw();
        getPlayerMove();
        if (checkForWin() != ' ') {
            printf("%c wins!\n", checkForWin());
            exit(0);
        }
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
    printf("Draw\n");
    return 0;
}

