#include <iostream>

class Player {
    public:
    // Player logic will go here later
};

class Board {
    public:
        char array[3][3]; // 3x3 board
        char marker;
        int row;
        int col;

        Board() {
            char placeholder = '0'; // Start with '0'
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    array[i][j] = placeholder++;
                }
            }
        }


        // Display function
        void display() {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    std::cout << array[i][j];
                    if (j < 2) std::cout << " | "; // Add "|" between columns
                }
                std::cout << std::endl;
                if (i < 2) std::cout << "--|---|--" << std::endl; // Add row divider
            }
        }

        // Update function (to be implemented later)
        void update(int row, int col, char marker) {
            // check if they are in bound
            if(row < 0 || row > 2 || col < 0 || col > 2){
                std::cout <<"invalid input please put a valid input \n";
                return;
            }            

            // if the position is empty

            if(array[row][col] == 'X' || array[row][col] == 'O'){
                std::cout << "position already taken, use another position please \n";
                return;
            }

            // now finally update the position
            array[row][col] = marker;
            std::cout << "position updated \n";
        }

        bool isFull(){
            for(int i = 0; i < 3; i++ ){
                for (int j = 0; j < 3; j++){
                    if (array[i][j] != 'X' && array[i][j] != 'O'){
                        return false;
                    }
                }
            }

            return true;
        }

        bool checkWin(char Marker){
            // check rows

            for(int i = 0; i < 3; i++){
                if(array[i][0] == array[i][1] && array[i][1] == array[i][2]){
                    return true;
                }
            }

            // check the columns
            for(int i = 0; i < 3; i++){
                if(array[0][i] == array[1][i] && array[1][i] == array[2][i]){
                    return true;
                }
            }


            // Check diagonals
            if (array[0][0] == array[1][1] &&  array[1][1] == array[2][2]) {
                return true; // Marker wins in the up to down diagnol
            }
            if (array[0][2] == array[1][1] && array[2][0] == array[1][1]) {
                return true; // Marker wins in the down to up diagnol
            }

            // No win condition met
            return false;
        }
};

int main() {
    Board one;

    // Display the initial board
    one.display();

    // Update some positions
    one.update(0, 0, 'X');
    one.update(1, 1, 'X');
    one.update(2, 2, 'X');

    // Display the board after updates
    one.display();

    // Check if the board is full
    if (one.isFull()) {
        std::cout << "The board is full!" << std::endl;
    } else {
        std::cout << "The board is not full yet." << std::endl;
    }

    // Check if 'X' has won
    if (one.checkWin('X')) {
        std::cout << "Player X wins!" << std::endl;
    } else {
        std::cout << "No winner yet!" << std::endl;
    }

    return 0;
}
