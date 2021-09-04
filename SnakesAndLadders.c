#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int even(int num)
{
    if (num % 2 == 0)
        return 1;
    else if (num == 0)
        return 1;
    return 0;
}

int emptySpace(int num, int a)
{
    if (a == 0)
    {
        if (num > 0 && num < 101)
            return 1;
        return 0;
    }
    if (num > 0 && num < 226)
        return 1;
    return 0;
}

void initializeBoard(int **board, int a)
{
    if (a == 0)
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (!even(i))
                    *(*(board + i) + j) = 10 * (9 - i) + j + 1;
                else
                    *(*(board + i) + j) = 10 * (9 - i) + 10 - j;
            }
        }
    }
    if (a == 1)
    {
        for (int i = 0; i < 15; i++)
        {
            for (int j = 0; j < 15; j++)
            {
                if (even(i))
                    *(*(board + i) + j) = 15 * (14 - i) + j + 1;
                else
                    *(*(board + i) + j) = 15 * (14 - i) + 15 - j;
            }
        }
    }
}
void displayBoard(int **board, int a)
{
    if (a == 0)
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (emptySpace(board[i][j], a))
                    printf("%4d", *(*(board + i) + j));
                else if (board[i][j] == 0)
                    printf("%4c", 'A');
                else if (board[i][j] == -1)
                    printf("%4c", 'a');
                else if (board[i][j] == -2)
                    printf("%4c", 'B');
                else if (board[i][j] == -3)
                    printf("%4c", 'b');
                else if (board[i][j] == -4)
                    printf("%4c", '-');
                else if (board[i][j] == -5)
                    printf("%4c", '#');
                else if (board[i][j] == -6)
                    printf("%4c", '@');
                else if (board[i][j] == -7)
                    printf("%4c", 'C');
                else if (board[i][j] == -8)
                    printf("%4c", 'c');
            }
            printf("\n");
        }
    }
    if (a == 1)
    {
        for (int i = 0; i < 15; i++)
        {
            for (int j = 0; j < 15; j++)
            {
                if (emptySpace(board[i][j], a))
                    printf("%4d", *(*(board + i) + j));
                else if (board[i][j] == 0)
                    printf("%4c", 'A');
                else if (board[i][j] == -1)
                    printf("%4c", 'a');
                else if (board[i][j] == -2)
                    printf("%4c", 'B');
                else if (board[i][j] == -3)
                    printf("%4c", 'b');
                else if (board[i][j] == -4)
                    printf("%4c", '-');
                else if (board[i][j] == -5)
                    printf("%4c", '#');
                else if (board[i][j] == -6)
                    printf("%4c", '@');
                else if (board[i][j] == -7)
                    printf("%4c", 'C');
                else if (board[i][j] == -8)
                    printf("%4c", 'c');
            }
            printf("\n");
        }
    }
}
int row(int pos, int a)
{
    if (a == 0)
    {
        if (pos % 10 == 0)
        {
            return 10 - ((int)(pos / 10));
        }
        return 9 - ((int)(pos / 10));
    }
    if (a == 1)
    {
        if (pos % 15 == 0)
        {
            return 15 - ((int)(pos / 15));
        }
        return 14 - (int)(pos / 15);
    }
}
int column(int pos, int a)
{
    // if even we are counxting from left if odd we are counting from the right
    if (a == 0)
    {
        if (even(row(pos, a)))
        {
            return (10 - row(pos, a)) * 10 - pos;
        }
        return 9 - ((10 - row(pos, a)) * 10 - pos);
    }
    if (a == 1)
    {
        if (!even(row(pos, a)))
        {
            return (15 - row(pos, a)) * 15 - pos;
        }
        return 14 - ((15 - row(pos, a)) * 15 - pos);
    }
}
int pos(int row, int column, int a)
{
    int pos;
    if (a == 0)
    {
        if (even(row))
        {
            pos = 10 * (9 - row) + (10 - column);
        }
        else
            pos = 10 * (9 - row) + column + 1;
    }
    else
    {
        if (!even(row))
        {
            pos = 15 * (14 - row) + (15 - column);
        }
        else
            pos = 15 * (14 - row) + column + 1;
    }
    return pos;
}

