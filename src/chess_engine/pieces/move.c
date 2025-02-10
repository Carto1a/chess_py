#include "move.h"
#include <stdlib.h>

chess_move *chess_move_initalize(chess_move_piece piece, chess_move_type type, int x, int y) {
  chess_move *move = malloc(sizeof(chess_move));

  move->y = y;
  move->x = x;
  move->piece = piece;
  move->type = type;

  return move;
}

chess_list_move *chess_list_move_initialize(int size) {
  chess_list_move *list = malloc(sizeof(chess_list_move));

  chess_move **moveslist = malloc(sizeof(chess_move*) * size);

  list->size = size;
  list->length = 0;
  list->moves = moveslist;

  return list;
}

void chess_list_move_add(chess_list_move *list, chess_move *move) {
  if (list->length >= list->size) {
    // TODO: alocar outra lista
  
  }

  list->moves[list->length] = move;
}

void chess_list_move_remove(chess_list_move *list, int index);
