#include<iostream>
using namespace std;
struct Node {
	char operator_char;
	Node *next;
};
class Stack {
	private:
		Node *head, *top;
	public:
		Stack() {
			head = 0;
			top = 0;
		}
		
		//Pushing Elements in Stack
		void Push(char str) {
			Node *temp = new Node;
			temp->operator_char = str;
			temp->next = 0;
			
			if(head == 0) {
				head = temp;
				top = temp;
				head->next = 0;
				top->next = 0;
			}
			else {
				temp->next = top;
				top = temp;
			}
		}
		
		bool IsEmpty(void) {
			if(top == 0)
				return true;
			return false;
		}
		
		char Pop(void) {
			if(IsEmpty() == true)
				return ' ';
			else {
				char ch = top->operator_char;
				top = top->next;
				return ch;
			}
		}
		
		char Peek(void) {
			return top->operator_char;
		}
		~Stack() {
			if(IsEmpty() != true ) {
				while(IsEmpty() != true) {
					Node *temp = top;
					top = top->next;
					temp->next = 0;
					delete temp;
					temp = 0;
				}
			}
			delete top;
			top = 0;  
			delete head;
			head = 0;
		}
};

//Infix to Prefix And Postfix

class Conversion {
	public:
		Stack s1;
		string input_str, postfix_output_str, prefix_output_str;
	//public:
		Conversion() {
			postfix_output_str = ""; input_str = ""; prefix_output_str = "";
		}
		
		void Input_string(string str) {
			input_str = str;
		}
		
		int Precedence(char ch) {
			
			if(ch == '-' || ch == '+') return 1;
			if(ch  == '*' || ch == '/') return 2;
			if(ch == '^') return 3;
			
			return 0;
		}
		
		string Reverse_string(string inputt_str) {
			string reversee = inputt_str;
			int length = reversee.length();
			int j = length-1;
			for(int i=0; i<(length/2); i++) {
				char temp = reversee[i];
				reversee[i] = reversee[j];
				reversee[j] = temp;
				j--;
			}
			return reversee;
		}
		
		//Infix to Prefix
		void Infix_to_Prefix(void) {
		
			int i = 0, length = input_str.length();
			string reverse = Reverse_string(input_str);
			
			while(i < length) {

				if( reverse[i] != '-' && reverse[i] != '+' && reverse[i] != '*' && reverse[i] != '/'  && reverse[i] != '^' && reverse[i] != '(' && reverse[i] != ')' && reverse[i] != '[' && reverse[i] != ']'&& reverse[i] != '{' && reverse[i] != '}')
				{
					prefix_output_str += reverse[i];
					//cout << "\nPrefix Output: " << prefix_output_str << "\n";
				}
				
				//Put Close Parenthesis in Stack
				else if(reverse[i] == ')' || reverse[i] == '}' || reverse[i] == ']') {
					s1.Push(reverse[i]);
					//cout << "\nIn closing paraenthesis: " << s1.Peek() << "\n";
				}
				
				//Pop all the elements from Stack and Put Operators in output
				else if(reverse[i] == '(' || reverse[i] == '{' || reverse[i] == '[') {
					char ch = ' ';
					if(reverse[i] == '(') 
					{
						while( ch != ')' && s1.IsEmpty() == false ) {
				
							ch = s1.Pop();
							//cout << "\nValue of Ch: " << ch << " Peek : " << s1.Peek() << "\n";
					
							if(ch != ')' && ch != '}' && ch != ']') {
								prefix_output_str += ch;
								//cout << "\nIn Pop area: " << prefix_output_str << "\n";
							}
				
						}
					}
					else if(reverse[i] == '{') 
					{
						while( ch != '}' && s1.IsEmpty() == false ) {
				
							ch = s1.Pop();
							//cout << "\nValue of Ch: " << ch << " Peek : " << s1.Peek() << "\n";
					
							if(ch != ')' && ch != '}' && ch != ']') {
								prefix_output_str += ch;
								//cout << "\nIn Pop area: " << prefix_output_str << "\n";
							}
				
						}
					}
					else
					{
						while( ch != ']' && s1.IsEmpty() == false ) {
				
							ch = s1.Pop();
							//cout << "\nValue of Ch: " << ch << " Peek : " << s1.Peek() << "\n";
					
							if(ch != ')' && ch != '}' && ch != ']') {
								prefix_output_str += ch;
								//cout << "\nIn Pop area: " << prefix_output_str << "\n";
							}
						}
					}
				}
				
				//If Operator is found
				else if(s1.IsEmpty() || Precedence(reverse[i]) >= Precedence(s1.Peek()))  
				{
					s1.Push(reverse[i]);
					//cout << "\nIn Operator in stack: " << s1.Peek() << "\n";
				}
				else  
				{
					while( s1.IsEmpty() != true && !(Precedence(reverse[i]) >= Precedence(s1.Peek())))
					{
						char ch = s1.Pop();
	
						if(ch != ')'|| ch != '}' || ch != ']')
							prefix_output_str += ch;
					}
					s1.Push(reverse[i]);
				}
				i++;
			}
			if( s1.IsEmpty() == false) {
				while(s1.IsEmpty() != true)
				{
					prefix_output_str += s1.Pop();
					//cout << s1.Pop() << " ";
				}
			}
			cout << Reverse_string(prefix_output_str);
		}
		
