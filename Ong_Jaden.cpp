
#include <iostream>
#include <vector>
using namespace std;
class TicTacToe {
public:
    /* Constructor*/
    TicTacToe(){
        /* Initialize defaults here */
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
    /* This method modifes the game board*/
    void modifyGameBoard(char player, int position)
    {
        /*write code to modify the game board here*/
    }
};