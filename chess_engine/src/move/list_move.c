#include "chess/move/list_move.h"
#include "chess/chess.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

chess_list_move *chess_list_move_initialize(int size) {
  if (size < 1) {
    chess_set_error("Invalid size provided. Size must be greater than zero");
    return NULL;
  }

  chess_list_move *list = malloc(sizeof(chess_list_move));
  if (!list) {
    chess_set_error("Memory allocation failed");
    return NULL;
  }

  list->moves = malloc(sizeof(chess_move) * size);
  if (!list->moves) {
    chess_set_error("Memory allocation failed");
    return NULL;
  }

  list->size = size;
  list->length = 0;

  return list;
}

int chess_list_move_append(chess_list_move *list, chess_move *move) {
  if (list->length >= list->size) {
    size_t new_size = list->size + 10;
    chess_move *new_moves_list = malloc(sizeof(chess_move) * new_size);
    if (!new_moves_list) {
      chess_set_error("Memory allocation for new list failed");
      return CHESS_ERROR;
    }

    memcpy(new_moves_list, list->moves, sizeof(chess_move) * list->size);
    free(list->moves);

    list->moves = new_moves_list;
  }

  list->moves[list->length] = *move;
  list->length += 1;

  // NOTE: devo dar free no move?
  return CHESS_SUCESS;
}

void chess_list_move_dispose(chess_list_move *list) {
  if (list->moves)
    free(list->moves);

  free(list);
}
