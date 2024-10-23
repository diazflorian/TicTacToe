#include <iostream>

using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char actualPlayer = 'X';

void drawBoard() {
    for(int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) {
                cout << " | ";
            } ;
        };
        if (i < 2) {
            cout << "\n__________\n";
        };
    }
    cout << "\n";
};

bool movement(int movement) {
    if (movement < 1 || movement > 9) {
        cout << "Fuera de rango: " << movement << endl;
        return false;
    }

    int row = (movement < 4) ? 0 : (movement < 7) ? 1 : 2;
    int column = (movement == 1 || movement == 4 || movement == 7) ? 0 :
            (movement == 2 || movement == 5 || movement == 8) ? 1 : 2;

    if (board[row][column] != 'X' && board[row][column] != 'O') {
        board[row][column] = actualPlayer;
        return true;
    } else {
        cout << "Posicion ocupada. Por favor intente otra vez" << endl;
        return false;
    }
}

bool checkWin() {
    // Verifica las filas, columnas y diagonales
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == actualPlayer && board[i][1] == actualPlayer && board[i][2] == actualPlayer) ||
            (board[0][i] == actualPlayer && board[1][i] == actualPlayer && board[2][i] == actualPlayer)) {
            return true;
        }
    }
    if ((board[0][0] == actualPlayer && board[1][1] == actualPlayer && board[2][2] == actualPlayer) ||
        (board[0][2] == actualPlayer && board[1][1] == actualPlayer && board[2][0] == actualPlayer)) {
        return true;
    }
    return false;
}

void switchPlayer() {
    actualPlayer = (actualPlayer == 'X') ? 'O' : 'X';
}

int main() {
    int moveCount = 0;
    bool gameWon = false;

    while (moveCount < 9 && !gameWon) {
        drawBoard();
        int move;
        cout << "Jugador " << actualPlayer << ", ingrese el numero de la casilla donde desea jugar (1-9): ";
        cin >> move;

        if (movement(move)) {
            moveCount++;
            gameWon = checkWin();
            if (!gameWon) {
                switchPlayer();
            }
        }
    }

    drawBoard();
    if (gameWon) {
        cout << actualPlayer << " ha ganado!" << endl;
    } else {
        cout << "¡Es un empate!" << endl;
    }

    return 0;
}
