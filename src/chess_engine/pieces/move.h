typedef enum chess_move_type {
  CHESS_MOVE_MOVEMENT,
  CHESS_MOVE_CAPTURE,
  CHESS_MOVE_CASTLING,
  CHESS_MOVE_PROMOTE,
  CHESS_MOVE_ENPASSANT,
  CHESS_MOVE_CHECK
} chess_move_type;

typedef enum chess_move_piece {
  CHESS_PAWN_MOVE = 'p'
} chess_move_piece;

typedef struct chess_move {
  chess_move_piece piece;
  chess_move_type type;
  int x;
  int y;
} chess_move;

chess_move *chess_move_initalize(chess_move_piece piece, chess_move_type type, int x, int y);

typedef struct chess_list_move {
  chess_move **moves;
  int length;
  int size;
} chess_list_move;

chess_list_move *chess_list_move_initialize(int size);
void chess_list_move_add(chess_list_move *list, chess_move *move);
void chess_list_move_remove(chess_list_move *list, int index);
