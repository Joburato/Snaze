#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

// Include necessary headers
#include "..\maze.h"  // Adjust the path relative to snake_game.h

#include <chrono>
#include <thread>
#include <iostream>

class SnakeGame {
private:
    Maze maze;
    int lives;
    int score;
    int currentLevel;
    bool gameOver;

public:
    SnakeGame(int rows, int cols, int initialLives);

    void run();
    void handleInput();
    void update();
    void render();
    void processCollision();
    void processFoodEaten();
    void checkGameOver();
    void nextLevel();

    bool isGameOver() const;
};

#endif