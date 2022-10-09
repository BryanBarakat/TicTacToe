#include <iostream>
#include <cctype>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

std::vector<string> board = {"","","","","","","","",""};
int win = 0;


void introduction(){
    std::cout << "===========================================================================================================================================\n";
    std::cout << "                                                                Tic Tac Toe\n";
    std::cout << "===========================================================================================================================================\n\n";
    std::cout << "Hello,Welcome to the Tic Tac Toe Game!\n";
    std::cout << "Here is the game board.numbers on it allow you to know each position of each square to decide what your next move will be.\n\n";
    std::cout << "                                                     --------------------------------\n";
    std::cout << "                                                     |         |          |         |\n";
    std::cout << "                                                     |    1    |     2    |    3    |\n";
    std::cout << "                                                     |         |          |         |\n";
    std::cout << "                                                     |------------------------------|\n";
    std::cout << "                                                     |         |          |         |\n";
    std::cout << "                                                     |    4    |     5    |    6    |\n";
    std::cout << "                                                     |         |          |         |\n";
    std::cout << "                                                     --------------------------------\n";
    std::cout << "                                                     |         |          |         |\n";
    std::cout << "                                                     |    7    |     8    |    9    |\n";
    std::cout << "                                                     |         |          |         |\n";
    std::cout << "                                                     --------------------------------\n";
}

bool winner(){
    bool winner = false;

    //rows

    if(board[0] != "" && board[1] != "" && board[2] != ""){
        winner = true;
    }
    else if(board[3] != "" && board[4] != "" && board[5] != ""){
        winner = true;
    }
    else if(board[6] != "" && board[7] != "" && board[8] != ""){
        winner = true;
    }

    //columns

    else if(board[0] != "" && board[3] != "" && board[6] != ""){
        winner = true;
    }
    else if(board[1] != "" && board[4] != "" && board[7] != ""){
        winner = true;
    }
    else if(board[2] != "" && board[5] != "" && board[8] != ""){
        winner = true;
    }
    else if(board[0] != "" && board[4] != "" && board[8] != ""){
        winner = true;
    }
    else if(board[2] != "" && board[4] != "" && board[6] != ""){
        winner = true;
    }

    return winner;
}

void is_winner(){

    int winnerX = 0;
    int winnerO = 0;
    if(board[0] != "X" && board[1] != "X" && board[2] != "X"){
        winnerX++;
    }
    else if(board[3] != "X" && board[4] != "X" && board[5] != "X"){
        winnerX++;
    }
    else if(board[6] != "X" && board[7] != "X" && board[8] != "X"){
        winnerX++;
    }

    //columns

    else if(board[0] != "X" && board[3] != "X" && board[6] != "X"){
        winnerX++;
    }
    else if(board[1] != "X" && board[4] != "X" && board[7] != "X"){
        winnerX++;
    }
    else if(board[2] != "X" && board[5] != "X" && board[8] != "X"){
        winnerX++;
    }
    else if(board[0] != "X" && board[4] != "X" && board[8] != "X"){
        winnerX++;
    }
    else if(board[2] != "X" && board[4] != "X" && board[6] != "X"){
        winnerX++;
    }

    else if(board[0] != "" && board[1] != "" && board[2] != ""){
        winnerO++;
    }
    else if(board[3] != "" && board[4] != "" && board[5] != ""){
        winnerO++;
    }
    else if(board[6] != "" && board[7] != "" && board[8] != ""){
        winnerO++;
    }

    //columns

    else if(board[0] != "" && board[3] != "" && board[6] != ""){
        winnerO++;
    }
    else if(board[1] != "" && board[4] != "" && board[7] != ""){
        winnerO++;
    }
    else if(board[2] != "" && board[5] != "" && board[8] != ""){
        winnerO++;
    }
    else if(board[0] != "" && board[4] != "" && board[8] != ""){
        winnerO++;
    }
    else if(board[2] != "" && board[4] != "" && board[6] != ""){
        winnerO++;
    }

    if(winnerO != 0 && winnerX == 0){
        std::cout << "O is the winner!";
    }
    else if(winnerO == 0 && winnerX != 0){
        std::cout << "X is the winner!";
    }
    else{
        std::cout << "It is a tie!";
    }
}

int userChoice(){
    srand(time(NULL));
    int num1 = rand() % 9;
    return num1;
}

void retry(){
    std::cout << "Retry,this spot is already taken" << "\n";
}

bool spotTaken(int n){
    bool taken = false;
    for(int i = 0;i < board.size();i++){
        if(board[n-1] != ""){
            taken = true;
        }
    }
    return taken;
}

void userAnswer(){
        int userC = userChoice() - 1;
        std::cout << "It is X's turn.\n";
        if(spotTaken(userC) == true){
            retry();
        }
        else{
            std::cout << "The user chose " << userC << "\n";
            board.insert(board.begin(),userC, "X");
        }
        winner();
        if (winner() == true){
            is_winner();
            win++;
        }
}

void playerAnswer(){
        int playerChoice;
        std::cout << "O's turn.Choose a number between 1 and 9." << "\n";
        std::cin >> playerChoice;
        if(spotTaken(playerChoice) == true){
            retry();
        }
        else{
            std::cout << "O chose " << playerChoice << "\n";
            board.insert(board.begin(),playerChoice, "O");
        }
        winner();
        if (winner() == true){
            is_winner();
            win++;
        }
}

void game(){
    introduction();
    std::cout << "The user is automatically X.so you are O.Good luck !\n";
    std::cout << "Let the game begin ! Here we go.\n";
    winner();
    while(win < 1 && winner() == false){
        
        userAnswer();

        playerAnswer();
    }
}