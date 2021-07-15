#include<iostream>
#include<vector>
using namespace std;
class Cell {
	public:
		int x;
		int y;
		
		Cell() {
			x = 0; y = 0;
		}
		Cell operator=(const Cell &rhs) {
			x = rhs.x;
			y = rhs.y;
			return *this;
		}
		bool operator==(const Cell &rhs) {
			return (x == rhs.x && y == rhs.y);
		}
		
		~Cell()
		{
			x = 0; y = 0;
		}
};
struct Node{
	Cell cell;
	Node *next;
};

class Stack{
	private:
		Node *head, *top;
		int count;
	public:
		Stack()
		{
			head = 0; top = 0;
			count = 0;
		}
		
		void Push(int x, int y) {
			Node *temp = new Node;
			temp->cell.x = x;
			temp->cell.y = y;
			temp->next = 0;
			if(head == 0) {
				head = temp;
				top = temp;
				
				head->next = 0; top->next = 0;
			}
			else {
				temp->next = top;
				top = temp;
			}
		}
		
		Cell Pop() {
			if(top == 0)
			{
				Cell d; d.x = 0; d.y = 0;
				return d;
			}
			Node *temp = top;
			top = top->next;
			Cell c1 = temp->cell;
			temp = 0;
			delete temp;
			return c1;
		}
		
		bool IsEmpty(void) {
			if(top == 0)
				return true;
			return false;
		}
		
		Cell Peek(void) {
			Cell c1 = top->cell;
			return c1;
		}
		
		//Assignment Operator
		void operator=(Stack &rhs)
		{
			Stack temp;
			
			if( !IsEmpty() )
			{
				while( !IsEmpty() )
				{
					Cell c1 = Pop();
					c1.x = 0; c1.y = 0;
				}
			}
			
			Node *rhs_temp = rhs.top;
			while( rhs.top != 0 )
			{
				Cell c1 = rhs.top->cell;
				rhs.top = rhs.top->next;
				temp.Push(c1.x, c1.y);
			}
			rhs.top = rhs_temp;
			while( !temp.IsEmpty())
			{
				Cell c1 = temp.Pop();
				Push(c1.x, c1.y);
				//c1 = Peek();
				//cout << "\nValues of x: " << c1.x << " y: " << c1.y<<"\n";
				count++;
			}
		}
		
		int get_count(void)
		{
			return count;
		}
		
		void Print(void)
		{
			Node *temp = top;
			while(top != 0)
			{
				cout << "( " << top->cell.x << " , " << top->cell.y << " )" << "\n";
				top = top->next;
			}
			top = temp;
			temp = 0; delete temp;
		}
		
		void Delete_Pop(void)
		{
			if(IsEmpty()) return;
			Node *temp = top;
			top = top->next;
			temp = 0; 
			delete temp;	
		}
		
		~Stack()
		{
			if(top != 0)
			{
				while(top != 0)
				{
					Node *temp = top;
					top = top->next;
					temp = 0; delete temp;	
				}	
			}
			head = 0; top = 0;
			delete head; 
			delete top;
		}
};

class Maze{
	private:
		char **maze;
		int row, col;
		Stack **solution_stack, cell_stack;
	    vector<int> optimized_location;
		Cell Start_cell, Exit_cell;
		
	public:
		static int stack_position_col;
		Maze(int r, int c)
		{
			row = r;
			col = c;
			//Dynamic 2d Jagged Char array
			maze = new char*[row];
			for(int i=0; i<row; i++)
				maze[i] = new char[col];
			
			//Dynamic 2d Jagged Solution Stack Array
			solution_stack = new Stack*[0];
			solution_stack[0] = new Stack[row*col];
			
			stack_position_col = 0;
		}
		
		//Inputting the Data in Maze
		void Input_Maze()
		{
			for(int i=0; i<row; i++) {
				for(int j=0; j<col; j++) {
					cin >> maze[i][j];
					
					//Storing Start Position of Rat in Maze
					if(maze[i][j] == 's') {
						Start_cell.x = i; Start_cell.y = j;
					}
					
					//Storing Ending Position of Rat in Maze
					if(maze[i][j] == 'e') {
						Exit_cell.x = i; Exit_cell.y = j;
					//	cout << "\nExit Cell: " << Exit_cell.x << " y: " << Exit_cell.y;
					}
				}
			}
		}
		
		~Maze()
		{
			for(int i=row-1; i>=0; i--)
			{
				delete [] maze[i];
			}
			delete [] maze;
			delete [] solution_stack[0];
			delete [] solution_stack;
		}
		
		//Boundary Check
		bool boundary_check(int x, int y, bool **path_checker) {
			if( x < 0 || x >= row || y < 0 || y >=col || path_checker[x][y] == false || maze[x][y] == '1')
				return false;
			return true;
		}
		
		void Solve_Maze(void) 
		{
			if(Start_cell == Exit_cell) {
				cout << "\nOn Same path\n";
				return;
			}
			cell_stack.Push(Start_cell.y, Start_cell.x);
			
			// A boolean Array for track of previous path 
			bool **path = new bool*[row];
			for(int i=0; i<row; i++)
				path[i] = new bool[col];
			
			// Opening All the paths
			for(int i=0; i<row; i++)
			{
				for(int j=0; j<col; j++)
					path[i][j] = true;
			}
			//path[Start_cell.x][Start_cell.y] = false;
			Maze_Solution(Start_cell.x, Start_cell.y, path);
			Print_All_Path();
		}
		
