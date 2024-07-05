#ifndef MAZE_H
#define MAZE_H

#include <vector>

struct Position {
    int row, col;
    Position(int r = 0, int c = 0) : row{ r }, col{ c } { }
};

enum direction_t : int { UP, DOWN, LEFT, RIGHT };

class Maze {
private:
    std::vector<std::vector<int>> m_maze;
    Position m_snakeHead;

public:
    Maze();

    const std::vector<std::vector<int>>& getGrid() const;

    bool allFoodEaten() const;
    Position getSnakeHead() const;
    bool isCollision() const;
    bool isFood(Position pos) const;
    void moveSnake(Position new_pos);
    void placeFood(Position pos);
    void placeSnake(Position pos);
    void removeFood(Position pos);

    int get_width() const { return m_maze[0].size(); }
    int get_height() const { return m_maze.size(); }
};

#endif // MAZE_H
