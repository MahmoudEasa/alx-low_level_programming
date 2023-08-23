#!/usr/bin/python3
"""Create a function def island_perimeter(grid):
    that returns the perimeter of the island described in grid
"""


def island_perimeter(grid):
    """Function to returns the perimeter of the island described in grid
    """
    perimeter = 0

    if isinstance(grid, list) and all(isinstance(i, list) for i in grid):
        row = len(grid)
        col = len(grid[0])

        for r in range(row):
            for c in range(col):
                if grid[r][c] == 1:
                    if r > 0:
                        if grid[r - 1][c] == 0:
                            perimeter += 1
                    if r < row - 1:
                        if grid[r + 1][c] == 0:
                            perimeter += 1
                    if c > 0:
                        if grid[r][c - 1] == 0:
                            perimeter += 1
                    if c < col - 1:
                        if grid[r][c + 1] == 0:
                            perimeter += 1

    return (perimeter)
