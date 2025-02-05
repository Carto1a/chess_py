#include "pieces/piece.h"

// NOTE: board tem que ser uma struct por si so, tenho que sabe a largura e
// altura do tabuleiro, se não for uma tabuleiro convencional, não sei oque eu
// vou fazer

typedef struct ChessBoard {
  Piece *board;
  Piece *capturedPieces;
} ChessBoard;

ChessBoard *Chess_BoardInitialize();

typedef struct ChessGame {
  ChessBoard initialState;
  ChessBoard state;
  void *moves;
} ChessGame;

ChessGame *Chess_GameInitialize();

int teste(void);
