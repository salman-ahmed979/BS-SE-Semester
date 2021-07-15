#include<iostream>
using namespace std;
class matrix 
{
	private:
		int image[7][7], filter[3][3], result[5][5];
	public:
		void input_image(void)
		{
			cout << "\nEnter values in image must be in 0 or 1:\n";
			for (int i=0; i<7; i++)
			{
				for (int j=0; j<7; j++)
				{
					x:
					cout << "\nPosition of row: " << i  << " column: " << j << " value: ";
					cin >> image[i][j];
					if (!(image[i][j] ==0 || image[i][j] == 1))
					{
						cout << "\nEnter correct value\n";
						goto x;
					}
				}	
			}
			cout << "\nValues in image are inserted\n";	
		}
		void input_filter(void)
		{
			cout << "\nEnter values in filter must be in 0 or 1:\n";	
			for (int i=0; i<3; i++)
			{
				for (int j=0; j<3; j++)
				{
					x:
					cout << "\nPosition of row: " << i  << " column: " << j << " value: ";
					cin >> filter[i][j];
					if (!(filter[i][j] ==0 || filter[i][j] == 1))
					{
						cout << "\nEnter correct value\n";
						goto x;
					}
				}	
			}
			cout << "\nValues in filter are inserted\n";	
		}
		void deter(int arr, int i, int j)
		{
			result[i][j] = arr;
		}
		
		
		void multi_img_filt(void)
		{
			int count=1, a=0, n=0, x=0, y=0, var=1, m=0, p=0;
			while (var<=5)
			{
				count=1;
			while (count<=5)
			{	
				int temp=0;			
				for (int i=a; i<=(a+2); i++)
				{				
					for (int j=n; j<=(n+2); j++)
					{
						temp = ( image[i][j] * filter[x][y] )+ temp;
						y+=1;
					}
					//temp[1] += temp[0]; 
					x+=1; y=0;
				}
				deter(temp, m, p);
				x=0;y=0;
				n+=1; count+=1; p+=1;
			}
			m+=1; a+=2; n=0; p=0;
			var+=1;
			}
		}
		
		void print_result(void)
		{
			cout << "\nValues in 5x5 result array:\n\n";
			for (int i=0; i<5; i++)
			{
				for (int j=0; j<5; j++)
				{
					cout << result[i][j] << " ";		
				}
				cout << "\n";
			}	
		}	
};
int main()
{
	matrix m1;
	m1.input_filter();
	m1.input_image();
	m1.multi_img_filt();
	m1.print_result();
	return 0;
}
