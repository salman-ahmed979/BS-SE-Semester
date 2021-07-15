#include<iostream>
using namespace std;
class DSAJagged {
	private:
		int **Data, row, col, m, n;
	public:
		DSAJagged(int r, col) {
			row = r; col = c;
			Data = new int * [row];
			for(int i=0; i<row; i++) {
				Data = new int[col];
				for(int j=0; j<col; j++)
					*(*Data+i)+j = 0;
			}
			m = 0; n = 0;
		}
		void input(int d) {
			if(m<row && n<col) {
				*(*Data+m) + n = d;
				n++;
			}
			if(n==col-1) {
				n = 0; m++;
			}
		}
		~DSAJagged() {
			for(int i=row-1; i>0; i--) {
				for(int j=0; j<col; j++) {
					if(*(Data+i) != 0) {
						delete [] *(Data+i);
						*(Data+i) = 0;
					}
				}
				delete [] Data;
				Data = 0;
			}
		}
};
