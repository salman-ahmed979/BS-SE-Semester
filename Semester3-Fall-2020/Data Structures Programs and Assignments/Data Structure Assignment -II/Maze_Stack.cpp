#include<iostream>
using namespace std;
class Cell {
	public:
		int x, y;
		Cell(int r, int c) {
			x = r;
			y = c;
		}
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
struct Node {
	Cell cell;
	Node *next;
};
class Stack {
	public:
		Node *head, *top;
	//public:
		Stack() {
			head = 0; top = 0;
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
	    Cell Pop(void) {
	    	Cell c2; c2.x = 0; c2.y = 0;
	    	if(IsEmpty() == true) return c2; 
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
			Stack temp, lhs;
			
			Node *rhs_temp = rhs.top;
			while( rhs.top != 0 )
			{
				Cell c1 = rhs.top->cell;
				rhs.top = rhs.top->next;
				temp.Push(c1.x, c1.y);
				c1 = temp.Peek();
				cout << "\nIn temp: " << c1.x << " " << c1.y << "\n";
			}
			rhs.top = rhs_temp;
			while( !temp.IsEmpty())
			{
				Cell c1 = temp.Pop();
				Push(c1.x, c1.y);
				
				c1 = Peek();
				cout << "\nIn My Stack: " << c1.x << " " << c1.y << "\n";
			}
		}
		
		Cell get_head(void)
		{
			Cell c1 = head->cell;
			return c1;
		}
		
		void Print(void)
		{
			while(top != 0)
			{
				cout << "( " << top->cell.x << " , " << top->cell.y << " )" << "\n";
				top = top->next;
			}
		}
		
		~Stack()
		{
			if(top != 0)
			{
				while(top != 0)
				{
					Node *temp = top;
	    			top = top->next;
	    			delete temp; temp = 0;
				}
			}
			delete top; delete head;
		}
};
class Maze {
	private:
		char **maze;
		int row, col;
		Stack s1, *solution_stack;
		Cell Start_cell, Exit_cell;
		bool varify;
		int stack_position;
	public:
		Maze(int r, int c) {
			row = r;
			col = c;
			//Dynamic 2d Char array
			maze = new char*[row];
			for(int i=0; i<row; i++){
				maze[i] = new char[col];
			varify = false;
			}
			
			solution_stack = new Stack[row*col];
			for(int i=0; i<row*col; i++)
				solution_stack[i].Push(0,0);
//			for(int i=0; i < row*col; i++)
//			{
//				Cell c1 = solution_stack[i].Pop();
//				c1.x = 0; c1.y = 0;
//			}
			stack_position = 0;
		}
		
