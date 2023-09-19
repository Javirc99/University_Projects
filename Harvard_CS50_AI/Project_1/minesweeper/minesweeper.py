import itertools
import random


class Minesweeper():
    """
    Minesweeper game representation
    """

    def __init__(self, height=8, width=8, mines=8):

        # Set initial width, height, and number of mines
        self.height = height
        self.width = width
        self.mines = set()

        # Initialize an empty field with no mines
        self.board = []
        for i in range(self.height):
            row = []
            for j in range(self.width):
                row.append(False)
            self.board.append(row)

        # Add mines randomly
        while len(self.mines) != mines:
            i = random.randrange(height)
            j = random.randrange(width)
            if not self.board[i][j]:
                self.mines.add((i, j))
                self.board[i][j] = True

        # At first, player has found no mines
        self.mines_found = set()

    def print(self):
        """
        Prints a text-based representation
        of where mines are located.
        """
        for i in range(self.height):
            print("--" * self.width + "-")
            for j in range(self.width):
                if self.board[i][j]:
                    print("|X", end="")
                else:
                    print("| ", end="")
            print("|")
        print("--" * self.width + "-")

    def is_mine(self, cell):
        i, j = cell
        return self.board[i][j]

    def nearby_mines(self, cell):
        """
        Returns the number of mines that are
        within one row and column of a given cell,
        not including the cell itself.
        """

        # Keep count of nearby mines
        count = 0

        # Loop over all cells within one row and column
        for i in range(cell[0] - 1, cell[0] + 2):
            for j in range(cell[1] - 1, cell[1] + 2):

                # Ignore the cell itself
                if (i, j) == cell:
                    continue

                # Update count if cell in bounds and is mine
                if 0 <= i < self.height and 0 <= j < self.width:
                    if self.board[i][j]:
                        count += 1

        return count

    def won(self):
        """
        Checks if all mines have been flagged.
        """
        return self.mines_found == self.mines


class Sentence():
    """
    Logical statement about a Minesweeper game
    A sentence consists of a set of board cells,
    and a count of the number of those cells which are mines.
    """

    def __init__(self, cells, count):
        self.cells = set(cells)
        self.count = count

    def __eq__(self, other):
        return self.cells == other.cells and self.count == other.count

    def __str__(self):
        return f"{self.cells} = {self.count}"

    def known_mines(self):
        """
        Returns the set of all cells in self.cells known to be mines.
        """
        
        # Only if the count of miines is equal to the number of cells (and > 0), all the cells in the set are mines:
        if len(self.cells) == self.count and self.count > 0:
            print("Mine found - ", self.cells)
            return self.cells
        else:
            return set()

    def known_safes(self):
        """
        Returns the set of all cells in self.cells known to be safe.
        """
        
        # Only if the count of miines is 0, then all cells in the sentence are safe:
        if self.count == 0:
            return self.cells
        else:
            return set()

    def mark_mine(self, cell):
        """
        Updates internal knowledge representation given the fact that
        a cell is known to be a mine.
        """
        
        # If a cell is known to be a mine, remove the cell from the set and decrement the count:
        if cell in self.cells:
            self.cells.remove(cell)
            self.count -= 1

    def mark_safe(self, cell):
        """
        Updates internal knowledge representation given the fact that
        a cell is known to be safe.
        """

        # If a cell is known to be safe, remove the cell from the set but left the count untouched:
        if cell in self.cells:
            self.cells.remove(cell)
            


