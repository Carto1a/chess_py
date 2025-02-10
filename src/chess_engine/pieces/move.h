typedef enum MoveType {
  MOVE,
  CAPTURE,
  CASTLING,
  PROMOTE,
  ENPASSANT,
  CHECK
} MoveType;

typedef enum MovePiece {
  PAWN_MOVE = 'p'
} MovePiece;

typedef struct Move {
  MovePiece piece;
  MoveType type;
  int x;
  int y;
} Move;

Move *Chess_InitMove(MovePiece piece, MoveType type, int x, int y);

typedef struct MoveList {
  Move **moves;
  int length;
  int size;
} MoveList;

MoveList *Chess_InitMoveList(int size);
void Chess_MoveList_Add(MoveList *list, Move *move);
void Chess_MoveList_Remove(MoveList *list, int index);