		//Input the Maze
		void Input_Maze(void) {
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
					}
				}
			}
		}
		
		~Maze()
		{
			for(int i=row-1; i>=0; i--)
			{
				delete [] *(maze+i);
			}
			delete [] maze;	
			delete [] solution_stack;
		}
		
		//Push the Unvisited Path
		void Push_Unvisited_Path(int r, int c, bool **path_checker) {
			if(r < 0 || r >= row || c < 0 || c >= col || path_checker[r][c] == false)
				return;
			if(maze[r][c] == '0' || maze[r][c] == 'e') {
				s1.Push(r,c);
				varify = true;
			}
		}	
		
		//Check Specific boundary
		bool boundary_check(int x, int y) {
			if(x < row && y < col && x == Exit_cell.x && y == Exit_cell.y) return true;
			return false;
		}
		
		
		void Solve_Maze(void) {
			//Make Cell
			Cell current_cell;
			current_cell = Start_cell;
			bool **path_locker;
			
			//All Paths are open to traverse
			path_locker = new bool *[row];
			for(int i=0; i<row; i++)
				path_locker[i] = new bool[col];
			for(int i=0; i<row; i++)
			{
				for(int j=0; j<col; j++)
					path_locker[i][j] = true;
			}
			
			int get_row = 0, get_col = 0; 
			Cell copu = solution_stack[stack_position].Pop();
			solution_stack[stack_position].Push(current_cell.y, current_cell.x);
			
			path_locker[current_cell.x][current_cell.y] = false;
			s1.Push(current_cell.x, current_cell.y);
			
			while( !s1.IsEmpty() ) {
				get_row = current_cell.x;
				get_col = current_cell.y;
				
				//Marking My Maze Position as 'false'
				if(!(current_cell == Start_cell)) 
				{
					path_locker[get_row][get_col] = false;
				}
				
				if( boundary_check(current_cell.x+1, current_cell.y) || boundary_check(current_cell.x-1, current_cell.y) || boundary_check(current_cell.x, current_cell.y+1) || boundary_check(current_cell.x, current_cell.y-1)  )
				{
					//Cell c1 = solution_stack[stack_position].Pop();
					//solution_stack[stack_position+1] = solution_stack[stack_position];
					
					path_locker[current_cell.x][current_cell.y] = true;
						
					//solution_stack[stack_position].Push(c1.y, c1.x);
					solution_stack[stack_position].Push(Exit_cell.y, Exit_cell.x);
					
					stack_position++;
					
					if( !s1.IsEmpty())
					{
						Stack temp;
						Node *rhs_temp = s1.top;
						while( s1.top != 0 )
						{
							Cell c1 = s1.top->cell;
							s1.top = s1.top->next;
							temp.Push(c1.x, c1.y);
							c1 = temp.Peek();
							cout << "\nIn temp: " << c1.x << " " << c1.y << "\n";
						}
						s1.top = rhs_temp;
						Cell cc = solution_stack[stack_position].Pop();
						while( !temp.IsEmpty())
						{
							Cell c1 = temp.Pop();
							solution_stack[stack_position].Push(c1.x, c1.y);
				
							c1 = solution_stack[stack_position].Peek();
							cout << "\nIn My Stack: " << c1.x << " " << c1.y << "\n";
						}
						
						//solution_stack[stack_position] = s1;
						
						Cell checker = solution_stack[stack_position].Peek();
						cout << "\nStack 2: " << checker.x << " " << checker.y << "\n";
						current_cell = s1.Pop();
						path_locker[current_cell.x][current_cell.y] = true;
					}
				}
				else {
					Push_Unvisited_Path(get_row, get_col+1, path_locker);
					Push_Unvisited_Path(get_row+1, get_col, path_locker);
					Push_Unvisited_Path(get_row, get_col-1, path_locker);
					Push_Unvisited_Path(get_row-1, get_col, path_locker);
					
					if(varify == false && !solution_stack[stack_position].IsEmpty()) {
						Cell c2 = solution_stack[stack_position].Pop();
						c2.x = 0; c2.y = 0;
					
						if(!s1.IsEmpty()) {
							current_cell = s1.Pop();
							solution_stack[stack_position].Push(current_cell.y, current_cell.x);
						}
					}
					
					else {
						current_cell = s1.Pop();
						if(varify == true) {
							solution_stack[stack_position].Push(current_cell.y, current_cell.x);
						}
						varify = false;
					}
				}
			}
			
			for(int i=0; i>row; i++)
			{
				delete [] *(path_locker+i);
		
			}
			delete [] path_locker;
			//int i = 0;
			//while(i <= stack_position){
//			while(solution_stack[1].IsEmpty() != true)
//			{
//				Cell c1 = solution_stack[1].Pop();
//				cout << c1.x << " " << c1.y << "\n";
//				c1.x = 0; c1.y = 0;
//				
//			}
//			//	i++;
//			
//			delete [] solution_stack;
		}
		
		void Print_Stack_Solution()
        { 
        	int i = 0;
        	while(i < stack_position) {
        		
//            	while(!solution_stack[i].IsEmpty())
//            	{
//               		Cell c1 = solution_stack[i].Pop();
//               		cout << "( " << c1.x << " , " << c1.y << " )" << "\n";
//               		//c1 = solution_stack[i].
//            	}
				solution_stack[i].Print();
            	cout << "\n";
            	i++;
            }
        
           	delete [] solution_stack;
        }
};

int main() {
	int r, c;
	cin >> r >> c;
	Maze m1(r,c);
	m1.Input_Maze();
	m1.Solve_Maze();
//	cout << m1.Solve_Maze() << "\n";
//    cout << "\nSolution\n"; m1.Print_Stack_Solution();
	return 0;
}
