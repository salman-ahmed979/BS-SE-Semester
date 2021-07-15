#include<iostream>
#define N  4
using namespace std;

//Check that if i am in grid
bool IsCallwithinGrid(int si, int sj) {
	if(si >= 0 && sj >=0 && si<N && sj<N)
		return true;
	else
		return false;
}
//Check is the path of x-coordinate & y-coordinate is Available
bool IsOpen(int maze[N][N], int si, int sj) {
	if(maze[si][sj]== 1)
		return true;
	else
		return false;
}
//Setting solution path to '1'
void Set_Marker(int sol[N][N], int si, int sj) {
	sol[si][sj] = 1;
}
//Traversing the path
bool IsTraverse(int solution[N][N], int si, int sj) {
	if(solution[si][sj]==0)
		return true;
	else
		return false;
}
void MazeSolution(int maze[N][N], int start_i, int start_j, int end_i, int end_j, int solution[N][N]) {
	if(start_i == end_i && start_j == end_j && maze[start_i][start_j]==1)
	{
		solution[start_i][start_j] = 1; return;	
	}
	if (IsCallwithinGrid(start_i, start_j)) {
		if (IsOpen(maze, start_i, start_j) && solution[start_i][start_j]!=1) {
			//Set_Marker(solution, start_i, start_j);
			solution[start_i][start_j] = 1;
			MazeSolution(maze, start_i+1, start_j, end_i, end_j, solution);
		}
		
		//	solution[start_i][start_j] = 0;
		//	MazeSolution(maze, start_i, start_j+1, end_i, end_j, solution);
		
		MazeSolution(maze, start_i, start_j+1, end_i, end_j, solution);
	}
}

int main() {
	int maze[N][N] = 
	{ 	{ 1, 0, 0, 0 }, 
    	{ 1, 1, 0, 1 }, 
        { 0, 1, 0, 0 }, 
        { 1, 1, 1, 1 }
	};
	int sol[N][N] = 
	{
		{ 0, 0, 0, 0 }, 
    	{ 0, 0, 0, 0 }, 
        { 0, 0, 0, 0 }, 
        { 0, 0, 0, 0 }
	};
	MazeSolution(maze, 0, 0, 3, 3, sol);
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			cout << sol[i][j] << " ";
		}
		cout << endl;
	}
}
