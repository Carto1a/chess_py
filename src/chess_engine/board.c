#include "board.h"
#include "chess.h"
#include <stdlib.h>

chess_board *chess_board_initialize();
chess_board *chess_board_initialize_from_chars(char char_board[8][8]);
chess_board *chess_board_initialize_from_file(char *file_name);

int chess_board_dispose(chess_board *board) {
  if (!board) {
    chess_set_error("Attempt to deallocate a NULL board");
    return CHESS_ERROR;
  }

  free(board);

  return CHESS_SUCESS;
}

chess_board *chess_board_duplicate(chess_board *board);
chess_piece *chess_board_get_piece(int x, int y);
