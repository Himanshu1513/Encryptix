#include <iostream>

using namespace std;

char gameBoard[3][3] = { {'1', '2', '3'},
                         {'4', '5', '6'},
                         {'7', '8', '9'} };

char currentMarker;
int currentPlayer;

void displayBoard() {
    cout << " " << gameBoard[0][0] << " | " << gameBoard[0][1] << " | " << gameBoard[0][2] << "\n";
    cout << "---|---|---\n";
    cout << " " << gameBoard[1][0] << " | " << gameBoard[1][1] << " | " << gameBoard[1][2] << "\n";
    cout << "---|---|---\n";
    cout << " " << gameBoard[2][0] << " | " << gameBoard[2][1] << " | " << gameBoard[2][2] << "\n";
}

bool setMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (gameBoard[row][col] != 'X' && gameBoard[row][col] != 'O') {
        gameBoard[row][col] = currentMarker;
        return true;
    } else {
        return false;
    }
}

int checkWinner() {
    for (int i = 0; i < 3; i++) {
        if (gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][1] == gameBoard[i][2]) return currentPlayer;
        if (gameBoard[0][i] == gameBoard[1][i] && gameBoard[1][i] == gameBoard[2][i]) return currentPlayer;
    }
    if (gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2]) return currentPlayer;
    if (gameBoard[0][2] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][0]) return currentPlayer;

    return 0;
}

void changePlayerAndMarker() {
    currentMarker = (currentMarker == 'X') ? 'O' : 'X';
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
}

void startGame() {
    cout << "Player 1, choose your marker (X or O): ";
    char markerP1;
    cin >> markerP1;

    currentPlayer = 1;
    currentMarker = markerP1;

    displayBoard();

    int winner = 0;

    for (int i = 0; i < 9; i++) {
        cout << "Player " << currentPlayer << ", enter your slot: ";
        int slot;
        cin >> slot;

        if (slot < 1 || slot > 9) {
            cout << "Invalid slot! Please choose a slot between 1 and 9.\n";
            i--;
            continue;
        }

        if (!setMarker(slot)) {
            cout << "Slot occupied! Choose another slot.\n";
            i--;
            continue;
        }

        displayBoard();

        winner = checkWinner();

        if (winner == 1) { cout << "Player 1 wins! Congratulations!\n"; break; }
        if (winner == 2) { cout << "Player 2 wins! Congratulations!\n"; break; }

        changePlayerAndMarker();
    }

    if (winner == 0) cout << "It's a tie game!\n";
}

int main() {
    startGame();
}
