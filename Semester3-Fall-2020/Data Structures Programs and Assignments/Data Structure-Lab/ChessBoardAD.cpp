/****************************************************************************
* Author: Muhammad Rafi                                                    *
* Purpose: Example Program - Backtracking                                  *
*          Adam Drozdak - Edition 4th (class motivation)                   *
* Dated: September 20, 2014                                                *
* Version: 3.0                                                             *                                                 
* Last modified: September 27, 2014                                        *
****************************************************************************/

#include <iostream>

using namespace std;

// chessBoard Class for the problem

class ChessBoard {
public:
    ChessBoard();    // 8 x 8 chessboard;
    ChessBoard(int); // n x n chessboard;
    void findSolutions();
private:
    const bool available;  
    const int squares, norm;
    bool *column, *leftDiagonal, *rightDiagonal;  // pointer for data structures 
    int  *positionInRow, howMany;   // queens and their position in row { Q1 --> Row 1} 
    void putQueen(int);
    void printBoard(ostream&);
    void initializeBoard();
};
// default constructor 
ChessBoard::ChessBoard() : available(true), squares(8), norm(squares-1) {
    initializeBoard();
}

//parametric constructor ChessBoard { dimension }
ChessBoard::ChessBoard(int n) : available(true), squares(n), norm(squares-1) {
    initializeBoard();
}

// initialization for the initial board 
void ChessBoard::initializeBoard() {
    register int i;
    column = new bool[squares];
    positionInRow = new int[squares];
    leftDiagonal  = new bool[squares*2 - 1];
    rightDiagonal = new bool[squares*2 - 1];
    for (i = 0; i < squares; i++)
        positionInRow[i] = -1;
    for (i = 0; i < squares; i++)
        column[i] = available;
    for (i = 0; i < squares*2 - 1; i++)
        leftDiagonal[i] = rightDiagonal[i] = available;
    howMany = 0;
}


// Print the board on the screen 
void ChessBoard::printBoard(ostream& out) {
    register int col, row;
    for (row = 0; row < squares; row++) {
        for (col = 0; col < positionInRow[row]; col++)
            out.put('.');
        out.put('Q');
        for (col = positionInRow[row] + 1; col < squares; col++)
            out.put('.');
        out << endl;
    }
    out << endl;
    howMany++;
}

// function to put queen in non-attacking position. 

void ChessBoard::putQueen(int row) {
    for (int col = 0; col < squares; col++)
        if (column[col] == available &&
            leftDiagonal [row+col] == available &&
            rightDiagonal[row-col+norm] == available) {
            positionInRow[row] = col;
            column[col] = !available;
            leftDiagonal[row+col] = !available;
            rightDiagonal[row-col+norm] = !available;
            if (row < squares-1)
                 putQueen(row+1);
            else printBoard(cout);

            column[col] = available;
            leftDiagonal[row+col] = available;
            rightDiagonal[row-col+norm] = available;
        }
}


// solution for ChessBoard 
void ChessBoard::findSolutions() {
    putQueen(0);
    cout << howMany << " solutions found.\n";
}

int main() {
    ChessBoard board(4);
    board.findSolutions();
    
    return 0;
}
