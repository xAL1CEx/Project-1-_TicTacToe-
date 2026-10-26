#include <stdio.h>

#define maxRowCol 3

/*
    ช่อง 3*3 = {[0,0][0,1][0,2]
               [1,0][1,1][1,3]
               [2,0][2,1][2,2]}
*/

// ต้องทำให้รู้ว่าช่องไหนมีใครเป็นเจ้าของหรือยังไม่มี
// ถ้ามีจำของแล้ว ห้ามจองอีก
// เกมจะ loop ไปเรื่อยจนกว่าจะมีคนชนะ หรือ ช่องทุกช่องเต็มโดยยังไม่มีคนชนะ

void showBoard(char tictactoe[][maxRowCol])
{
    for (size_t i = 0; i < maxRowCol; i++)
    {
        for (size_t j = 0; j < maxRowCol; j++)
        {
            printf("[%c]", tictactoe[i][j]);
        }

        printf("\n");
    }
}

int main()
{

    char tictactoe[3][3] = {{' ', ' ', ' '},
                            {' ', ' ', ' '},
                            {' ', ' ', ' '}};

    showBoard(tictactoe);

    return 0;
}