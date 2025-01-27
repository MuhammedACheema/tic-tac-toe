#include <iostream>

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

class Game {
    public:
    // Game logic will go here later
    Board board;
    char currentPlayer;

    Game(){
        currentPlayer = 'X'; //Player X will always start first
    }

    void getPlayerMove() {
        int row, col;

        while (true) { // Loop until the user provides valid input
            std::cout << "Player " << currentPlayer << ", enter the row (0-2): ";
            std::cin >> row;

            std::cout << "Player " << currentPlayer << ", enter the column (0-2): ";
            std::cin >> col;

            // Check if row and column are within bounds
            if (row < 0 || row > 2 || col < 0 || col > 2) {
                std::cout << "Invalid input. Row and column must be between 0 and 2. Try again.\n";
                continue;
            }

            // Check if the position is already occupied
            if (board.array[row][col] == 'X' || board.array[row][col] == 'O') {
                std::cout << "That spot is already taken. Try another one.\n";
                continue;
            }

            // If valid, update the board and break the loop
            board.update(row, col, currentPlayer);
            break;
        }
    }

    void switchPlayer(char &currentPlayer){
        if(currentPlayer == 'X'){
            currentPlayer = 'O';
        }
        else if(currentPlayer == 'O'){
            currentPlayer = 'X';
        }

    }

    

    void playGame(){
        
        for(int i = 0; i < 10; i++){
            board.display();
            std::cout << "input a place to put your move";
            getPlayerMove();

            if(board.checkWin(currentPlayer)){
                board.display();
                std::cout << "Congrats to " << currentPlayer<< " you are the winner of the game";
                break;
            }

            if (board.isFull()){
                board.display();
                std::cout << "sorry guys its a draw";
                break;
            }

            switchPlayer(currentPlayer);

        }
        
    }
};

int main() {
    Game game; // Create a new instance of the game
    game.playGame(); // Start the game
    return 0;

}
