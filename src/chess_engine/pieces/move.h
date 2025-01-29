typedef enum MoveType {
  MOVE,
  CAPTURE,
  CASTLING,
  PROMOTE,
  ENPASSANT,
  CHECK
} MoveType;

typedef struct Move {
  MoveType type;
  int x;
  int y;
} Move;
