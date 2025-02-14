#ifndef CHESS_PIECE_PAWN_H
#define CHESS_PIECE_PAWN_H

#include "piece.h"

typedef struct chess_pawn {
  chess_piece_type type;
  chess_piece_owner owner;
  int captured;
  int x;
  int y;

  chess_game *game;

  chess_list_move *(*get_moves)(struct chess_pawn *);
  chess_move *(*get_move)(struct chess_pawn *, int, int);

  int (*move_to)(struct chess_pawn *, int, int);
  int (*move_from_move)(struct chess_pawn *, chess_move);

  int moved;
} chess_pawn;

chess_pawn *chess_pawn_initialize(chess_piece_owner owner, int x, int y);
void chess_pawn_dispose(chess_pawn *pawn);

chess_list_move *chess_pawn_get_moves(chess_pawn *pawn);
chess_move *chess_pawn_get_move(chess_pawn *pawn, int x, int y);

int chess_pawn_move_to(chess_pawn *piece, int x, int y);
int chess_pawn_move_from_move(chess_pawn *piece, chess_move move);

#endif // !CHESS_PIECE_PAWN_H