int locate_CurlySnake(int **board, int a)
{

    if (a == 0)
    {
        int i = rand() % 8;
        int j = rand() % 6;
        if (emptySpace(board[i][j], a) && emptySpace(board[i][j + 1], a) && emptySpace(board[i][j + 2], a) && emptySpace(board[i + 1][j + 2], a) && emptySpace(board[i + 1][j + 2], a) && emptySpace(board[i + 2][j + 2], a) && emptySpace(board[i + 2][j + 3], a) && emptySpace(board[i + 2][j + 4], a) && pos(i, j, a) > 0 && pos(i, j, a) < 101)
        {
            printf("The i and j chosen by locate_CurlySnake are %d %d, and the position is %d\n a is equal to %d", i, j, pos(i, j, a), a);
            return pos(i, j, a);
        }
        else
            locate_CurlySnake(board, a);
    }
    if (a == 1)
    {
        int i = rand() % 13;
        int j = rand() % 11;
        if (emptySpace(board[i][j], a) && emptySpace(board[i][j + 1], a) && emptySpace(board[i][j + 2], a) && emptySpace(board[i + 1][j + 2], a) && emptySpace(board[i + 2][j + 2], a) && emptySpace(board[i + 2][j + 3], a) && emptySpace(board[i + 2][j + 4], a))
        {
            return pos(i, j, a);
        }
        else
            locate_CurlySnake(board, a);
    }
    else
        printf("You have neither chosen 1 or 0 and a = %d\n", a);
}

void initializeCurlySnake(int **board, int a, int num)
{

    if (a == 0)
    {
        int pos = locate_CurlySnake(board, a);
        int i = row(pos, a);
        int j = column(pos, a);
        printf("i = %d, j = %d pos(i, j) = %d \n", i, j, pos);
        if (num == 1)
        {
            board[i][j] = 0;
            board[i][j + 1] = -1;
            board[i][j + 2] = -1;
            board[i + 1][j + 2] = -1;
            board[i + 2][j + 2] = -1;
            board[i + 2][j + 3] = -1;
            board[i + 2][j + 4] = -1;
        }
        if (num == 2)
        {
            board[i][j] = -2;
            board[i][j + 1] = -3;
            board[i][j + 2] = -3;
            board[i + 1][j + 2] = -3;
            board[i + 2][j + 2] = -3;
            board[i + 2][j + 3] = -3;
            board[i + 2][j + 4] = -3;
        }
    }

    if (a == 1)
    {
        int pos = locate_CurlySnake(board, a);
        int i = row(pos, a);
        int j = column(pos, a);
        printf("i = %d, j = %d pos(i, j) = %d \n", i, j, pos);
        if (num == 1)
        {
            board[i][j] = 0;
            board[i][j + 1] = -1;
            board[i][j + 2] = -1;
            board[i + 1][j + 2] = -1;
            board[i + 2][j + 2] = -1;
            board[i + 2][j + 3] = -1;
            board[i + 2][j + 4] = -1;
        }
        if (num == 2)
        {
            board[i][j] = -2;
            board[i][j + 1] = -3;
            board[i][j + 2] = -3;
            board[i + 1][j + 2] = -3;
            board[i + 2][j + 2] = -3;
            board[i + 2][j + 3] = -3;
            board[i + 2][j + 4] = -3;
        }
    }
}
int locate_StraightSnake(int **board, int a)
{
    int i = rand() % 8;
    int j = rand() % 15;
    if (emptySpace(board[i][j], a) && emptySpace(board[i + 1][j], a) && emptySpace(board[i + 2][j], a) && emptySpace(board[i + 3][j], a) && emptySpace(board[i + 4][j], a) && emptySpace(board[i + 5][j], a) && emptySpace(board[i + 6][j], a) && emptySpace(board[i + 7][j], a))
    {
        return pos(i, j, a);
    }
    else
        locate_StraightSnake(board, a);
}
void initializeStraightSnake(int **board, int a)
{
    int pos = locate_StraightSnake(board, a);
    int i = row(pos, a);
    int j = column(pos, a);
    printf("i = %d, j = %d pos(i, j) = %d \n", i, j, pos);
    if (a == 1)
    {
        board[i][j] = -7;
        board[i + 1][j] = -8;
        board[i + 2][j] = -8;
        board[i + 3][j] = -8;
        board[i + 4][j] = -8;
        board[i + 5][j] = -8;
        board[i + 6][j] = -8;
        board[i + 7][j] = -8;
    }
}

