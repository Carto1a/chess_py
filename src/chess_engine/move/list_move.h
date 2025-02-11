#ifndef CHESS_LIST_MOVE_H
#define CHESS_LIST_MOVE_H

#include "move.h"

typedef struct chess_list_move {
  chess_move *moves;
  int length;
  int size;

  int (*append)(struct chess_list_move, chess_move *);
  int (*remove)(struct chess_list_move, int);
} chess_list_move;

chess_list_move *chess_list_move_initialize(int size);
void chess_list_move_append(chess_list_move *list, chess_move *move);
void chess_list_move_remove(chess_list_move *list, int index);

#endif // !CHESS_LIST_MOVE_H
