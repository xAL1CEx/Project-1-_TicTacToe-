#include <stdio.h>
#include <string.h>

#define maxRowCol 3

struct board
{
    char Mainboard[maxRowCol][maxRowCol];  // To play
    int sampleboard[maxRowCol][maxRowCol]; // To show an example
};

struct statusGame
{
    struct board Board;

    int iswin; // 1 have a winner
    char turn;
};

void clearBoard(struct statusGame *B)
{
    for (size_t i = 0; i < maxRowCol; i++)
    {
        for (size_t j = 0; j < maxRowCol; j++)
        {
            B->Board.Mainboard[i][j] = ' ';
        }
    }
}

/*
    ช่อง 3*3 = {[0,0][0,1][0,2]
               [1,0][1,1][1,2]
               [2,0][2,1][2,2]}
*/

// ต้องทำให้รู้ว่าช่องไหนมีใครเป็นเจ้าของหรือยังไม่มี
// ถ้ามีจำของแล้ว ห้ามจองอีก
// เกมจะ loop ไปเรื่อยจนกว่าจะมีคนชนะ หรือ ช่องทุกช่องเต็มโดยยังไม่มีคนชนะ

void showBoard(struct statusGame *B)
{
    for (size_t i = 0; i < maxRowCol; i++)
    {
        for (size_t j = 0; j < maxRowCol; j++)
        {
            printf("[%c]", B->Board.Mainboard[i][j]);
        }

        printf("\n");
    }
}

void titleboard(struct statusGame *B)
{
    int count = 0;

    for (size_t i = 0; i < maxRowCol; i++)
    {
        for (size_t j = 0; j < maxRowCol; j++)
        {
            count++;
            B->Board.sampleboard[i][j] = count;
        }
    }

    for (size_t i = 0; i < maxRowCol; i++)
    {
        for (size_t j = 0; j < maxRowCol; j++)
        {
            printf("[%d]", B->Board.sampleboard[i][j]);
        }

        printf("\n");
    }
}

void ChangeTurn(struct statusGame *T)
{
    T->turn = (T->turn == 'X') ? 'O' : 'X';
}

void getSelect(struct statusGame *St, int *col, int *row)
{
    int select;

    // for get number
    while (1)
    {
        printf("Turn [%c] select >> ", St->turn);
        if (scanf("%d", &select) != 1)
        {
            printf("[Error] when select must be only number\n");
            while (getchar() != '\n')
                ;
        }
        else if (select < 1 || select > 9)
        {
            printf("[Error] must select number more than 1 and less than 9\n");
            while (getchar() != '\n')
                ;
        }
        else
        {
            break;
        }
    }

    // cal row col
    int n = select - 1;

    *row = n / 3;
    *col = n % 3;
}

int main()
{
    // set up board
    struct statusGame st;
    clearBoard(&st);
    st.turn = 'X';

    int col;
    int row;

    st.iswin = 0; // change back when game ready now just for test easier let is 1

    //==================================================================================

    printf("==== Welcome to Tictactoe game!! ====\n");
    printf("[In this game X makes the first move.] \n\n");
    titleboard(&st);
    printf("\n[Press a number to select a space on the board.]\n\n");

    while (st.iswin == 0)
    {

        showBoard(&st);
        printf("\n");

        getSelect(&st, &col, &row);

        ChangeTurn(&st);
    }

    return 0;
}