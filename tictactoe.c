#include <stdio.h>

#define maxRowCol 3

struct board
{
    char Mainboard[maxRowCol][maxRowCol];  // To play
    int sampleboard[maxRowCol][maxRowCol]; // To show an example
};

struct statusGame
{
    struct board;

    int iswin; // 1 have a winner
};

void clearBoard(struct board *B)
{
    for (size_t i = 0; i < maxRowCol; i++)
    {
        for (size_t j = 0; j < maxRowCol; j++)
        {
            B->Mainboard[i][j] = ' ';
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

void showBoard(struct board *B)
{
    for (size_t i = 0; i < maxRowCol; i++)
    {
        for (size_t j = 0; j < maxRowCol; j++)
        {
            printf("[%c]", B->Mainboard[i][j]);
        }

        printf("\n");
    }
}

void titleboard(struct board *B)
{
    int count = 0;

    for (size_t i = 0; i < maxRowCol; i++)
    {
        for (size_t j = 0; j < maxRowCol; j++)
        {
            count++;
            B->sampleboard[i][j] = count;
        }
    }

    for (size_t i = 0; i < maxRowCol; i++)
    {
        for (size_t j = 0; j < maxRowCol; j++)
        {
            printf("[%d]", B->sampleboard[i][j]);
        }

        printf("\n");
    }
}

int main()
{
    // set up board
    struct statusGame st;
    struct board Board;
    clearBoard(&Board);

    st.iswin = 1; // change back when game ready now just for test easier let is 1

    printf("==== Welcome to Tictactoe game!! ====\n");
    printf("[In this game x makes the first move.] \n\n");
    titleboard(&Board);
    printf("\n[Press a number to select a space on the board.]");

    return 0;
}