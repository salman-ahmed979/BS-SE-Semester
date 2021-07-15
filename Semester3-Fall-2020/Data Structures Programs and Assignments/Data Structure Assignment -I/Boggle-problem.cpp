#include<iostream>
using namespace std;
//Creating Dynamic Safe 2d-Array
template<class T>
class DynamicSafe2dArray {
	private:
		T **Data;
		unsigned int nRow, nCol;
	public:
		//Default Constructor
		DynamicSafe2dArray() {
			Data = 0; nRow = 0; nCol = 0;
		}
		//Parameterized Constructor
		DynamicSafe2dArray(unsigned int row,unsigned int col) {
			nRow = row; nCol = col;
			Data = new T*[nRow];
			for(int i=0; i<nRow; i++) {
				*(Data+i) = new T[nCol];
				for(int j=0; j<nCol; j++) {
					*((*Data+i) + j) = 0;
				}
			}
		}
		//Copy constructor
		DynamicSafe2dArray(const  DynamicSafe2dArray& rhs) {
			nRow = rhs.nRow; nCol = rhs.nCol;
			Data = new T*[nRow];
			for(int i=0; i<nRow; i++) {
				*(Data+i) = new T[nCol];
				for(int j=0; j<nCol; j++) {
					*((*Data+i) + j) = *(*(rhs.Data+i) + j);
				}
			}
		}
		//Destructor
		~DynamicSafe2dArray() {
			if(Data != 0)
			{
				for(int i=nRow-1; i>0; i--)
				{
					
					delete [] *(Data+i);
					//	*(Data+i) = 0;	
				}
				delete[] Data;
				Data = 0;
			}
		}
		//Overloading Operator '()'
		T& operator()(unsigned int i, unsigned int j) {
			if(i < 0 || i > nRow-1 || j < 0 || j > nCol-1) {
				cout << "\nOut of bound\n";
				exit(0);
			}
			return (*(*(Data+i) + j));
		}
		//Setter function
		void Input_data(void) {
			for(int i=0; i<nRow; i++) {
				for(int j=0; j<nCol; j++) {
					cout << "\nEnter element in row: " << i << " col: " << j << " : ";
					cin >> *(*(Data+i) + j);
				}
			}
		}
		//Print function
		void Print_data(void) {
			for(int i=0; i<nRow; i++) {
				for(int j=0; j<nCol; j++) {
					cout << *(*(Data+i) + j) << " ";
					//if(*(*(Data+i) + j) == 'c') cout << "\nc found\n";
				}
				cout << endl;
			}
		}
		
		//Find the words
		bool Check_str(string &target_array, int row, int col) {
			for(int i=0; i<target_array.length(); i++) {
				if(*(*(Data+row) + col) == target_array[i]) {
					target_array[i] = '*';
					return true;
				}
			}
			return false;
		}
		//Boggle Boggle search 
		void BoggleBoggle(string target_array) {
			int score = 0, target_length = target_array.length();
			int count = 0, k = 0;
			string target_str = target_array;
			//Check for 'Downward' position e.g. "PROPER"
			for(int j=0; j<nCol; j++) {
				for(int i=0; i<nRow; i++) {
					//if( *(*(Data+i) + j) == target_array[k])
					if(Check_str(target_str, i, j) == true)
					{
						count++; 	
					}
					if(count == target_length) {
						score = 1000 + score;
					}
					if(count > 1 && (i+1) <= nRow-1) { 
					//if(*(*(Data+(i+1)) + j) != target_array[k] && (k <= target_length))
					if(Check_str(target_str, i+1, j) == false)
					{
						
						count = 0;
					}}
				}
				 count = 0;
			}
			//cout << "\nScore: " << score << " Count: " << count << endl;
		    //Check for 'Upward' position e.g. REPORP
			k = 0; count = 0;
			for(int j=nCol-1; j>=0; j--) {
				for(int i=nRow-1; i>=0; i--) {
					if( *(*(Data+i) + j) == target_array[k])
					{
							k++; count++; 	
					}
					if(count == target_length) {
						score = 1000 + score;
					}
					if(count > 1 && (i-1) >= 0) {
					if(*(*(Data+(i-1)) + j) != target_array[k] && (k <= target_length))
					{
						k = 0; count = 0;
					}}
				}
				k = 0; count = 0;
			}	
			//cout << "\nScore: " << score << " Count: " << count << endl;
			
			//Check for Left to Right e.g. PROPER
			k = 0; count = 0;
			for(int i=0; i<nRow; i++) {
				for(int j=0; j<nCol; j++) {
					if( *(*(Data+i) + j) == target_array[k])
					{
						k++; count++; 	
					}
					if(count == target_length) {
						score = 1000 + score;
					}
					if(count > 1 && (j+1) <= nCol-1) {
					if (*(*(Data+i) + (j+1)) != target_array[k] && (k <= target_length))
					{
						k = 0; count = 0;
					}}
				}
				k = 0; count = 0;
			}
			//cout << "\nScore: " << score << " Count: " << count << endl;
			//Check for Right to Left e.g. REPORP
			for(int i=nRow-1; i>=0; i--) {
				for(int j=nCol-1; j>=0; j--) {
					if( *(*(Data+i) + j) == target_array[k])
					{
						k++; count++; 	
					}
					if(count == target_length) {
						score = 1000 + score;
					}
					if(count > 1 && (j-1) >= 0) {
					if (*(*(Data+i) + (j-1)) != target_array[k] && (k <= target_length))
					{
						k = 0; count = 0;
					}}
				}
				k = 0; count = 0;
			}
			//cout << "\nScore: " << score << " Count: " << count << endl;
			
			//Left Diagonal top to bottom
			
			for(int i=0; i<nRow; i++) {
				for(int j=0; j<nCol; j++) {
					if(i==j) 
					{
						if( *(*(Data+i) + j) == target_array[k])
						{	
							k++; count++; 	
						}
						if(count == target_length) {
							score = 1000 + score;
						}
						if(count > 0 && i+1 <= nRow-1 && j+1 <= nCol-1)
						{
							if (*(*(Data+(i+1)) + (j+1)) != target_array[k] && (k <= target_length))
							{
								k = 0; count = 0;
							}
						}
					}
				}
			}
			//cout << "\nScore: " << score << " Count: " << count << endl;
			//Left Diagonal from bottom to top
			for(int i=nRow-1; i>=0; i--) {
				for(int j=nCol-1; j>=0; j--) {
					if(i==j) 
					{
						if( *(*(Data+i) + j) == target_array[k])
						{	
							k++; count++; 	
						}
						if(count == target_length) {
							score = 1000 + score;
						}
						if(count > 0 && i-1 >= 0 && j-1 >= 0)
						{
							if (*(*(Data+(i-1)) + (j-1)) != target_array[k] && (k <= target_length))
							{
								k = 0; count = 0;
							}
						}
					}
				}
			}
			cout << score << endl;			
		}
};
int main() {
	int row, col;
	cin >> row >> col;
	DynamicSafe2dArray<char> d1(row+1,col+1);
	d1.Input_data();
//	d1.Print_data();
	int n;
	cin >> n;
	string str[n];
	for(int i=0; i<n; i++)
		cin >> str[i];
	int counter = 0;
	while(counter != n) {
		string target = str[counter];
		cout << target;
		d1.BoggleBoggle(target);
		counter += 1;	
	}
	//string str= "Hello";
	//cout << str[0] << " " << str[1];
	
	return 0;
}
