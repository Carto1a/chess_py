#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include "pieces/piece.h"

typedef struct chess_board {
  chess_piece **pieces;
} chess_board;

chess_board *chess_board_initialize();
chess_board *chess_board_initialize_from_chars(char char_board[8][8]);
chess_board *chess_board_initialize_from_file(char *file_name);
int chess_board_dispose(chess_board *board);

chess_board *chess_board_duplicate(const chess_board *board);
chess_piece *chess_board_get_piece(const chess_board *board, int x, int y);

#endif // !CHESS_BOARD_H