		//Infix to Postfix	
		void Infix_Postfix(void) {
			
			int i = 0, length = input_str.length();
			Stack post_stack;
			
			while(i < length)
			{
				if( input_str[i] != '-' && input_str[i] != '+' && input_str[i] != '*' && input_str[i] != '/'  && input_str[i] != '^' && input_str[i] != '(' && input_str[i] != ')' && input_str[i] != '[' && input_str[i] != ']'&& input_str[i] != '{' && input_str[i] != '}')
				{
					postfix_output_str += input_str[i];
				}
				
				//Opening Paranthesis Put on Stack
				else if(input_str[i] == '(' || input_str[i] == '[' || input_str[i] == '{')
				{
					post_stack.Push(input_str[i]);
				}
				
				//Stack Empty & Operator
				else if( post_stack.IsEmpty()  && ( input_str[i] != ')' || input_str[i] != '}' && input_str[i] != ']') )
				{
					post_stack.Push(input_str[i]);
				}
				
				//Stack has an item & Operator
				else if ( !post_stack.IsEmpty() && Precedence(input_str[i]) > Precedence(post_stack.Peek()) && ( input_str[i] != ')' || input_str[i] != '}' && input_str[i] != ']') )
				{
					post_stack.Push(input_str[i]);
				}
				
				//If less Precedence
				else if( !post_stack.IsEmpty() && (Precedence(input_str[i]) <= Precedence(post_stack.Peek()) ) && ( input_str[i] != ')' && input_str[i] != '}' && input_str[i] != ']') )
				{
					if(post_stack.IsEmpty() != true)
					{
						while( post_stack.IsEmpty() == false && !(Precedence(input_str[i]) >= Precedence(post_stack.Peek()) ))
						{
							if(post_stack.IsEmpty()) break;
							postfix_output_str += post_stack.Pop();
						}
					}
					post_stack.Push(input_str[i]);
				}
				
				//If Closing Parenthesis then Pop out until Open parenthesis is found
				else if(input_str[i] == ')' || input_str[i] == '}' || input_str[i] == ']')
				{
					char ch = ' ';
					if(input_str[i] == ')') 
					{
						while( ch != '(' && post_stack.IsEmpty() == false ) {
				
							ch = post_stack.Pop();
					
							if(ch != '(' && ch != '{' && ch != '[') {
								postfix_output_str += ch;		
							}
						}
					}
					else if(input_str[i] == '}') 
					{
						while( ch != '{' && post_stack.IsEmpty() == false ) {
				
							ch = post_stack.Pop();
							
							if(ch != '(' && ch != '{' && ch != '[') {
								postfix_output_str += ch;
							}
						}
					}
					else
					{
						while( ch != '[' && post_stack.IsEmpty() == false ) {
				
							ch = post_stack.Pop();
							
							if(ch != '(' && ch != '{' && ch != '[') {
								postfix_output_str += ch;
							}
						}
					}
				}
				i++;				
			}
			if(post_stack.IsEmpty() == false) {
				while(post_stack.IsEmpty() != true ) 
				{
					if( post_stack.Peek() != '(' && post_stack.Peek() != '{' && post_stack.Peek() != '[' )
						postfix_output_str += post_stack.Pop();
					else
					{
						char opr = post_stack.Pop();
					}
				}
			}
			cout << endl << postfix_output_str;
		}	
		
		
		~Conversion() {
			
		}
};
int main() {
	Conversion c1;
	string str;
	cin >> str;
	c1.Input_string(str);
	c1.Infix_to_Prefix();
	c1.Infix_Postfix();
	return 0;
}
