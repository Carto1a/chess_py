#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include "pieces/piece.h"

typedef struct chess_board {
  chess_piece **pieces;
} chess_board;

#endif // !CHESS_BOARD_H
