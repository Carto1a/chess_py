#include "chess/pieces/pawn.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

chess_pawn *chess_pawn_initialize(chess_piece_owner owner, int x, int y) {
  chess_pawn *pawn = malloc(sizeof(chess_pawn));

  pawn->type = CHESS_PAWN;
  pawn->owner = owner;
  pawn->captured = false;
  // NOTE: check if off bound?
  pawn->x = x;
  pawn->y = y;
  pawn->game = NULL;

  pawn->get_moves = chess_pawn_get_moves;
  pawn->get_move = chess_pawn_get_move;
  pawn->move_to = chess_pawn_move_to;
  pawn->move_from_move = chess_pawn_move_from_move;

  pawn->moved = false;

  return pawn;
}

void chess_pawn_dispose(chess_pawn *pawn) { free(pawn); }

chess_list_move *chess_pawn_get_moves(chess_pawn *pawn) {
  chess_list_move *moves = chess_list_move_initialize(5);

  /* chess_move *move = chess_move_initalize(CHESS_PAWN_MOVE,
   * CHESS_MOVE_MOVEMENT, */
  /*                                         pawn.piece.x + 1, pawn.piece.y +
   * 2); */

  /* chess_list_move_append(moves, move); */

  return moves;
}

chess_move *chess_pawn_get_move(chess_pawn *pawn, int x, int y) {
  chess_move *move =
      chess_move_initalize(CHESS_MOVE_MOVEMENT, (chess_piece *)pawn, 0, 0);
  return move;
}

/* { */
/*   pawn->moved = true; */
/* } */

int chess_pawn_move_to(chess_pawn *piece, int x, int y) { return 0; }
int chess_pawn_move_from_move(chess_pawn *piece, chess_move move) { return 0; }
