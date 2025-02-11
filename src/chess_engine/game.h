#ifndef CHESS_GAME_H
#define CHESS_GAME_H

#include "board.h"
#include "move/list_move.h"

typedef struct chess_game {
  chess_board initial_state;
  chess_board atual_state;
  chess_piece **captured_pieces;
  chess_list_move *moves;
} chess_game;

#endif // !CHESS_GAME_H
