#include<iostream>
using namespace std;
class ChessBoard {
	private:
		bool *column, *leftDiagonal, *rightDiagonal;
		int *positionInRow, howmany;
		int norm, square;
	public:
		ChessBoard(int n) {
			square = n; norm = square-1; howmany = 0; 
			Initialize();
		}
		void Initialize(void) {
			column = new bool[square];
			leftDiagonal = new bool[square*2-1];
			rightDiagonal = new bool[square*2-1];
			positionInRow = new int[square];
			for(int col=0; col<square; col++)
				column[col] = true;
			for(int pos=0; pos<square; pos++)
				positionInRow[pos] = -1;
			for(int diag=0; diag<square*2-1; diag++)
			{
				leftDiagonal[diag] = true; rightDiagonal[diag] = true;
			} 
		}
		void printBoard(void) {
			int row, col;
			for (row = 0; row < square; row++) {
        		for (col = 0; col < positionInRow[row]; col++)
            		cout << ".";
        		cout<<"Q";
        	for (col = positionInRow[row] + 1; col < square; col++)
            	cout << ".";
        	cout << endl;
    		}
    		cout << endl;
    		howmany++;
		}
		//Put Queen part
		void PutQueen(int row) {
			for(int col=0; col<square; col++) 
			{
				if(column[col]==true && leftDiagonal[row+col]==true && rightDiagonal[row-col+norm]==true)
				{
					positionInRow[row] = col;
					column[col] = false;
					leftDiagonal[row+col] = false;
					rightDiagonal[row-col+norm] = false;
					
					//Check if row is in the range
					if(row < square-1)
						PutQueen(row+1);
					else 
						printBoard();
					
					column[col] = true;
					leftDiagonal[row+col] = true;
					rightDiagonal[row-col+norm] = true;
				}
			}
		}
};
int main() {
	ChessBoard c1(4);
	c1.PutQueen(0);
	
	return 0;
}
