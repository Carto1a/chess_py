#include "util.h"
#include "pieces/pawn.h"
#include <string.h>

chess_piece_owner chess_piece_owner_from_char(char owner_char) {
  switch (owner_char) {
  case 'b':
    return CHESS_OWNER_BLACK;
  case 'w':
    return CHESS_OWNER_WHITE;
  default:
    return CHESS_OWNER_NONE;
  }
}

piece_initialize_func chess_piece_intialize_from_char(char piece_char) {
  switch (piece_char) {
  case 'p':
    return (piece_initialize_func)chess_pawn_initialize;
  default:
    return NULL;
  }
}
