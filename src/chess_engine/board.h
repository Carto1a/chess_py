#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include "pieces/piece.h"

typedef struct chess_board {
  chess_piece **pieces;
} chess_board;

chess_board *chess_board_initialize();
chess_board *chess_board_initialize_from_file(char *string_board);
int chess_board_dispose(chess_board *board);

chess_board *chess_board_duplicate(const chess_board *src_board);
chess_piece *chess_board_get_piece(const chess_board *board, unsigned int x,
                                   unsigned int y);
chess_piece *chess_board_get_piece_c_char(const chess_board *board, char c_x,
                                          char c_y);
chess_piece *chess_board_get_piece_c_int(const chess_board *board,
                                         unsigned int c_x, unsigned int c_y);

int chess_board_set_piece(const chess_board *board, const chess_piece *piece,
                          unsigned int x, unsigned int y);

#endif // !CHESS_BOARD_H
