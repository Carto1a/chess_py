#include "move.h"
#include <stdlib.h>

chess_move *chess_move_initalize(chess_piece *piece, chess_move_type type,
                                 int x, int y) {
  chess_move *move = malloc(sizeof(chess_move));

  move->y = y;
  move->x = x;
  move->piece = piece;
  move->type = type;

  return move;
}
