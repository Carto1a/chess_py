#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

#include "../move/list_move.h"

typedef enum chess_piece_owner {
  CHESS_OWNER_NONE,
  CHESS_OWNER_BLACK,
  CHESS_OWNER_WHITE
} chess_piece_owner;

typedef enum chess_piece_type {
  CHESS_PIECE_NONE,
  CHESS_KING,
  CHESS_QUEEN,
  CHESS_ROOK,
  CHESS_BISHOP,
  CHESS_KNIGHT,
  CHESS_PAWN
} chess_piece_type;

typedef struct chess_game chess_game;

typedef struct chess_piece {
  chess_piece_type type;
  chess_piece_owner owner;
  int captured;
  int x;
  int y;

  chess_game *game;

  chess_list_move (*get_moves)(struct chess_piece *);
  chess_move (*get_move)(struct chess_piece *, int, int);
  int (*move_to)(struct chess_piece *, int, int);
  int (*move_from_move)(struct chess_piece *, chess_move);
} chess_piece;

#endif // !CHESS_PIECE_H
