
#include <iostream>
#include <vector>

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

    int main() {

        int playerTemp = randomTurn();

        cout << "It is player " << playerTemp << "'s turn.";
        cout << "Player " << playerTemp << ", please enter an open position on the gameboard.";

        // active game start for player

        int positionTemp = getPosition();

        modifyGameBoard(playerTemp, positionTemp);


    }



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

    int getPosition() { // for players
        int position;
        cin >> position; // get position a player wants to make a move on
        // i want to have error handling here in case a position inputted is not between 1 and 9 or is taken

        if(position < 1 || position > 9) {
            throw out_of_range("Position is not within the gameboard. Please enter another position.");
        }else if (gameBoard[position - 1] != ' ') {
            throw invalid_argument("The position you entered is already taken. Please enter another position.");
        }


        return position;

    }

    char randomTurn() { // randomize who gets to start the game
        int result;
        result = rand() % 100 + 1; // range from 1 to 100

        if(result >= 50) {
            return 'X';
        }
            return 'O';
    }



    /* This method modifes the game board*/
    void modifyGameBoard(char player, int position) // can add argument, cant adjust current args
    {
        /*write code to modify the game board here*/


        gameBoard[player][position] = player;







    }
};