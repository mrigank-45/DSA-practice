N = 8

class State:
    def __init__(self, board):

        self.board = board

        self.cost = self.calculate_cost()

    def calculate_cost(self):

        cost = 0

        for i in range(N):
            for j in range(i + 1, N):
                if self.board[i] == self.board[j] or abs(self.board[i] - self.board[j]) == abs(i - j):
                    cost += 1
        return cost

    def get_neighbors(self):

        neighbors = []
        for i in range(N):
            for j in range(N):
                if j != self.board[i]:

                    new_board = self.board.copy()
                    new_board[i] = j

                    new_state = State(new_board)

                    neighbors.append(new_state)
        return neighbors

import random

def generate_random_state():

    board = [random.randint(0, N - 1) for _ in range(N)]

    state = State(board)
    return state

def hill_climb_search():

    current_state = generate_random_state()

    while True:

        neighbors = current_state.get_neighbors()

        best_neighbor = min(neighbors, key=lambda x: x.cost)

        if best_neighbor.cost < current_state.cost:
            current_state = best_neighbor

        else:
            return current_state

def print_state(state):
    

    for i in range(N):

        for j in range(N):

            if state.board[i] == j:
                print("Q", end=" ")
            else:
                print(".", end=" ")
        print()

result = hill_climb_search()
print("Cost:", result.cost)
print("Board:")
print_state(result)
