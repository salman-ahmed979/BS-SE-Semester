#include <iostream>
using namespace std;

void transpose(int col, int row, int * matt)
{
    int tr[col][row], a=0,  x=0, y=0, n=0;
    int result[row][row] = {0};
    for (int i=0; i<row; i++)
    {
        for (int j=0; j<col; j++)
        {
            int a =  *(matt+i*col+j);
            tr[x][y] = a;
            x++;
        }
        y++; x=0;
    }
    cout << "\nTranspose of array\n";
    for (int i=0; i<col; i++)
    {
        for (int j=0; j<row; j++)
            cout << tr[i][j] << " ";
        cout << "\n";
    }
    x = 0; y = 0;
    while (x<=row)
    {
        for (int j=0; j<row; j++)
        {
            for (int i=0; i<col; i++)
            {
                a = *(matt+x*col+y);
                cout << a << " ";
                result[x][n] = (a * tr[i][j]) + result[x][n];
                cout << "\nResult " << result[x][n] << "x: " << x << "n: " << n <<"\n";
                y++;
            }
            n++;
            y=0;
        }
        x++; n = 0;
    }
    cout << "\nResult of Multiplication\n";
    for (int i=0; i<row; i++)
    {
        for (int j=0; j<row; j++)
            cout << result[i][j] << " ";
        cout << "\n";
    }
    
}
int main()
{
    int row, col;
    cout << "Enter the dimension of array:\nRow: ";
    cin >> row;
    cout << "\nColumn: "; cin >> col;
    int mat[row][col];
    for (int i=0; i<row; i++)
    {
        for (int j=0; j<col; j++)
        {
            cout << "\nEnter Value in Row " << i << " Column " << j << ": ";
            cin >> mat[i][j];
        }
    }
    transpose(col, row, (int *)mat);


    return 0;
}