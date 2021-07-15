#include<iostream>
#include<fstream>
using namespace std;

class Maze{
	private:
		int n, m;
		char **maze;
		char **track;
		int count;
	public:
		Maze()
		{
			get_data();
			count = 0;
			track = new char * [n];
			for(int i=0;i<n;i++)
			{
				track[i] = new char [m];
				for(int j=0;j<m;j++)
				{
					track[i][j] = '1';
				}
			}
		}
		
		void get_data()
		{
			ifstream infile;
			infile.open("input.txt");
			infile>>n>>m;
			maze = new char * [n];
			for(int i=0;i<n;i++)
			{
				maze[i] = new char [m];
			}
			for(int i=0;i<n;i++)
			{
				infile>>maze[i];
			}
		}
		
		char can_move(int x, int y)//As my input maze is considered as char array so it is a function which will return '1' if it is true and '0' otherwise
		{
			if(maze[x][y] == '0' && x>=0 && x<n && y>=0 && y<m)//comparing if it is not out bound or the given move is valid or not
			{
				return '1';
			}
			else
			{
				return '0';
			}
		}
		
		void count_path(int x, int y)//function for counting no of ways
		{
			if(x == n-1 && y == m-1)// base condition if we have reached destination so increment counter
			{
				count++;
				return;
			}
			
			track[x][y] = '0';//so we will keep track of this position
			
			if((can_move(x, y) == '1'))//first we are checking if we can move
			{
				if(can_move(x+1, y) == '1' && (track[x+1][y] == '0'))// if there is a way down
				{
					count_path(x+1, y);
				}
				if(can_move(x, y+1) == '1' && (track[x][y+1] == '0'))//if there is a way right
				{
					count_path(x, y+1);
				}
			}
			
			//at this step we are backtracking
			track[x][y] = '1';
		}
		
		int get_count()
		{
			return count;
		}
		
		void put_data()
		{
			ofstream outfile;
			outfile.open("output.txt");
			outfile<<count;
			outfile.close();
		}
};

int main(void)
{
	Maze M;
	
	M.count_path(0,0);
	M.put_data();
}
