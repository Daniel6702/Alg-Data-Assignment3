#include <iostream>

const int ROWS = 5;
const int COLS = 5;

bool findPath(char maze[ROWS][COLS], int x, int y) {
    if (x < 0 || x >= ROWS || y < 0 || y >= COLS || maze[x][y] == 'X') {
        return false; // Ugyldig position eller væg
    }

    if (maze[x][y] == 'E') {
        return true; // Mål nået
    }

    maze[x][y] = 'X'; // Markerer positionen for at undgå uendelig løkke

    // Rekursiv funktion til at bevæge sig i alle retninger
    if (findPath(maze, x + 1, y) || findPath(maze, x - 1, y) || findPath(maze, x, y + 1) || findPath(maze, x, y - 1)) {
        std::cout << "Position (" << x << "," << y << ") besøgt." << std::endl; // Printer positionen
        return true; // Returnerer sand, hvis der er fundet en vej
    }

    maze[x][y] = ' '; // Gendan positionen

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

    if (findPath(maze, 1, 1)) {
        std::cout << "Vej fundet!" << std::endl;
    } else {
        std::cout << "Ingen vej fundet." << std::endl;
    }

    return 0;
}
