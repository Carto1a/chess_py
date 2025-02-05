#include "../../interface.h"
#include "../../chess_engine/chess.h"
#include "../common/common.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define CLEAR() printf("\033[H\033[J");
#define MOVE_CURSOR(x, y) printf("\033[%d;%dH", (y), (x))
#define SET_CURSOR_VISIBILITY(state) printf("\033[?25%c", state ? 'h' : 'l')
#define FAILURE 0

char get_piece_char(chess_piece_type piece);
int print_board(chess_piece *board);
void print_game_input();

char get_piece_char(chess_piece_type piece) {
  switch (piece) {
  case KING:
    return 'K';
  case QUEEN:
    return 'Q';
  case ROOK:
    return 'R';
  case BISHOP:
    return 'B';
  case KNIGHT:
    return 'N';
  case PAWN:
    return 'P';
  default:
    return ' ';
  }
}

int print_board(chess_piece *board) {
  if (board == NULL)
    return 0;

  int board_width = 8;
  int board_heigth = 8;
  for (int y = 0; y < 8; y++) {
    for (int x = 0; x < 8; x++) {
      chess_piece_type piece = board[x + (y * board_width)].type;
      char char_to_Print = get_piece_char(piece);
      printf(" %c ", char_to_Print);
    }
    printf("\n");
  }

  return 1;
}

void print_game_input() { printf("input: "); }

int interface_initialize(void) {
  const int board_width = 8;
  const int board_heigth = 8;

  while (true) {
    CLEAR();

    MOVE_CURSOR(0, 0);
    if (print_board(NULL) == FAILURE)
      break;

    MOVE_CURSOR(0, board_heigth + 2);
    print_game_input();

    sleep(500);
  }

  return 0;
}
