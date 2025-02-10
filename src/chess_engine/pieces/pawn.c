#include "piece.h"

chess_pawn chess_pawn_initialize(int x, int y, chess_piece_owner owner) {

}

chess_list_move *chess_pawn_get_moves(chess_pawn pawn, chess_piece *board) {
  chess_list_move *moves = chess_list_move_initialize(5);

  chess_move *move = chess_move_initalize(CHESS_PAWN_MOVE, CHESS_MOVE_MOVEMENT, pawn.piece.x + 1, pawn.piece.y + 2);

  chess_list_move_add(moves, move);

  return moves;
}

int chess_pawn_move(chess_piece piece, int x, int y) {
  
}


