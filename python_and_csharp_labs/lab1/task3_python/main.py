class Piece:
    def __init__(self, name, color, position):
        self.name = name
        self.color = color
        self.position = position
        self.is_attacked = False

    def __repr__(self):
        return f"{self.color} {self.name} at {self.position}"

    def can_attack(self, x, y):
        pass

    def get_attackable_pieces(self, board):
        attackable = []
        for piece in board.pieces:
            if piece.color != self.color and self.can_attack(*piece.position): # Розпакували кортеж
                piece.is_attacked = True
                attackable.append(piece)
        return attackable
    
class Queen(Piece):
    def can_attack(self, x, y):
        x0, y0 = self.position
        return x0 == x or y0 == y or abs(x0 - x) == abs(y0 - y)

class Rook(Piece):
    def can_attack(self, x, y):
        x0, y0 = self.position
        return x0 == x or y0 == y

class Bishop(Piece): # Слон
    def can_attack(self, x, y):
        x0, y0 = self.position
        return abs(x0 - x) == abs(y0 - y)

class Board:
    def __init__(self):
        self.pieces = []

    def show(self):
        for piece in self.pieces:
            print(piece)

    def add_piece(self, new_piece):
        x, y = new_piece.position

        if not (1 <= x <= 8 and 1 <= y <= 8):
            raise ValueError(f"{piece} за межами дошки")
        
        for piece in self.pieces:
            if piece.position == new_piece.position:
                raise ValueError(f"Клітина {new_piece.pos} вже зайнята {piece}")
            
        self.pieces.append(new_piece)

    @staticmethod
    def read_coord(name): 
        x, y = map(int, input(f"Введіть координати {name} у форматі x y (цілі 1..8): ").split())
        return (x, y)
    
def tick(active_piece, board):
    attackable = active_piece.get_attackable_pieces(board)
    messages = {}

    if not attackable:
        for piece in board.pieces:
            messages.setdefault(piece, []).append("Простий хід")

    for target in attackable:
        messages.setdefault(active_piece, []).append(f"Здійснює напад на {target.name}")

    for piece in board.pieces:
        for target in attackable:
            if (piece != active_piece 
                and piece != target
                and piece.color != active_piece.color 
                and piece.can_attack(*target.position)):
                messages.setdefault(piece, []).append(f"Захищає {target.name}")
        if piece not in messages:
            messages[piece] = ["Простий хід"]

    return messages

def main():
    board = Board()
    try:
        # wq_pos = board.read_coord("Білого ферзя")
        # wr_pos = board.read_coord("Білої тури")
        # bb_pos = board.read_coord("Чорного слона")
        wq_pos = (1, 1)
        wr_pos = (8, 1)
        bb_pos = (7, 2)

        white_queen = Queen("White queen", "white", wq_pos)
        white_rook = Rook("White rook", "white", wr_pos)
        black_bishop = Bishop("Black bishop", "black", bb_pos)

        board.add_piece(white_queen)
        board.add_piece(white_rook)
        board.add_piece(black_bishop)

        board.show()

        pieces_dict = {
            "1": white_queen,
            "2": white_rook,
            "3": black_bishop
        }
        choice = input("Виберіть фігуру для першого ходу (1-Queen, 2-Rook, 3-Bishop): ")
        active_piece = pieces_dict.get(choice)
        if not active_piece:
            print("Некоректний вибір фігури")
            return

        results = tick(active_piece, board)
        for piece, actions in results.items():
            print(f"{piece.name} ({piece.color}):")
            for action in actions:
                print(f"  - {action}")

    except ValueError as exception:
        print("Помилка:", exception)
        return

if __name__ == "__main__":
    main()
