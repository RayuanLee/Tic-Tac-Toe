#include<iostream>
#include<vector>
#include<algorithm>
//used for random numbers
#include<cstdlib>
#include<ctime>
using namespace std;

//game piece
char X = 'X';
char O = 'O';
char clear = ' ';
char tie = 'T';

int turn = 0;

//This is a function to check the move and to make sure that the space chosen is clear
bool checkMove(vector<char>& board, int placement)
{
    if (board[placement] == clear)
    {
        return true;
    }
    
    else
        return false;
}
//This asks the player where they want to move.
void playerMove(vector<char>& board)
{
    cout << (turn ? "Player 2, " : "Player 1, ");
    cout << "where would you like to go: ";
    int place;
    cin >> place;
    //for the math function
    int a, b, ans;
    
    if (checkMove(board, place))
    {
        //gives us a random number between 1 and 20
        a = rand() % 20 + 1;
        b = rand() % 20 + 1;
        if (turn)
        {
            cout << "Player 2, what is " << a << " * " << b << "? ";
            cin >> ans;
            
            if (ans == a * b)
            {
                cout << "Correct! I'll place your piece.";
                board[place] = O;
            }
            
            else
            {
                cout << "That is not correct! You lose your turn." << endl;
            }
            
            turn = 0;
        }
        
        else if (!turn)
        {
            
            cout << "Player 1, what is " << a << " * " << b << "? ";
            cin >> ans;
            
            if (ans == a * b)
            {
                cout << "Correct! I'll place your piece.";
                board[place] = X;
            }
            
            else
            {
                cout << "That is not correct! You lose your turn." << endl;
            }
            
            turn = 1;
        }
        
    }
    
    else if (!checkMove(board, place))
        cout << "Invalid Move !" << endl;
}

//this is the code that will display my board
void display(vector<char>& board)
{
    cout << "\n\t" << board[0] << " | " << board[1] << " | " << board[2];
    cout << "\n\t" << "-----" << "-----";
    cout << "\n\t" << board[3] << " | " << board[4] << " | " << board[5];
    cout << "\n\t" << "-----" << "-----";
    cout << "\n\t" << board[6] << " | " << board[7] << " | " << board[8];
    cout << "\n\n";
}

//This function will check the winner of the game and make sure the places are correct.
char checkWinner(vector<char>& board)
{
    if (board[0] == board[1] && board[2] == board[0])
        return board[0];
    
    if (board[3] == board[4] && board[5] == board[4])
        return board[3];
    
    if (board[6] == board[7] && board[8] == board[6])
        return board[6];
    
    if (board[0] == board[3] && board[6] == board[0])
        return board[0];
    
    if (board[1] == board[4] && board[7] == board[1])
        return board[1];
    
    if (board[2] == board[5] && board[8] == board[2])
        return board[2];
    
    if (board[0] == board[4] && board[8] == board[0])
        return board[0];
    
    if (board[2] == board[4] && board[6] == board[2])
        return board[2];
    
    if (count(board.begin(), board.end(), clear) == 0)
        return 0;
    
    else
        return clear;
}

void instructions();
void play();
//this is where the game starts and take all of my defined functions and builds them together
int main()
{
    //seeds the random number generator
    srand( static_cast<unsigned int>(time(NULL)));
    int choice;
    do {
        cout << "Welcome to Tic Tac Toe" << endl;
        cout << "For instructions press 1." << endl;
        cout << "To play, press 2." << endl;
        cout << "To exit, press 3." << endl;
        cin >> choice;
        //This is to make sure that the players don't get thrown into an infinte loop.
        if (!cin)
        {
            cin.clear();
            cin.ignore(100, '\n');
        }
        cout << endl;
        switch (choice)
        {
            case 1:
                instructions();
                break;
            case 2:
                play();
                break;
        }
    } while (choice != 9);
    return 0;
}
void instructions()
{
    cout << "Rules to Tic Tac Toe:" << endl;
    cout << "The objective of this game is to get 3 Xs or 3 Os in a row" << endl;
    cout << "The X, player 1 gets to move first." << endl;
    cout << "Each player will choose a board location, when a location is chosen the player will be presented with a math question to answer before placement. If the answer is correct you get the place, if false then you lose your turn."<< endl;
    cout << "The board locations are as follows:" << endl;
    cout << "    0    1    2" << endl;
    cout << "    3    4    5" << endl;
    cout << "    6    7    8" << endl;
}
void play()
{
    vector<char> board(9, clear);
    
    
    while (checkWinner(board) == clear)
    {
        display(board);
        
        playerMove(board);
    }
    
    display(board);
    
    if (checkWinner(board) == 0)
    {
        cout << "It was a tie!" << endl;
    }
    
    else
        cout << "Congratulations! " << checkWinner(board) << " has won!" << endl << endl;
}
