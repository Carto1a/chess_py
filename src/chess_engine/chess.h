#include "pieces/piece.h"

// NOTE: board tem que ser uma struct por si so, tenho que sabe a largura e
// altura do tabuleiro, se não for uma tabuleiro convencional, não sei oque eu
// vou fazer

typedef struct chess_board {
  chess_piece *board;
} chess_board;

chess_board *chess_board_initialize();

typedef struct chess_game {
  chess_board initial_state;
  chess_piece *captured_pieces;
  chess_board state;
  void *moves;
} chess_game;

chess_game *chess_game_initialize();
void chess_assign_move(chess_move *move, chess_game *game);

