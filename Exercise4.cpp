#include <iostream>

const int ROWS = 5;
const int COLS = 5;


bool findPath(char maze[ROWS][COLS], int x, int y) {
    // to ensure that we dont check an invalid position, we have these limits
    if (x < 0 || x >= ROWS || y < 0 || y >= COLS || maze[x][y] == 'X') {
        return false;
    }
    // if we find the position of "E" we return true 
    if (maze[x][y] == 'E') {
        std:: cout << "Goal reached at (" << x << "," << y << ")" << std::endl;
        return true;
    }
    // Marks the position to "X" so we dont go in a loop
    maze[x][y] = 'X'; 
    // recursive movemeent function, so it continues until target reached
    if (findPath(maze, x + 1, y) || findPath(maze, x - 1, y) || findPath(maze, x, y + 1) || findPath(maze, x, y - 1)) {
        std::cout << "Position (" << x << "," << y << ") visited." << std::endl;
        return true; 
    }
    // We back trace on of the code on line 18
    maze[x][y] = ' '; 

    return false;
}

int main() {
    char maze[ROWS][COLS] = {
        {'X','X','X','X','X'},
        {'X',' ',' ',' ','X'},
        {'X',' ','X',' ','X'},
        {'X',' ','X',' ','X'},
        {'X','E','X','X','X'}
    };

    if (findPath(maze, 3, 3)) {
        std::cout << "Path Found!" << std::endl;
    } 
    else {
        std::cout << "No Path Found." << std::endl;
    }
    return 0;
}
