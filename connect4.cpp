// CONNECT 4 GAME BASED FOR TWO PLAYERS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// by default the connect 4 game has grid size of 6x7 

const int ROWS = 6;
const int COLS = 7;

// Function to print the board design

void boarddesign(const vector<vector<char> >& board) 
{
    for (int i = 0; i < ROWS; i++) 
	{
        for (int j = 0; j < COLS; j++) 
		{
            cout << "|" << board[i][j] << " ";
        }
        cout << "|" << endl;
    }
    for (int i = 0; i < COLS; i++) 
	{
        cout << "---";
    }
    cout << endl;
}

// Function to check if the column is full

bool isColFul(const vector<vector<char> >& board, int col) 
{
    return board[0][col] != ' ';
}

// Function to make a move

bool makemove(vector<vector<char> >& board, int col, char player) 
{
    if (isColFul(board, col)) 
	{
        return false;
    }
    for (int i = ROWS - 1; i >= 0; --i) 
	{
        if (board[i][col] == ' ') 
		{
            board[i][col] = player;
            return true;
        }
    }
    return false;
}

// Function to check if the player has won
bool checkwin(const vector<vector<char> >& board, int col, char player) 
{
    // Check rows
    for (int i = 0; i < ROWS; ++i) 
	{
        for (int j = 0; j < COLS - 3; ++j) 
		{
            if (board[i][j] == player && board[i][j + 1] == player && board[i][j + 2] == player && board[i][j + 3] == player) 
			{
                return true;
            }
        }
    }

    // Check columns
    for (int j = 0; j < COLS; ++j) 
	{
        for (int i = 0; i < ROWS - 3; ++i) 
		{
            if (board[i][j] == player && board[i + 1][j] == player && board[i + 2][j] == player && board[i + 3][j] == player) 
			{
                return true;
            }
        }
    }

    // Check diagonals (top-left to bottom-right)
    for (int i = 0; i < ROWS - 3; ++i) 
	{
        for (int j = 0; j < COLS - 3; ++j) 
		{
            if (board[i][j] == player && board[i + 1][j + 1] == player && board[i + 2][j + 2] == player && board[i + 3][j + 3] == player) 
			{
			   return true;
            }
        }
    }

    // Check diagonals (bottom-left to top-right)
    for (int i = 3; i < ROWS; ++i) 
	{
        for (int j = 0; j < COLS - 3; ++j) 
		{
            if (board[i][j] == player && board[i - 1][j + 1] == player && board[i - 2][j + 2] == player && board[i - 3][j + 3] == player) 
			{
            	
                return true;
            }
        }
    }

    return false;
}

int main() 
{
    cout << "\033[1m\033[32mCONNECT 4 GAME\033[0m\033[0m" << endl;
    cout << "\033[31m(two player game)\033[0m" << endl << endl;
    cout << "\033[1mInstructions: \033[0m" << endl << "1. This is a two player game." << endl
         << "2. Each player gets a turn one after the other." << endl
         << "3. When one of the two players makes 4 of their symbol (either 'X' or 'O') in a row, they win." << endl << endl << endl << endl;
    cout << "\033[1mLet the game begin....\033[0m" << endl << endl;

    vector<vector<char> > board(ROWS, vector<char> (COLS, ' '));
    char player = 'X';

    while (true) 
	{
        boarddesign(board);
        int col;
        cout << endl << "\033[48;5;7m\033[30mPlayer " << player << ", enter the column (0-6) where you want to drop your piece:\033[0m";
        cin >> col;
        cout<<endl;

        if (col < 0 || col >= COLS) 
		{
            cout<<endl<<endl<<"\033[48;5;1mINVALID COLUMN" << endl << "Please choose a column between 0 to 6\033[0m" << endl<<endl;
            continue;
        }

        if (makemove(board, col, player)) 
		{
            if (checkwin(board, col, player)) 
			{
                boarddesign(board);
                cout << "\033[33mPLAYER " << player << " \033[33mWINS!\033[0m" << endl;
                break;
            }

            // Switches to the other player
            
            player = (player == 'X') ? 'O' : 'X';
        } else 
		{
            cout <<endl<<endl<< "\033[48;5;5mColumn is full. Try another column.\033[0m" <<endl<< endl;
        }
    }

    return 0;
}

