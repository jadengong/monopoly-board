
#include <iostream>
#include <vector>
#include <list>

using namespace std;
class TicTacToe {
public:
    /* Constructor*/
    TicTacToe(){
        /* Initialize defaults here */

        char currentPlayer = ''; // either X or O
        int currentPosition = 0;


    }




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

    int main() {


        while(true) {

            int playerTemp;


            cout << "It is player " << playerTemp << "'s turn.";
            cout << "Player " << playerTemp << ", please enter an open position on the gameboard.";

            int positionTemp;
            cin >> positionTemp;
            while(positionTemp < 1 || positionTemp > 9 || positionTemp != ' '){
                cout << "Invalid input, please enter another position." << endl;
            }

                modifyGameBoard(playerTemp, positionTemp);
                std::string result = checkWinner();
                if(result.length() > 0) {
                    cout << result << endl;
                    break;
                }



            }
    }

    std::string checkWinner() {

        std::vector<std::vector<int>> winningPositions = {
            {1,2,3}, {4,5,6}, {7,8,9}, // row wins
            {1,4,7}, {2,5,8}, {3,6,9}, // column wins
            {1,5,9}, {7,5,3}            // cross/diagnonal wins

        };

        for() {



    }





    /* This method modifes the game board*/
    void modifyGameBoard(char player, int position) // place piece

    {
        /*write code to modify the game board here*/


        gameBoard[][] =







    }
};