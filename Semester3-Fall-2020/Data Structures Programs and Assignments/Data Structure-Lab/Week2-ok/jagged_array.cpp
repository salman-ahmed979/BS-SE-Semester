#include<iostream>
#include<vector>
using namespace std;

int main(void)
{
	int n=0, a=0, input=0;
	cout << "\nEnter Number of rows for jagged array: ";
	cin >> n;
	vector < vector <int> > vec;
	for(int i=0; i<n; i++)
	{
		vector <int> temp;
		cout << "\nEnter number of columns for row: " << i <<" : ";
		cin >> input;
		for(int j=0; j<input; j++)
		{
			cout << "\nEnter row elements: ";
			cin >> a;
			temp.push_back(a);
		}
		vec.push_back(temp);
	}
	  // Displaying the 2D vector 
    for (int i = 0; i < vec.size(); i++) { 
        for (int j = 0; j < vec[i].size(); j++) 
            cout << vec[i][j] << " "; 
        cout << endl; 
    } 
	return 0;
}
