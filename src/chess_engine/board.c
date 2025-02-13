#include "board.h"
#include "chess.h"
#include "util.h"
#include <stdlib.h>
#include <string.h>

chess_board *chess_board_initialize() {
  chess_board *board = malloc(sizeof(chess_board));
  if (!board) {
    chess_set_error("Memory allocation failed for board");
    return NULL;
  }

  const int board_width = 8;
  chess_piece **pieces =
      malloc(sizeof(chess_piece *) * board_width * board_width);
  if (!pieces) {
    chess_set_error("Memory allocation failed for pieces");
    return NULL;
  }

  board->pieces = pieces;

  return board;
}

// NOTE: sindo que da para melhorar
chess_board *chess_board_initialize_from_string(char *string_board) {
  chess_board *board = chess_board_initialize();

  const int buffer_size = 3;
  char *piece_token_buffer = malloc(sizeof(char) * buffer_size);
  if (!piece_token_buffer) {
    chess_set_error("Memory allocation failed for piece_token");
    return NULL;
  }

  int x = 0;
  int y = 0;
  const int string_board_len = strlen(string_board);

  for (int i = 0; string_board_len < i; i++) {
    if (x > 8 || y > 8) {
      chess_set_error("Parse failed: offbounds");
      goto chess_board_initialize_from_file_failed;
    }

    if (strncpy_s(piece_token_buffer, 3, &string_board[i], 2)) {
      chess_set_error("Parse failed: Copy operation failed for piece_token");
      goto chess_board_initialize_from_file_failed;
    }

    if (!piece_token_buffer[0])
      break;

    if (piece_token_buffer[0] == ' ') {
      if (piece_token_buffer[1] == ' ') {
        chess_set_error("Parse failed: Too many white spaces on char: %d", i);
        goto chess_board_initialize_from_file_failed;
      }

      i++;
      continue;
    }

    if (piece_token_buffer[0] == '\n') {
      x = 0;
      y += 1;
      continue;
    }

    if (piece_token_buffer[0] == '0') {
      if (piece_token_buffer[1] == '0') {
        i++;

        if (!chess_board_set_piece(board, NULL, x, y)) {
          chess_set_error("Parse failed: Cannot set piece of char: %d %c", i,
                          piece_token_buffer[1]);
          goto chess_board_initialize_from_file_failed;
        }

        x += 1;
        continue;
      }

      chess_set_error(
          "Parse failed: Need to be two zeros for blank space on char: %d %c",
          i, piece_token_buffer[1]);
      goto chess_board_initialize_from_file_failed;
    }

    chess_piece_owner piece_owner =
        chess_piece_owner_from_char(piece_token_buffer[1]);
    if (!piece_owner) {
      chess_set_error("Parse failed: Unable to determine owner of char: %d %c",
                      i, piece_token_buffer[1]);
      goto chess_board_initialize_from_file_failed;
    }

    piece_initialize_func initialize_func =
        chess_piece_intialize_from_char(piece_token_buffer[0]);
    if (!initialize_func) {
      chess_set_error("Parse failed: Unable to determine piece on char: %d %c",
                      i, piece_token_buffer[0]);
      goto chess_board_initialize_from_file_failed;
    }

    chess_piece *piece = initialize_func(piece_owner, x, y);
    i++;
    x += 1;
  }

  free(piece_token_buffer);

  return board;

chess_board_initialize_from_file_failed:
  free(piece_token_buffer);
  free(board);
  return NULL;
}

void chess_board_dispose(chess_board *board) {
  free(board->pieces);
  free(board);
}

chess_board *chess_board_duplicate(const chess_board *src_board) {
  if (!src_board) {
    chess_set_error("Attempt to duplicate a NULL board");
    return NULL;
  }

  chess_board *dest_board = chess_board_initialize();

  const int board_width = 8;
  memcpy(dest_board->pieces, src_board->pieces,
         sizeof(chess_piece *) * board_width * board_width);

  return dest_board;
}

chess_piece *chess_board_get_piece(const chess_board *board, unsigned int x,
                                   unsigned int y) {
  int board_width = 8;

  if (x < 0 || x > 8) {
    chess_set_error(
        "Invalid x provided. x must be greater zero or less than eight");
    return NULL;
  }

  if (y < 0 || y > 8) {
    chess_set_error(
        "Invalid x provided. x must be greater zero or less than eight");
    return NULL;
  }

  return board->pieces[x + (y * board_width)];
}
