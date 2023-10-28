#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>

using namespace std;

const int width = 40;
const int height = 20;
int birdX, birdY;
int gravity = 1;
bool gameOver = false;

// Function to initialize the game
void InitializeGame() {
    srand(time(nullptr));
    birdX = 5;
    birdY = height / 2;
}

// Function to update the game state
void UpdateGame() {
    if (!gameOver) {
        birdY += gravity;
    }

    if (birdY >= height) {
        birdY = height;
        gameOver = true;
    }
}

// Function to render the game
void RenderGame() {
    system("cls");

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == birdX && i == birdY) {
                cout << "B"; // Bird
            } else if (i == height - 1) {
                cout << "="; // Ground
            } else {
                cout << " "; // Empty space
            }
        }
        cout << endl;
    }
}

//int main() {
//    InitializeGame();
//
//    while (true) {
//        UpdateGame();
//        RenderGame();
//
//        if (_kbhit()) {
//            char input;
//            input = _getch();
//
//            if (input == ' ') {
//                birdY -= 4; // Flap the bird by moving it up
//            } else if (input == 'q' || input == 'Q') {
//                return 0; // Quit the game
//            }
//        }
//
//        if (gameOver) {
//            cout << "Game Over!" << endl;
//            break;
//        }
//
//        // Introduce a delay to control the frame rate
//        // Sleep(100); // Uncomment and include <windows.h> for Windows
//    }
//
//    return 0;
//}
