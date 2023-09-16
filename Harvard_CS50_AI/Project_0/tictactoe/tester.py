from tictactoe import player,actions,result,winner,terminal,minimax

EMPTY = None
X = "X"
O = "O"

board = [[EMPTY, EMPTY, EMPTY],
            [O, X, X],
            [EMPTY, O, EMPTY]]

won_board = [[X, X, O],
            [O, O, X],
            [X, O, X]]

print(player(board))
print(actions(board))
print(result(board, (0,0)))
print(winner(won_board))
print(terminal(board))
print(minimax(board))