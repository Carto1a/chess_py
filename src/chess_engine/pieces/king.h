#ifndef CHESS_PIECE_KING_H
#define CHESS_PIECE_KING_H

#include "piece.h"

typedef struct chess_king {
  chess_piece_type type;
  chess_piece_owner owner;
  int captured;
  int x;
  int y;

  chess_game *game;

  chess_list_move *(*get_moves)(struct chess_king *);
  chess_move (*get_move)(struct chess_king *, int, int);

  int (*move_to)(struct chess_king *, int, int);
  int (*move_from_move)(struct chess_king *, chess_move);

} chess_king;

chess_king *chess_king_initialize(chess_piece_owner owner, int x, int y);
void chess_king_dispose(chess_king *pawn);

chess_list_move *chess_king_get_moves(chess_king *pawn);
chess_move chess_king_get_move(chess_king *pawn, int x, int y);

int chess_king_move_to(chess_king *piece, int x, int y);
int chess_king_move_from_move(chess_king *piece, chess_move move);

#endif // !CHESS_PIECE_KING_H
