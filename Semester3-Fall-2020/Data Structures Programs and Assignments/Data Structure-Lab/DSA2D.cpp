#include<bits/stdc++.h>
using namespace std;
class DSA2D {
	private:
		int *Data, row, col;
	public:
		DSA2D(int r, int c) {
			row = r; col = c;
			int size = row * col;
			Data = new int[size];
			memset(Data, 0, sizeof(int)*size);
		}
		
		DSA2D(const DSA2D& rhs) {
			row = rhs.row; col = rhs.col;
			int size = row * col;
			Data = new int[size];
			memcpy(Data, rhs.Data, sizeof(int)*size);
		}
		
		DSA2D& operator=(const DSA2D& rhs) {
			if(this != &rhs) {
				delete [] Data;
				Data = 0;
				row = rhs.row; col = rhs.col;
				int size = row * col;
				Data = new int[size];
				memcpy(Data, rhs.Data, sizeof(int)*size);
			}
			return *this;
		}
		
		void Input_data(void) {
			for(int i=0; i<row; i++) {
				for(int j=0; j<col; j++)
				{
					cin >> *(*(Data+i) +j);
				}
			}
		}
		
		void 
};