void initializeLadder(int **board, int size, int a)
{
    if (a == 0)
    {
        if (size == 3)
        {
            int i = rand() % 8;
            int j = rand() % 10;
            if (emptySpace(board[i][j], a) && emptySpace(board[i + 1][j], a) && emptySpace(board[i + 2][j], a))
            {
                board[i][j] = -4;
                board[i + 1][j] = -4;
                board[i + 2][j] = -4;
            }
            else
                initializeLadder(board, size, a);
        }
        if (size == 5)
        {
            int i = rand() % 5;
            int j = rand() % 10;
            if (emptySpace(board[i][j], a) && emptySpace(board[i + 1][j], a) && emptySpace(board[i + 2][j], a) && emptySpace(board[i + 3][j], a) && emptySpace(board[i + 4][j], a))
            {
                board[i][j] = -4;
                board[i + 1][j] = -4;
                board[i + 2][j] = -4;
                board[i + 3][j] = -4;
                board[i + 4][j] = -4;
            }
            else
                initializeLadder(board, size, a);
        }
    }
    else if (a == 1)
    {
        if (size == 3)
        {
            int i = rand() % 12;
            int j = rand() % 15;
            if (emptySpace(board[i][j], a) && emptySpace(board[i + 1][j], a) && emptySpace(board[i + 2][j], a))
            {
                board[i][j] = -4;
                board[i + 1][j] = -4;
                board[i + 2][j] = -4;
            }
            else
                initializeLadder(board, size, a);
        }
        if (size == 5)
        {
            int i = rand() % 10;
            int j = rand() % 15;
            if (emptySpace(board[i][j], a) && emptySpace(board[i + 1][j], a) && emptySpace(board[i + 2][j], a) && emptySpace(board[i + 3][j], a) && emptySpace(board[i + 4][j], a))
            {
                board[i][j] = -4;
                board[i + 1][j] = -4;
                board[i + 2][j] = -4;
                board[i + 3][j] = -4;
                board[i + 4][j] = -4;
            }
            else
                initializeLadder(board, size, a);
        }
        if (size == 6)
        {
            int i = rand() % 9;
            int j = rand() % 15;
            if (emptySpace(board[i][j], a) && emptySpace(board[i + 1][j], a) && emptySpace(board[i + 2][j], a) && emptySpace(board[i + 3][j], a) && emptySpace(board[i + 4][j], a) && emptySpace(board[i + 5][j], a))
            {
                board[i][j] = -4;
                board[i + 1][j] = -4;
                board[i + 2][j] = -4;
                board[i + 3][j] = -4;
                board[i + 4][j] = -4;
                board[i + 5][j] = -4;
            }
            else
                initializeLadder(board, size, a);
        }
    }
}
void initializeSnakesandLadders(int **board, int a)
{
    if (a == 0)
    {
        initializeCurlySnake(board, a, 1);
        initializeLadder(board, 5, a);
        initializeLadder(board, 3, a);
        initializeLadder(board, 3, a);
        initializeCurlySnake(board, a, 2);
    }
    if (a == 1)
    {
        initializeCurlySnake(board, a, 1);
        initializeCurlySnake(board, a, 2);
        initializeStraightSnake(board, a);
        initializeLadder(board, 6, a);
        initializeLadder(board, 5, a);
        initializeLadder(board, 3, a);
        initializeLadder(board, 3, a);
    }
}
int step_size(int d1, int d2)
{
    if (d1 == d2)
    {
        return -d1;
    }
    else if (d1 == 5 && d2 == 6 || d1 == 6 && d1 == 5)
    {
        return 14;
    }
    else
        return d1 + d2;
}
int checkSnakes(int **board, int pos, int a)
{
    // returns 1 if straight snake and -1 if curly Snake and 0 if false
    int i = row(pos, a);
    int j = column(pos, a);
    int val = board[i][j];
    // represents straight snakes
    if (val == -7)
    {
        return 1;
    }
    else if (val == 0 || val == -2) // represents the curly snakes heads
    {
        return -1;
    }
    return 0;
}
int ladderStart(int **board, int pos, int a)
{
    int i = row(pos, a);
    int j = column(pos, a);

    if (board[i][j] == -4 && board[i + 1][j] != -4)
        return 1;

    return 0;
}
int ladderLength(int **board, int start, int a)
{
    int i = row(start, a);
    int len = 0;
    int j = column(start, a);
    while (board[i][j] == -4)
    {
        i--;
        len++;
    }
    return len;
}

