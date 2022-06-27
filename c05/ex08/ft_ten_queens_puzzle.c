#include <unistd.h>

#define BOARD_SIZE 10

typedef enum {queen, free} cell;

int count = 0;

static int pf_isSafe(cell board[][BOARD_SIZE], int row, int col)
// returns 0 if not Safe; 1 if Safe
{
  for (int i = 0; i < row; i++)
    if (board[i][col] == queen)
      return 0; // if 2 queens share the same column
  for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    if (board[i][j] == queen)
      return 0; // if 2 queens share same \ diagonal.
  for (int i = row, j = col; i >= 0 && j < BOARD_SIZE; i--, j++)
    if (board[i][j] == queen)
      return 0; // if 2 queens share the same / diagonal
  return 1; // Safe
}
  
static void pf_newBoard(cell* pboard)
{
  cell *pos = pboard;
  for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++)
    *pos ++ = free;
}

static void pf_printSolution(cell board[][BOARD_SIZE])
{
  char charToWrite = '.';
  for (int j = 0; j < BOARD_SIZE; j ++)
    for (int i = 0; i < BOARD_SIZE; i ++)
      if ( board[j][i] == queen )
	{
	  charToWrite = '0' + i;
	  if (write(1, &charToWrite, 1)) {}
	}
  if (write(1, "\n", 1)) {}
}

static void pf_nQueen(cell board[][BOARD_SIZE], int row)
{
  // if 'BOARD_SIZE' queens placed succesfully, print soluce & increment count
  if (row == BOARD_SIZE)
    {
      pf_printSolution(board);
      count ++;
      return;
    }

  // place queen at every square in current col, and recurse for each valid pos
  for (int i = 0; i < BOARD_SIZE; i++)
    if (pf_isSafe(board, row, i))
      {
	board[row][i] = queen; //place queen on current cell
	pf_nQueen(board, row + 1); //recurse for  the next col
	board[row][i] = free; // backtrack + remove queen from cell
      }
}

int ft_ten_queens_puzzle(void)
{
  cell cb[BOARD_SIZE][BOARD_SIZE];
  pf_newBoard((cell*)(&cb));
  pf_nQueen(cb, 0); // Start recursive algo
  return count; 
}
