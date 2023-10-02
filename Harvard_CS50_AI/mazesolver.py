import time
import matplotlib.pyplot as plt
import numpy as np
from collections import deque
from pathfinding.core.diagonal_movement import DiagonalMovement
from pathfinding.core.grid import Grid
from pathfinding.finder.a_star import AStarFinder


# Define the maze as a 2D list
import random

def generate_maze(width, height):
    maze = [['1' for _ in range(width)] for _ in range(height)]

    def is_valid(x, y):
        return 0 <= x < width and 0 <= y < height

    stack = [(random.randrange(0, width, 2), random.randrange(0, height, 2))]

    while stack:
        x, y = stack[-1]
        maze[y][x] = 0

        # Get unvisited neighbors
        neighbors = [(x + dx, y + dy) for dx, dy in [(2, 0), (-2, 0), (0, 2), (0, -2)]]
        random.shuffle(neighbors)

        unvisited_neighbors = [(nx, ny) for nx, ny in neighbors if is_valid(nx, ny) and maze[ny][nx] == 1]

        if unvisited_neighbors:
            nx, ny = unvisited_neighbors[0]
            mx, my = (x + nx) // 2, (y + ny) // 2
            maze[my][mx] = 0
            stack.append((nx, ny))
        else:
            stack.pop()

    return maze

maze = generate_maze(50, 50)

# Define the start and end points
start = (0, 0)
end = (49, 49)

# Define the four possible movements in the maze
moves = [(0, -1), (-1, 0), (0, 1), (1, 0)]

def is_valid_move(maze, move):
    return (move[0] >= 0 and move[0] < len(maze) and 
            move[1] >= 0 and move[1] < len(maze[0]) and 
            maze[move[0]][move[1]] == 0)

def dfs(maze, start, end):
    stack = [(start, [start])]
    while stack:
        (vertex, path) = stack.pop()
        for move in moves:
            next_vertex = (vertex[0] + move[0], vertex[1] + move[1])
            if is_valid_move(maze, next_vertex) and next_vertex not in path:
                if next_vertex == end:
                    return path + [next_vertex]
                stack.append((next_vertex, path + [next_vertex]))

def bfs(maze, start, end):
    queue = deque([(start, [start])])
    while queue:
        (vertex, path) = queue.popleft()
        for move in moves:
            next_vertex = (vertex[0] + move[0], vertex[1] + move[1])
            if is_valid_move(maze, next_vertex) and next_vertex not in path:
                if next_vertex == end:
                    return path + [next_vertex]
                queue.append((next_vertex, path + [next_vertex]))

# Compare the time taken by DFS and BFS
start_time = time.time()
dfs_path = dfs(maze, start, end)
print("DFS took", time.time() - start_time)

start_time = time.time()
bfs_path = bfs(maze, start, end)
print("BFS took", time.time() - start_time)

# Create a grid from the maze for A*
grid = Grid(matrix=maze)

# Define the start and end points for A*
start_node = grid.node(start[0], start[1])
end_node = grid.node(end[0], end[1])

# Create an A* finder and find the path
finder = AStarFinder(diagonal_movement=DiagonalMovement.never)
start_time = time.time()
a_star_path, runs = finder.find_path(start_node, end_node, grid)
print("A* took", time.time() - start_time)

# Convert paths to numpy arrays for plotting
dfs_path_np = np.array(dfs_path).T
bfs_path_np = np.array(bfs_path).T
a_star_path_np = np.array(a_star_path).T

print(a_star_path_np)

# Plot the maze and paths
plt.figure(figsize=(10, 10))
# plt.imshow(maze, cmap='binary')
plt.plot(dfs_path_np[1], dfs_path_np[0], color='orange', label='DFS')
plt.plot(bfs_path_np[1], bfs_path_np[0], color='blue', label='BFS')
plt.plot(a_star_path_np[1], a_star_path_np[0], color='green', label='A*')
plt.legend()
plt.show()
