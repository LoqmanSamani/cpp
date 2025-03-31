#include <iostream>
#include <ctime>




void assign(std::string (&board)[3][3], int row, int col);
void check_index(std::string board[3][3], bool &right_index, int row, int col);
void show_board(std::string board[3][3]);
void check_board(std::string board[3][3], bool &won, std::string sign);




int main() {
    srand(time(0));
    std::string board[3][3] = {
        {" ", " ", " "},
        {" ", " ", " "},
        {" ", " ", " "}
    };

    int row, col, counter = 0;
    bool tie = false, you_won = false, com_won = false;

    std::cout << "***************************************" << std::endl;
    std::cout << "*           Tik-Tak-Toe Game          *" << std::endl;
    std::cout << "***************************************" << std::endl;

    do {
        bool right_index = false;
        std::cout << "------Live Board!------" << std::endl;
        show_board(board);
        std::cout << "-------Your move!------" << std::endl;
        
        do {
            std::cout << "row index: ";
            std::cin >> row;
            std::cout << "column index: ";
            std::cin >> col;
            check_index(board, right_index, row, col);
        } while (!right_index);
        
        assign(board, row, col);
        check_board(board, you_won, "X");
        check_board(board, com_won, "O");
        counter++;

        if (!you_won && !com_won && counter == 9) {
            tie = true;
        }

    } while (!you_won && !com_won && !tie);

    show_board(board);

    if (you_won) {
        std::cout << "Congrats! You won!" << std::endl;
    } else if (com_won) {
        std::cout << "Sorry! You lost!" << std::endl;
    } else {
        std::cout << "It's a Tie!" << std::endl;
    }

    return 0;
}



void assign(std::string (&board)[3][3], int row, int col) {
    board[row][col] = "X";
    
    int count_free = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == " ") {
                count_free++;
            }
        }
    }
    
    if (count_free == 0) return;
    
    bool right = false;
    while (!right) {
        int r = rand() % 3;
        int c = rand() % 3;
        if (board[r][c] == " ") {
            board[r][c] = "O";
            right = true;
        }
    }
}



void check_index(std::string board[3][3], bool &right_index, int row, int col) {
    if (row < 0 || row > 2 || col < 0 || col > 2) {
        std::cout << "Wrong index! Try again." << std::endl;
    } else if (board[row][col] == "X" || board[row][col] == "O") {
        std::cout << "This cell is already occupied! Try again." << std::endl;
    } else {
        right_index = true;
    }
}



void show_board(std::string board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == " ") {
                std::cout << "-" << " ";
            } else {
                std::cout << board[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }
}



void check_board(std::string board[3][3], bool &won, std::string sign) {
    won = false;
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == sign && board[i][1] == sign && board[i][2] == sign) {
            won = true;
            return;
        }
    }

    for (int j = 0; j < 3; j++) {
        if (board[0][j] == sign && board[1][j] == sign && board[2][j] == sign) {
            won = true;
            return;
        }
    }

    if (board[0][0] == sign && board[1][1] == sign && board[2][2] == sign) {
        won = true;
        return;
    }

    if (board[0][2] == sign && board[1][1] == sign && board[2][0] == sign) {
        won = true;
        return;
    }
}