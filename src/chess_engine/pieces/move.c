#include "move.h"
#include <stdlib.h>

Move *Chess_InitMove(MovePiece piece, MoveType type, int x, int y) {
  Move *move = malloc(sizeof(Move));

  move->y = y;
  move->x = x;
  move->piece = piece;
  move->type = type;

  return move;
}

MoveList *Chess_InitMoveList(int size) {
  MoveList *list = malloc(sizeof(MoveList));

  Move **moveslist = malloc(sizeof(Move*) * size);

  list->size = size;
  list->length = 0;
  list->moves = moveslist;

  return list;
}

void Chess_MoveList_Add(MoveList *list, Move *move) {
  if (list->length >= list->size) {
    // TODO: alocar outra lista
  
  }

  list->moves[list->length] = move;
}
void Chess_MoveList_Remove(MoveList *list, int index);
