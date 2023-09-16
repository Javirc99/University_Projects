"""
Tic Tac Toe Player
"""

import math
import copy

X = "X"
O = "O"
EMPTY = None

def initial_state():
    """
    Returns starting state of the board.
    """
    return [[EMPTY, EMPTY, EMPTY],
            [EMPTY, EMPTY, EMPTY],
            [EMPTY, EMPTY, EMPTY]]


def player(board):
    """
    Returns player who has the next turn on a board.
    """
    count_x = 0
    count_o = 0
    for i in range(3):
        for j in range(3):
            if board[i][j] == X:
                count_x += 1
            if board[i][j] == O:
                count_o += 1

    # Looking at the amount of X or O placed we can know whose turn it is
    if count_x > count_o:
        return O
    else:
        return X

def actions(board):
    """
    Returns set of all possible actions (i, j) available on the board.
    """
    allactions = set()

    # Iterate over the whole board
    for i in range(3):
        for j in range(3):
            # If the cell is ocuppied do nothing
            if board[i][j] == X or board[i][j] == O:
                pass
            # Otherwise, add the cell
            else:
                allactions.add((i,j))
    
    return allactions

def result(board, action):
    """
    Returns the board that results from making move (i, j) on the board.
    """
    if action[0] > 2 or action[0] < 0 or action[1] > 2 or action[1] < 0:
        raise Exception("Action not allowed")
    
    # Deepcopying the board
    auxboard = copy.deepcopy(board)
    
    # Acknowledging the player's turn and making the move
    turn = player(auxboard)
    auxboard[action[0]][action[1]] = turn

    # Returning the modified auxiliary board
    return auxboard


def winner(board):
    """
    Returns the winner of the game, if there is one.
    """
    # Checking for wins vertically:
    for i in range(3):
        counter3X = 0 
        counter3O = 0
        for j in range(3):
            if board[i][j] is not None:
                if board[i][j] == X:
                    counter3X += 1
                else:
                    counter3O += 1

        if counter3X == 3:
            return X
        if counter3O == 3:
            return O

    # Checking for wins horizontally:
    for i in range(3):
        counter3X = 0 
        counter3O = 0
        for j in range(3):
            if board[j][i] is not None:
                if board[j][i] == X:
                    counter3X += 1
                else:
                    counter3O += 1

        if counter3X == 3:
            return X
        if counter3O == 3:
            return O
        
    # Checking for wins diagonally:
    if (board[0][0] == X and board[1][1] == X and board[2][2] == X) or \
        ((board[0][2] == X and board[1][1] == X and board[2][0] == X)):
        return X
    if (board[0][0] == O and board[1][1] == O and board[2][2] == O) or \
    ((board[0][2] == O and board[1][1] == O and board[2][0] == O)):
        return O

    # No winner yet or a tie
    return None


def terminal(board):
    """
    Returns True if game is over, False otherwise.
    """
    # Checking if there is a winner:
    if winner(board) is not None:
        print("winner")
        return True
    
    # Checking if every cell is filled with a tie
    else:
        if all(EMPTY not in row for row in board):
            print("tie")
            return True
        
    # Otherwise, game is still in progress:
    return False
    


def utility(board):
    """
    Returns 1 if X has won the game, -1 if O has won, 0 otherwise.
    """
    # Assuming we have a terminal board we only need to check for the winner
    winner_player = winner(board)

    if winner_player == X:
        return 1
    elif winner_player == O:
        return -1
    else:
        return 0

# Functions for max and min players
def min_value(board):
    if terminal(board):
        return utility(board)
    
    v = math.inf
    
    for action in actions(board):
        v = min(v, min_value(result(board, action)))

    return v

def max_value(board):

    if terminal(board):
        return utility(board)
    
    v = -math.inf
    
    for action in actions(board):
        v = max(v, min_value(result(board, action)))
        
    return v
    


def minimax(board):
    """
    Returns the optimal action for the current player on the board.
    """
    # if terminal board is received return 'None':
    if terminal(board):
        return None

    # General Minimax implementation using auxiliary functions
    
    # Supposing X is max player:
    if player(board) == X:
        moves = []
        # Consider all the posible actions
        for action in actions(board):
            # Add the "score or value" of the min_value and the action that induced it
            moves.append([min_value(result(board, action)), action])

        # Finding the optimal action
        new_value = -float('inf')  # Initialize min_value to negative infinity
        optimal_action = None

        for value, action in moves:
            if value > new_value:
                new_value = value
                optimal_action = action
        
        return optimal_action
    
    # Supposing O is min player:
    if player(board) == O:
        moves = []
        # Consider all the posible actions
        for action in actions(board):
            # Add the "score or value" of the min_value and the action that induced it
            moves.append([max_value(result(board, action)), action])

        # Finding the optimal action
        new_value = float('inf')  # Initialize min_value to positive infinity
        optimal_action = None

        for value, action in moves:
            if value < new_value:
                new_value = value
                optimal_action = action
        
        return optimal_action
