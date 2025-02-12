#ifndef CHESS_UTIL_H
#define CHESS_UTIL_H

#include "pieces/piece.h"

typedef chess_piece *(*piece_initialize_func)(chess_piece_owner, int, int);

chess_piece_owner chess_piece_owner_from_char(char owner_char);
piece_initialize_func chess_piece_intialize_from_char(char piece_char);

#endif // !CHESS_UTIL_H