int checkLadders(int **board, int pos, int a)
{
    int i = row(pos, a);
    int j = column(pos, a);
    int val = board[i][j];

    return 0;
}

void move(int **board, int start, int finish, int player, int a)
{
    int i0 = row(start, a);
    int j0 = column(start, a);

    int i = row(finish, a);
    int j = column(finish, a);
    if (checkSnakes(board, board[i][j], a) == 1)
    {
        move(board, pos(i, j, a), pos(i + 7, j, a), player, a);
    }
    if (checkSnakes(board, board[i][j], a) == -1)
    {
        move(board, pos(i, j, a), pos(i + 2, j + 4, a), player, a);
    }
    if (ladderStart(board, finish, a))
    {
        move(board, pos(i, j, a), pos(i - ladderLength(board, finish, a), j, a), player, a);
    }
    else
    {
        board[i][j] = player;
    }
    if (i0 > 0 && j0 > 0 && board[i0][j0] > 0)
    {
        board[i0][j0] = pos(i0, j0, a);
    }
}
void clear(int **board, int position, int a)
{
    int i = row(position, a);
    int j = column(position, a);
    if (i > 0 && j > 0)
        board[i][j] = pos(i, j, a);
}
int main(void)
{
printf("Hello world\n");
    srand(time(NULL));
    int **board;
    int a;

    printf("Welcome to Snakes and Ladders, enter 0 for a 10x10 board and 1 for a 15x15 board\n");
    scanf("%d", &a);
    if (a == 0)
    {
        board = (int **)calloc(10, sizeof(int *));
        for (int i = 0; i < 10; i++)
        {
            *(board + i) = (int *)calloc(10, sizeof(int));
        }
    }
    else if (a == 1)
    {
        board = (int **)calloc(15, sizeof(int *));
        for (int i = 0; i < 15; i++)
        {
            *(board + i) = (int *)calloc(15, sizeof(int));
        }
    }
    initializeBoard(board, a);
    initializeSnakesandLadders(board, a);
    displayBoard(board, a);

    int lastPosition;
    if (a == 0)
        lastPosition = 100;
    else
        lastPosition = 225;

    int pPosition = 0;
    int cPosition = 0;
    int pDice = rand() % 6 + 1;
    int cDice = rand() % 6 + 1;
    printf("Player rolled %d and Computer rolled %d\n", pDice, cDice);

    if (pDice > cDice)
        printf("Player Starts!\n");
    else
        printf("Computer Starts!\n");

    int d1, d2;
    int stepsize;
    // Player starts
    int round = 1;
    /*
    while (round <= 10)
    {
        printf("Round %d!\n", round);
        //Player's turn
        d1 = rand() % 6 + 1;
        d2 = rand() % 6 + 1;
        stepsize = step_size(d1, d2);
        move(board, pPosition, pPosition + stepsize, -5, a);
        pPosition += stepsize;
        printf("Player has rolled %d and %d putting him at position %d\n", d1, d1, pPosition);

        // Computer's turn
        d1 = rand() % 6 + 1;
        d2 = rand() % 6 + 1;
        stepsize = step_size(d1, d2);
        move(board, cPosition, cPosition + stepsize, -6, a);
        cPosition += stepsize;
        printf("Computer has rolled %d and %d putting it at position %d\n", d1, d2, cPosition);
        displayBoard(board, a);

        round++;
    }
    */

    free(board);
    return 0;
}
