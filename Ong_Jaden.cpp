
#include <algorithm>
#include <iostream>
#include <vector>
#include <list>

using namespace std;
class TicTacToe {
public:
    /* Constructor*/
    TicTacToe(){
        /* Initialize defaults here */

        char currentPlayer = ' '; // to be set to x or 0
        int currentPosition = 0;


    }

    // lists for player entries
    std::vector<int> playerXPositions;
    std::vector<int> playerOPositions;




    /* This is your game board*/
    vector<vector<char>> gameBoard
{
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};



    /* This prints your game board*/
    void printGameBoard()
    {
        for (int i = 0; i < gameBoard.size(); i++)
        {
            for (int j = 0; j < gameBoard[i].size(); j++)
            {
                cout << gameBoard[i][j] << " ";
            }
            cout << endl;
        }
    }


    char determinePlayer() { // kind of random way to decide who starts
        int temp;
        temp = rand() % 100 + 1; // 1 to 100
        if(temp > 50) {
            return 'X';
        }else {
            return 'O';
        }
    }


    bool containsAll(const std::vector<int> & playerPositions, const std::vector<int> & winningPositions) { // i guess this is what you call a function signature that sets a generic template to be used later
        // c++ lists have .begin and .end when iterating; as well as an all_of which acts like the containsAll() in java; and then there is a find function that helps me compare an element to target
        return std::all_of(winningPositions.begin(), winningPositions.end(), [&](int pos) { // last condition sets a lambda by creating a very temporary variable pos to be used as a comparison in the                                                                                                        next line
            return std::find(playerPositions.begin(), playerPositions.end(), pos) != playerPositions.end(); // iterate through the entire player position (to be either X or O) and compare (that is what the                                                                                                              last condition is, checking if the search for pos was successful or not)
        });

    }


    std::string checkWinner() {
        // use a list of lists to contain possible winning positions and then check those conditions

        std::vector<std::vector<int>> winningPositions = {
            {1,2,3}, {4,5,6}, {7,8,9}, // row wins
            {1,4,7}, {2,5,8}, {3,6,9}, // column wins
            {1,5,9}, {7,5,3}            // cross/diagnonal wins

        };

        for(auto a : winningPositions) {
            if(containsAll(playerOPositions, a)) {
                return "Player O wins!";
            }else if(containsAll(playerXPositions, a)) {
                return "Player X wins!";
            }else if(playerOPositions.size() + playerXPositions.size() == 9) {
                return "The game ends in a draw.";
            }
        }

        return "";

    }





    /* This method modifes the game board*/
    void modifyGameBoard(vector<vector<char>> gameBoard, char player, int position) // added the gameboard parameter, but i realized i can't just pass char[][], so i had to google what the c++ equivalent was

    {
        /*write code to modify the game board here*/

        player = ' ';

        if(player == 'X') {
            playerXPositions.push_back(position);
        }else {
            playerOPositions.push_back(position);
        }

        switch(position) {
            case 1:
                gameBoard[0][0] = player;
                break;
            case 2:
                gameBoard[0][2] = player;
                break;
            case 3:
                gameBoard[0][4] = player;
                break;
            case 4:
                gameBoard[2][0] = player;
                break;
            case 5:
                gameBoard[2][2] = player;
                break;
            case 6:
                gameBoard[2][4] = player;
                break;
            case 7:
                gameBoard[4][0] = player;
                break;
            case 8:
                gameBoard[4][2] = player;
                break;
            case 9:
                gameBoard[4][4] = player;
                break;
            default:
                break;
        }






    }
};


int main() {
    TicTacToe game;
    game.printGameBoard();
    char currentPlayer = game.determinePlayer();

    while(true) {


        cout << "It is player " << currentPlayer << "'s turn.";
        cout << "Player " << currentPlayer << ", please enter an open position on the gameboard.";


        // input
        int currentPosition;
        cin >> currentPosition;
        while(currentPosition < 1 || currentPosition > 9){
            if(game.playerXPositions[currentPosition] != ' ' || game.playerOPositions[currentPosition] != ' ') {
                cout << "Invalid input, please enter another position." << endl;
            }
        }

        game.modifyGameBoard(game.gameBoard, currentPlayer, currentPosition); // playerPosition lists updated there
        game.printGameBoard();
        std::string result = game.checkWinner();
        if(result.length() > 0) { // have to check winner after every entry in the event that the last entry is a winning one
            cout << result << endl;
            break;
        }


        // switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';

    }
    return 0; // i have learned that main has to be int and returns 0 on close.
}