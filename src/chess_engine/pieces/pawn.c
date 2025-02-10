#include "piece.h"

Pawn *Chess_InitPawn(GameOwner owner, int x, int y){

}

MoveList *Chess_GetMovesPawn(Pawn pawn, Piece *board){
  MoveList *moves = Chess_InitMoveList(5);

  Move *move = Chess_InitMove(PAWN_MOVE, MOVE, pawn.piece.x + 1, pawn.piece.y + 2);

  Chess_MoveList_Add(moves, move);

  return moves;
}

void Chess_MovePawn(Piece *piece, int x, int y){
  
}


