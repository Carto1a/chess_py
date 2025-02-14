#include "chess/game.h"
#include "chess/board.h"
#include "chess/chess.h"
#include "chess/move/list_move.h"
#include <stdlib.h>

chess_game *chess_game_intialize(chess_board *initial_state) {
  if (!initial_state) {
    chess_set_error("Invalid initial state provided. NULL pointer");
    return CHESS_ERROR;
  }

  chess_game *game = malloc(sizeof(chess_game));

  game->initial_state = chess_board_duplicate(initial_state);
  game->atual_state = chess_board_duplicate(initial_state);

  // TODO: fazer uma lista dinâmica
  game->captured_pieces = NULL;
  game->moves = chess_list_move_initialize(100);

  return game;
}

void chess_game_dispose(chess_game *game) {
  chess_board_dispose(game->initial_state);
  chess_board_dispose(game->atual_state);
  chess_list_move_dispose(game->moves);
  free((chess_piece *)game->captured_pieces);
  free(game);
}
