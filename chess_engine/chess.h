#ifndef CHESS_H
#define CHESS_H

#define CHESS_ERROR 0
#define CHESS_SUCESS 1

void chess_set_error(const char *fmt, ...);
const char *chess_get_error();

#endif // !CHESS_H
