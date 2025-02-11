#ifndef CHESS_MOVE_H
#define CHESS_MOVE_H

typedef enum chess_move_type {
  CHESS_MOVE_NONE,
  CHESS_MOVE_MOVEMENT,
  CHESS_MOVE_CAPTURE,
  CHESS_MOVE_CASTLING_QUEEN,
  CHESS_MOVE_CASTLING_KING,
  CHESS_MOVE_PROMOTE,
  CHESS_MOVE_ENPASSANT,
  CHESS_MOVE_CHECK,
  CHESS_MOVE_CHECK_MATE,
} chess_move_type;

typedef struct chess_piece chess_piece;

typedef struct chess_move {
  chess_move_type type;
  chess_piece *piece;
  int x;
  int y;
} chess_move;

chess_move *chess_move_initalize(chess_piece *piece, chess_move_type type,
                                 int x, int y);

#endif // !CHESS_MOVE_H
