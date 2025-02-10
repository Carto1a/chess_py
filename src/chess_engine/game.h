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

typedef enum chess_piece_type {
  CHESS_PIECE_NONE,
  CHESS_KING,
  CHESS_QUEEN,
  CHESS_ROOK,
  CHESS_BISHOP,
  CHESS_KNIGHT,
  CHESS_PAWN
} chess_piece_type;
typedef enum chess_piece_owner { CHESS_OWNER_BLACK, CHESS_OWNER_WHITE } chess_piece_owner;

typedef struct chess_piece {
  chess_piece_type type;
  chess_piece_owner owner;
  int captured;
  int x;
  int y;
} chess_piece;

// NOTE: board tem que ser uma struct por si so, tenho que sabe a largura e
// altura do tabuleiro, se não for uma tabuleiro convencional, não sei oque eu
// vou fazer

typedef struct chess_board {
  chess_piece *board;
} chess_board;

typedef struct chess_game {
  chess_board initial_state;
  chess_piece *captured_pieces;
  chess_board state;
  void *moves;
} chess_game;

typedef struct chess_pawn {
  chess_piece piece;
} chess_pawn;

chess_pawn chess_pawn_initialize(int x, int y, chess_piece_owner owner);

chess_list_move *chess_pawn_get_moves(chess_pawn pawn, chess_piece *board);
chess_move chess_pawn_get_move(chess_pawn pawn, int x, int y);

int chess_pawn_move(chess_piece piece, chess_game board, int x, int y);
int chess_pawn_move2(chess_piece piece, chess_game board, chess_move move);

typedef struct chess_bishop {
  chess_piece piece;
} chess_bishop;

chess_pawn chess_bishop_initialize();
chess_move chess_bishop_get_moves();
void chess_bishop_move();

chess_board *chess_board_initialize();

chess_game *chess_game_initialize();
void chess_assign_move(chess_move *move, chess_game *game);

