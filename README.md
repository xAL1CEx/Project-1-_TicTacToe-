# Project-1-_TicTacToe-
first try on project

# Tic-Tac-Toe in C

A two-player Tic-Tac-Toe game that runs in the terminal, written in C as one of my first projects while learning programming.

## How to play

1. Player X goes first, then O. Players take turns.
2. Each turn, type the number of the square you want. The numbers are shown at the start of the game:

```
[1][2][3]
[4][5][6]
[7][8][9]
```

3. The first player to fill a whole row, column or diagonal wins. If the board fills up with no winner, the game is a draw.

## Build and run

```
gcc -Wall tictactoe.c -o tictactoe
./tictactoe
```

Any C compiler or IDE works too.

## Features

- Input checking: rejects letters, numbers out of range, and squares that are already taken, then asks again
- Win detection for rows, columns and both diagonals
- Draw detection, with the final board always shown at the end
- Adjustable board size: change `maxRowCol` at the top of the file (a 4x4 board needs four in a row to win)

## How the code is organized

The whole game state (board, whose turn it is, win flag) lives in one `struct` that is passed by pointer to small functions, each doing one job:

| Function | Job |
|---|---|
| `clearBoard` / `showBoard` | set up and print the board |
| `getSelect` | read and validate the player's move |
| `add_select` | place the mark on the board |
| `checkwinner` | check all rows, columns and diagonals |
| `ChangeTurn` | switch between X and O |
| `Celebration` | print the final board and the result |

## What I learned

- **Test every case, not just one.** My first win check passed for rows but never detected a win in a column, because the second loop had the row and column indexes swapped. I only found it by playing a game where X filled a column.
- **Off-by-one errors are easy to make.** A wrong starting value for the round counter made the game keep asking for a move after the board was already full.
- **Order matters at the end of a game.** The last move can both win and fill the board, so the win check has to come before the draw check.
- **Pointers and structs.** Passing the game state by pointer lets one function change the real board instead of a copy.
