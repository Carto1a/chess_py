#include "list_move.h"
#include <stdlib.h>

chess_list_move *chess_list_move_initialize(int size) {
  chess_list_move *list = malloc(sizeof(chess_list_move));

  chess_move **moveslist = malloc(sizeof(chess_move *) * size);

  list->size = size;
  list->length = 0;
  list->moves = moveslist;

  return list;
}

void chess_list_move_append(chess_list_move *list, chess_move *move) {
  if (list->length >= list->size) {
    // TODO: alocar outra lista
  }

  list->moves[list->length] = move;
}

void chess_list_move_remove(chess_list_move *list, int index);
