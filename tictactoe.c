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

int check_isemty(struct statusGame *st, int *row, int *col)
{

    if (st->Board.Mainboard[*row][*col] == ' ')
    {
        return 1;
    }
    else
    {
        printf("already taken\n");
    }

    return 0;
}

void getSelect(struct statusGame *St, int *row, int *col)
{
    int select;

    while (1)
    {
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
            else if (select < 1 || select > (maxRowCol * maxRowCol))
            {
                printf("[Error] must select number more than 1 and less than %d\n", maxRowCol * maxRowCol);
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

        *row = n / maxRowCol;
        *col = n % maxRowCol;

        int checker = check_isemty(St, row, col);
        if (checker == 1)
        {
            break;
        }
    }
}

void add_select(struct statusGame *st, int *row, int *col)
{
    char OBJ = st->turn;

    st->Board.Mainboard[*row][*col] = OBJ;
}

int checkwinner(struct statusGame *st)
{

    for (size_t i = 0; i < maxRowCol; i++)
    {
        int counter_col = 0;

        for (size_t j = 0; j < maxRowCol; j++)
        {
            if (st->Board.Mainboard[i][j] == st->turn)
            {
                counter_col++;
            }
        }

        if (counter_col == maxRowCol)
        {
            return 1;
        }
    }

    for (size_t j = 0; j < maxRowCol; j++)
    {
        int counter_row = 0;

        for (size_t i = 0; i < maxRowCol; i++)
        {
            if (st->Board.Mainboard[i][j] == st->turn)
            {
                counter_row++;
            }
        }

        if (counter_row == maxRowCol)
        {
            return 1;
        }
    }

    int counter_diadown = 0;

    for (size_t i = 0; i < maxRowCol; i++)
    {
        if (st->Board.Mainboard[i][i] == st->turn)
        {
            counter_diadown++;
        }
    }

    int counter_diaup = 0;

    for (size_t i = 0; i < maxRowCol; i++)
    {
        if (st->Board.Mainboard[i][(maxRowCol - 1) - i] == st->turn)
        {
            counter_diaup++;
        }
    }

    if (counter_diadown == maxRowCol || counter_diaup == maxRowCol)
    {
        return 1;
    }

    return 0;
}

void Celebration(struct statusGame *st)
{
    showBoard(st);

    if (st->iswin == 1)
    {
        printf("\n===================================\n");
        printf("      !!! WE HAVE WINNER!!!!            \n");
        printf("===================================\n");
        printf(">>>>>>>>>>>> [ %c ] <<<<<<<<<<<<<<<\n", st->turn);
    }

    else
    {
        printf("\n===================================\n");
        printf("     The match ended in a draw.      \n");
        printf("===================================\n");
    }
}

int main()
{
    // set up board
    struct statusGame st;
    clearBoard(&st);
    st.turn = 'X';

    int row, col;
    st.iswin = 0;

    int round = 1;

    //==================================================================================

    printf("==== Welcome to Tictactoe game!! ====\n");
    printf("[In this game X makes the first move.] \n\n");
    titleboard(&st);
    printf("\n[Press a number to select a space on the board.]\n\n");

    while (round != ((maxRowCol * maxRowCol) + 1))
    {

        showBoard(&st);
        printf("\n");

        getSelect(&st, &row, &col);

        add_select(&st, &row, &col);

        int winner = checkwinner(&st);

        if (winner == 1)
        {
            st.iswin = 1;
            break;
        }

        ChangeTurn(&st);
        round++;
    }

    Celebration(&st);

    return 0;
}