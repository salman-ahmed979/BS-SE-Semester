#include<iostream>
using namespace std;
#define n 10
static int score;
static bool traverse = false;
void Boggle(char board[][n], string target_str, int i, int j, int count, bool check[][n]);

//void checker(bool check[][n]) {
//	for(int x=0; x<n; x++) {
//		for(int y=0; y<n; y++)
//			check[x][y] = false;
//	}
//}
void GoBoggle(char board[][n], string target_str)
{
	bool check[n][n];
//	checker(check);
	for(int x=0; x<n; x++) {
		for(int y=0; y<n; y++)
			check[x][y] = false;
	}
	for(int m=0; m<n; m++) {
		for(int l=0; l<n; l++) {
			if(board[m][l] == target_str[0]) {
				Boggle(board, target_str, m, l, 0, check);
//				checker(check);
				
//				if(traverse == true) {
//					board[m][l] = '*';
//					traverse = false;	
//				}
				for(int x=0; x<n; x++) {
					for(int y=0; y<n; y++)
						check[x][y] = false;
				}			
			}
		}
	}
}

void Boggle(char board[][n], string target_str, int i, int j, int count, bool check[][n]) {
	
	if(i<0 || i>n-1 || j<0 || j>n-1) {
		return;
	}
	
	if(count == target_str.length()) {
		//score  += 1000;
		return;
	}
	
	if(check[i][j]==true)
		return;	
	
	bool var = false;
	for(int k=0; k<target_str.length(); k++) {
		
		if(board[i][j] == target_str[k] && board[i][j]!='*' && var!=true) //pre-con check[i][j]!=true
		{
			count += 1;
			var = true;
			target_str[k] = '*';
			cout << "\nWord: " << board[i][j] << " row: " << i << " column: " << j << "\n";
			if(count==target_str.length() && var==true) {
				score += 1000;
				cout << "In score: " << score << "\n";
				
			//	traverse = true; // I SWITCH OFF THIS ON HACKER RANK
			}
		}
	}
	
	if(var == false)
		return;

	check[i][j] = true;
	Boggle(board, target_str, i, j+1, count, check); // right
	
	
	Boggle(board, target_str, i+1, j, count, check); // down
	
	
	Boggle(board, target_str, i, j-1, count, check); // left
	
	Boggle(board, target_str, i-1, j, count, check); // up
	
	check[i][j] = false;
	return;
}

int main() {
	int p, q;
	cin >> p >> q;
	char boardd[n][n] = {""};
	for(int m=0; m<n; m++) {
		for(int l=0; l<n; l++)
		{
			//if(l==9 || l==7 || l==8) {
			cout << "\nEnter row " << m << " column " << l << " : ";
			cin >> boardd[m][l];
			//else {
			//	boardd[m][l] = 'z';
			//}
		}
	}
	
	int N;
	cin >> N;
	string str[N];
	for(int p=0; p<N; p++)
		cin >> str[p];
	int counter = 0;
	while(counter != N) {
		string target = str[counter];
		cout << target << " ";
		GoBoggle(boardd, target);
		cout << score << "\n";
		score = 0;
		counter += 1;	
	}
	
//	string str;
//	cin >> str;
//	GoBoggle(boardd, str);
//	cout << "\nScore: " << score << endl;
	return 0;
}
