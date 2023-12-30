#include <iostream>
#include <vector>
#include <string>

bool is_can_exit_from_maze(std::vector<std::string> maze, int r, int c) {
    if (maze[r][c] == 'E'){
        return true;
    }
    if (maze[r][c] == '#'){
        return false;
    }
    maze[r][c] = '#';
    return is_can_exit_from_maze(maze, r + 1, c) || is_can_exit_from_maze(maze, r - 1, c) || is_can_exit_from_maze(maze, r, c + 1) || is_can_exit_from_maze(maze, r, c - 1);
}

int main(){
    int row, col, rows, cols;
    std::cin >> row >> col >> rows >> cols;
    std::cin.ignore(1); // Игнорируем перевод строки, застрявший в потоке ввода
    
    std::vector<std::string> maze(rows);
    for(auto& line : maze) std::getline(std::cin, line);
    
    std::cout << (is_can_exit_from_maze(maze, row, col) ? "YES" : "NO") << std::endl;
}
