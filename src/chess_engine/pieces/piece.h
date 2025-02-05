#include "move.h"

typedef enum chess_piece_type {
  CHESS_PIECE_NONE,
  CHESS_KING,
  CHESS_QUEEN,
  CHESS_ROOK,
  CHESS_BISHOP,
  CHESS_KNIGHT,
  CHESS_PAWN
} chess_piece_type;
typedef enum chess_piece_owner { OWNER_BLACK, OWNER_WHITE } chess_piece_owner;

typedef struct chess_piece {
  chess_piece_type type;
  chess_piece_owner owner;
  int captured;
  int x;
  int y;
} chess_piece;

typedef struct chess_pawn {
  chess_piece piece;
} chess_pawn;

chess_pawn chess_pawn_initialize(int x, int y, chess_piece_owner owner);
Move chess_pawn_get_moves(chess_pawn piece);
int chess_pawn_move(chess_piece piece, int x, int y);

typedef struct chess_bishop {
  chess_piece piece;
} chess_bishop;

chess_pawn chess_bishop_initialize();
Move chess_bishop_get_moves();
void chess_bishop_move();
