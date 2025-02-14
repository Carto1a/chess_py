#include "move.h"
#include "../chess.h"
#include <stdlib.h>

chess_move *chess_move_initalize(chess_move_type type, chess_piece *piece,
                                 int x, int y) {
  chess_move *move = malloc(sizeof(chess_move));
  if (!move) {
    chess_set_error("Memory allocation failed");
    return NULL;
  }

  move->x = x;
  move->y = y;
  move->piece = piece;
  move->type = type;

  return move;
}

void chess_move_dispose(chess_move *move) { free(move); }