		void Maze_Solution(int i, int j, bool **path)
		{
			// Check Within the boundary
			if( boundary_check(i, j, path) == false )
				return;
			
			path[i][j] = false;
			// Push in my Stack
			if( !(i == Start_cell.x && j == Start_cell.y))
			{
				cell_stack.Push(j, i);
			}
			
			if(i == Exit_cell.x && j == Exit_cell.y)
			{
				solution_stack[0][stack_position_col] = cell_stack;
				
				//cout << "\nGetting count: " << solution_stack[0][stack_position_col].get_count() << "\n";
				
				optimized_location.push_back(solution_stack[0][stack_position_col].get_count());
				//cout << "\nOptimized: "<< optimized_location[stack_position_col] << "\n";
				
				stack_position_col++;
				cell_stack.Delete_Pop();
				path[i][j] = true;
				return;
			}
			
			Maze_Solution(i, j+1, path);
			Maze_Solution(i+1, j, path);
			Maze_Solution(i, j-1, path);
			Maze_Solution(i-1, j, path);
			
			path[i][j] = true;
			if(cell_stack.Peek() == Start_cell) 
			{
				cell_stack.Delete_Pop();
				return;
			}
			
			cell_stack.Delete_Pop();
		}
		
		void Print_All_Path(void)
		{
			/*
				//Selection Sort
				
			for(int i=0; i<stack_position_col-1; i++)
			{
				int min_index = i;
				for(int j=i+1; j<stack_position_col; j++)
				{
					if(optimized_location[j] < optimized_location[min_index])
						min_index = j;
				}
				if(min_index != i)
				{
					int temp = optimized_location[i];
					optimized_location[i] = optimized_location[min_index];
					optimized_location[min_index] = temp;
					
					cout << "\nExchanging: " << i << " and " << min_index << "\n";
					Stack tempo = solution_stack[0][i];
					solution_stack[0][i] = solution_stack[0][min_index];
					
					solution_stack[0][i].Print();
					solution_stack[0][min_index] = tempo;
					cout << "\n\n";
					
					solution_stack[0][min_index].Print();
					cout << "\n";

					/*Stack tempo = solution_stack[0][min_index];
					
					while( !solution_stack[0][min_index].IsEmpty())
					{
						solution_stack[0][min_index].Delete_Pop();
					}
					
					bool var = false;
					Stack shift = solution_stack[0][i];
					for(int k = i; k<min_index; k++)
					{
						if( !solution_stack[0][k+1].IsEmpty()){
							shift = solution_stack[0][k+1];
							var = true;
						}
						solution_stack[0][k+1] = solution_stack[0][i];
						
						if(!solution_stack[0][i].IsEmpty())
						{
							while( !solution_stack[0][i].IsEmpty() )
								solution_stack[0][i].Delete_Pop();
						}
						if( var )
							solution_stack[0][i] = shift;
						var = false;
					}
					solution_stack[0][i] = tempo;
					
					if(i+1 == min_index)
					{
						solution_stack[0][min_index] = solution_stack[0][i];
						solution_stack[0][i] = tempo;
					}
					else{
						for(int k=i; k<min_index; k++)
						{
							if(solution_stack[0][k+1].IsEmpty() == false)
							{
								Stack ss = solution_stack[0][k+1];
								solution_stack[0][k+1] = solution_stack[0][i];
								solution_stack[0][i] = ss;
							}
							else{
								solution_stack[0][k+1] = solution_stack[0][i];
								solution_stack[0][i] = tempo;
							}
						}
					}
				}
			}*/
			
			//Bubble Sort for correct Answer ( According to Hacker Rank Output)
			
			for(int i=1; i<stack_position_col; i++)
			{
				for(int j=0; j<stack_position_col-1; j++)
				{
					if(optimized_location[j] > optimized_location[j+1] )
					{
						int temp = optimized_location[j];
						optimized_location[j] = optimized_location[j+1];
						optimized_location[j+1] = temp;
						
						Stack temp_stack = solution_stack[0][j];
						solution_stack[0][j] = solution_stack[0][j+1];
						solution_stack[0][j+1] = temp_stack;
					}
				}
			}
			
			int i = 0;
			while(i < stack_position_col)
			{
				Stack temp;
				while( !solution_stack[0][i].IsEmpty())
				{
					Cell c1 = solution_stack[0][i].Pop();
					temp.Push(c1.x, c1.y);
				}
				
				cout << "Path#" << i+1 << "={";
				while( !temp.IsEmpty())
				{
					Cell c = temp.Pop();
					cout << "(" << c.x << "," << c.y << ")";
					if( !(c.y == Exit_cell.x && c.x == Exit_cell.y) ) cout << ",";
				}
				cout << "}" << " " << "Cost=" << optimized_location[i] << "\n";
				i++;
			}
			
		}
		
		void Path()
		{
			int j = 10;
			while(stack_position_col <= 3){
			for(int i=1; i<5; i++)
			{
				solution_stack[0][stack_position_col].Push(j, i);
				j++;
			}
			j *=2;
			stack_position_col++;}
			cout << "\nCopying stack with first one\n";
			solution_stack[0][stack_position_col] = solution_stack[0][0];
			
			for(int i=0; i<=stack_position_col; i++){
				cout << "\nStack No: " << i+1;
				solution_stack[0][i].Print();
				cout << "\n";}
		}
};

int Maze::stack_position_col = 0;

int main() {
	
	int r,c;
	cin >> r >> c;
	Maze m1(r,c);
	m1.Input_Maze();
	m1.Solve_Maze();
	return 0;
}
