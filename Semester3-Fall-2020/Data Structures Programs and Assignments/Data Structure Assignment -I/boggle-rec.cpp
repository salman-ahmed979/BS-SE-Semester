#include<iostream>
#define n 4
using namespace std;
int static sum = 0;
char static arr[n][n] = {""};
void boggle(string &str, string temp_str, int row, int col, int count_word, bool var) {
	if(row < 0 || row > n-1 || col < 0 || col > n-1)
		return;
	
	if(count_word == str.length() && sum!=0)
	{
		//count++;
		return;
	}
	
	if(count_word == str.length()) {
		sum += 1000;
	}

	for(int k=0; k<str.length(); k++) {
		if(arr[row][col] == str[k]) {
			count_word++;
			str[k] = '*';
			var = true;
		}
		if(k == str.length()-1 && var == false)
		{
			str = temp_str;
			return;	
		}
	}
	
	char temp = arr[row][col];
	arr[row][col] = '*';
	
	boggle( str, temp_str, row, col+1, count_word, var);//left
	//if(count_word == str.length() && sum!=0) {
	//	if(count_word!=0)
	//		return;
	//}
	boggle( str, temp_str, row, col-1, count_word, var);//right
	
//	if(count_word == str.length() && sum!=0) {
//		if(count_word!=0)
//			return;
//	}
	
	boggle(str, temp_str, row+1, col, count_word, var);//down
//	if(count_word == str.length() && sum!=0) {
//		if(count_word!=0)
//			return;
//	}
	
	boggle(str, temp_str, row-1, col, count_word, var);//up
//	if(count_word == str.length() && sum!=0) {
//		if(count_word!=0)
//			return;
//	}
	arr[row][col] = temp;
	return;
}




int main() {
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cout << "\nEnter element in row: " << i << " col: " << j << " : ";
			cin >> arr[i][j];
		}
	}
	string strr;
	cin >> strr;
	boggle( strr, strr, 0, 0, 0, false);
	cout << sum;
	return 0;
}
