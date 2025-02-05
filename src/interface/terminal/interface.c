#include "../../interface.h"
#include "../../chess_engine/chess.h"
#include "../common/common.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define CLEAR() printf("\033[H\033[J");
#define MOVE_CURSOR(x, y) printf("\033[%d;%dH", (y), (x))
#define SET_CURSOR_VISIBILITY(state) printf("\033[?25%c", state ? 'h' : 'l')

char get_piece_char(PieceType piece) {
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

void print_board(Piece *board) {
  int board_width = 8;
  int board_heigth = 8;
  for (int y = 0; y < 8; y++) {
    for (int x = 0; x < 8; x++) {
      PieceType piece = board[x + (y * board_width)].type;
      char char_to_Print = get_piece_char(piece);
    }
    printf("\n");
  }
}

int interface_initialize(void) {
  CLEAR();

  sleep(5000);

  return 0;
}
