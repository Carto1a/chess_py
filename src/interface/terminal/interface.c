#include "../../interface.h"
#include "../../chess_engine/chess.h"
#include "../common/common.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define Clear() printf("\033[H\033[J");
#define MoveCursor(x, y) printf("\033[%d;%dH", (y), (x))
#define CursorVisible(state) printf("\033[?25%c", state ? 'h' : 'l')

char GetPieceChar(PieceType piece) {
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

void PrintBoard(Piece *board) {
  int boardWidth = 8;
  int boardHeigth = 8;
  for (int y = 0; y < 8; y++) {
    for (int x = 0; x < 8; x++) {
      PieceType piece = board[x + (y * boardWidth)].type;
      char charToPrint = GetPieceChar(piece);
    }
    printf("\n");
  }
}

int init_interface() {
  Clear();

  sleep(5000);

  return 0;
}
