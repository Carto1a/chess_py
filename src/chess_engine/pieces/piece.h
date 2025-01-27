typedef enum PieceType {
  NONE,
  KING,
  QUEEN,
  ROOK,
  BISHOP,
  KNIGHT,
  PAWN
} PieceType;

typedef struct Piece {
  int x;
  int y;
} Piece;
