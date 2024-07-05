#include "Snaze\snake_game.h"  // Adjust the path as per your project structure
#include <iostream>
#include <vector>
#include <filesystem>

namespace fs = std::filesystem;

void game_loop(const std::vector<std::string>& maze_files, int food_count);

int main(int argc, char* argv[]) {
    std::cout << ">>> Program started with " << argc << " arguments.\n";
    if (argc != 4) {
        std::cout << ">>> Incorrect number of arguments!\n"
            << "    Syntax: Snaze.exe <folder for mazes> --food <food>\n\n";
        return 1;
    }

    std::string input_path = argv[1];
    int food_count = 0;

    // Parse arguments
    if (std::string(argv[2]) == "--food") {
        food_count = std::stoi(argv[3]);
    }
    else {
        std::cout << ">>> Expected --food argument!\n"
            << "    Syntax: Snaze.exe <folder for mazes> --food <food>\n\n";
        return 1;
    }

    if (food_count <= 0 || input_path.empty()) {
        std::cout << ">>> Incorrect arguments!\n"
            << "    Syntax: Snaze.exe <folder for mazes> --food <food>\n\n";
        return 1;
    }

    // Collect maze files from the folder
    std::vector<std::string> maze_files;
    for (const auto& entry : fs::directory_iterator(input_path)) {
        if (entry.path().extension() == ".dat") {
            maze_files.push_back(entry.path().string());
        }
    }

    if (maze_files.empty()) {
        std::cerr << "--> No maze files found in the specified folder!\n";
        return 1;
    }

    // Run the game loop
    game_loop(maze_files, food_count);

    return 0;
}

void game_loop(const std::vector<std::string>& maze_files, int food_count) {
    for (const auto& file : maze_files) {
        // Implement your game logic here
        std::cout << "Processing maze file: " << file << "\n";
        std::cout << "Food Count: " << food_count << "\n";
    }
}