class MinesweeperAI():
    """
    Minesweeper game player
    """

    def __init__(self, height=8, width=8):

        # Set initial height and width
        self.height = height
        self.width = width

        # Keep track of which cells have been clicked on
        self.moves_made = set()

        # Keep track of cells known to be safe or mines
        self.mines = set()
        self.safes = set()

        # List of sentences about the game known to be true
        self.knowledge = []

    def mark_mine(self, cell):
        """
        Marks a cell as a mine, and updates all knowledge
        to mark that cell as a mine as well.
        """
        self.mines.add(cell)
        for sentence in self.knowledge:
            sentence.mark_mine(cell)

    def mark_safe(self, cell):
        """
        Marks a cell as safe, and updates all knowledge
        to mark that cell as safe as well.
        """
        self.safes.add(cell)
        for sentence in self.knowledge:
            sentence.mark_safe(cell)

    def add_knowledge(self, cell, count):
        """
        Called when the Minesweeper board tells us, for a given
        safe cell, how many neighboring cells have mines in them.

        This function should:
            1) mark the cell as a move that has been made
            2) mark the cell as safe
            3) add a new sentence to the AI's knowledge base
               based on the value of `cell` and `count`
            4) mark any additional cells as safe or as mines
               if it can be concluded based on the AI's knowledge base
            5) add any new sentences to the AI's knowledge base
               if they can be inferred from existing knowledge
        """
        
        # Mark the cell as a move that has been made
        self.moves_made.add(cell)
        # Mark as safe
        self.mark_safe(cell)

        # Set to store undecided cells for Knowledge Base:
        new_sentence_cells = set()

        # Iterate over all cells within one row and column:
        for i in range(cell[0] - 1, cell[0]+2):
            for j in range(cell[1] - 1, cell[1]+2):

                # Ignore the cell itself or if the cell is known to be safe
                if (i,j) == cell or (i,j) in self.safes:
                    continue
                
                # If cells are known to be mines, reduce count by 1 and ignore them:
                if (i,j) in self.mines:
                    count -= 1
                    continue

                # Otherwise add them to the sentence if they are proper board cells:
                if 0 <= i < self.height and 0 <= j < self.width:
                    new_sentence_cells.add((i,j))

        # Register the new sentence into the AI's Knowledge Base:
        print(f"Move on cell: {cell} has added sentence to knowledge {new_sentence_cells} = {count}")
        self.knowledge.append(Sentence(new_sentence_cells, count))

        # Mark secured mines and safes, and infer new knowledge:
        new_knowledge = True

        while new_knowledge:
            new_knowledge = False
            
            safes = set()
            mines = set()

            for sentence in self.knowledge:
                safes = safes.union(sentence.known_safes())
                mines = mines.union(sentence.known_mines())


            # Mark safe cells or mines:
            if safes:
                new_knowledge = True
                for safe in safes:
                    self.mark_safe(safe)

            if mines:
                new_knowledge = True
                for mine in mines:
                    self.mark_mine(mine)

            # Remove possible empty sentences from KB:
            empty = Sentence(set(), 0)
            self.knowledge[:] = [x for x in self.knowledge if x != empty]

            # Infer new sentences from current ones:
            for sentence_1 in self.knowledge:
                for sentence_2 in self.knowledge:
                    
                    # Ignore the case when sentences are the same:
                    if sentence_1.cells == sentence_2.cells:
                        continue

                    # Create new sentence if 1 is subset of 2 and not in KB:
                    if sentence_1.cells.issubset(sentence_2.cells):
                        new_sentence_cells = sentence_2.cells - sentence_1.cells
                        new_sentence_count = sentence_2.count - sentence_1.count

                        new_sentence = Sentence(new_sentence_cells, new_sentence_count)

                        # Add to KB if not already included:
                        if new_sentence not in self.knowledge:
                            new_knowledge = True
                            print(f"New knowledge inferred: {new_sentence}, from {sentence_1} and {sentence_2}")
                            self.knowledge.append(new_sentence)

        # Print useful things:
        print("KB length = ", len(self.knowledge))
        print("known mines = ", self.mines)
        print("Safe moves remaining = ", self.safes -self.moves_made)
        print("----------------------------------------------")


    def make_safe_move(self):
        """
        Returns a safe cell to choose on the Minesweeper board.
        The move must be known to be safe, and not already a move
        that has been made.

        This function may use the knowledge in self.mines, self.safes
        and self.moves_made, but should not modify any of those values.
        """
        
        # Obtain a set of safe moves that haven't been played:
        available_safe_moves = self.safes - self.moves_made
        if len(available_safe_moves) > 0:
            print("Choosing a safe move from ", len(available_safe_moves)," safe moves available ")
            return random.choice(list(available_safe_moves))
        
        # No safe move can be guaranteed, return None
        else:
            return None

    def make_random_move(self):
        """
        Returns a move to make on the Minesweeper board.
        Should choose randomly among cells that:
            1) have not already been chosen, and
            2) are not known to be mines
        """
        
        # dict to save moves and mine probability
        possible_moves = {}
        # At most, there can be 8 mines
        MAX_MINES = 8

        # Probability of any cell being a mine
        mines_left = MAX_MINES - len(self.mines)
        # total cells - (mines + safes)
        cells_left = (self.height * self.width) - (len(self.mines) + len(self.safes))

        # If there are no cells left, there aren't possible moves to do:
        if cells_left == 0:
            return None
        
        probability = mines_left / cells_left

        # List of all posible moves that are not mines
        for i in range(self.height):
            for j in range(self.width):
                if (i,j) not in self.moves_made and (i,j) not in self.mines:
                    possible_moves[(i,j)] = probability

        # If there are possible moves and we have no knowledge base, choose any move:
        if possible_moves and not self.knowledge:
            move = random.choice(list(possible_moves.keys()))
            print("AI chose the move without Knowledge Base: ", move)
            return move
        
        # On the other side, if we have knowledge base, the choice can be improved:
        elif possible_moves:
            for sentence in self.knowledge:
                n_cells = len(sentence.cells)
                count   = sentence.count
                probability_of_mine = count / n_cells

                # If the probability of mine is greater than the basic one calculated before, update it:
                for cell in sentence.cells:
                    if probability_of_mine > possible_moves[cell]:
                        possible_moves[cell] = probability_of_mine

                # Choose the move with lowest mine probability:
                moves_list = [[x, possible_moves[x]] for x in possible_moves]
                # sort the list so they are ordered from lowest prob to highest
                moves_list.sort(key=lambda x: x[1])
                lowest_prob = moves_list[0][1]

                best_moves = [x for x in moves_list if x[1] == lowest_prob]
                chosen_move = random.choice(best_moves)[0]
                print("AI chose the move with Knowledge Base: ", chosen_move)

                return chosen_move





