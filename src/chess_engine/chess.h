typedef struct chess_piece {
  chess_piece_type type;
  chess_piece_owner owner;
  int captured;
  int x;
  int y;
} chess_piece;

// colocar em pawn.h
typedef struct chess_pawn {
  chess_piece piece;
  chess_list_move (*get_moves)(struct chess_pawn, chess_piece);
  chess_move (*get_move)(struct chess_pawn, chess_piece, int, int);
  int (*move)(chess_pawn, chess_game, int, int);
} chess_pawn;

chess_pawn chess_pawn_initialize(int x, int y, chess_piece_owner owner);
chess_list_move *chess_pawn_get_moves(chess_pawn pawn, chess_piece *board);
chess_move chess_pawn_get_move(chess_pawn pawn, chess_piece *board, int x, int y);

int chess_pawn_move(chess_piece piece, chess_game board, int x, int y);
//
