#include "move.h"

typedef enum PieceType { KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN } PieceType;
typedef enum GameOwner { OWNER_BLACK, OWNER_WHITE } GameOwner;

typedef struct Piece {
  PieceType type;
  GameOwner owner;
  int captured;
  int x;
  int y;
} Piece;

typedef struct Pawn {
  Piece piece;
} Pawn;

Pawn Chess_InitPawn(int x, int y, GameOwner owner);
Move Chess_GetMovesPawn(Pawn piece);
int Chess_MovePawn(Piece piece, int x, int y);

typedef struct Bishop {
  Piece piece;
} Bishop;

Pawn Chess_InitBishop();
Move Chess_GetMovesBishop();
void Chess_MoveBishop();
