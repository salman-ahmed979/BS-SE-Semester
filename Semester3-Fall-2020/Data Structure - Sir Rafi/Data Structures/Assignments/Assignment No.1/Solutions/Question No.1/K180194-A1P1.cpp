#include<iostream>
#include<fstream>
using namespace std;

class Puzzle{
	private:
		int n, m;
		char **puzzle;
		int a;
		string *dictionary;
		char **output;
	public:
		void get_data()//function to input data from file
		{
			ifstream infile;
			infile.open("input4.txt");
			infile>>n;
			infile>>m;
			puzzle = new char * [n];
			for(int i=0;i<n;i++)
			{
				puzzle[i] = new char [m];
			}
			for(int i=0;i<n;i++)
			{
				infile>>puzzle[i];
			}
			infile>>a;
			dictionary = new string [a];
			for(int i=0;i<a;i++)
			{
				infile>>dictionary[i];
			}
			infile.close();
		}
		
		char** solve()
		{
			int temp = 0;
			output = new char * [6];
			for(int i=0;i<6;i++)
			{
				output[i] = new char [2];
				output[i][0] = 'n';
				output[i][1] = ' ';
			}
			
			m = m + m/2;
			
			for(int k=0;k<a;k++)
			{	
				for(int i=0;i<n;i++)
				{
					for(int j=0;j<m;j++)
					{
						if(puzzle[i][j] == dictionary[k][0])
						{
							if(dictionary[k].size() <= (m-j))//check if we can find solution or not on right side
							{
								//if it is possible on right
								for(int l=0, o = j;l<dictionary[k].size()-1, o < (dictionary[k].size() + j)-1;l++, o++)//loop for iterating through the individual char in the dictionary's word
								{
									if(puzzle[i][o+1] == dictionary[k][l+1])//checking if every char of puzzle is equivalent ot dictionary
									{
										temp = 1;
									}
									else
									{
										temp = 0;
										break;
									}
								}
								if(temp == 0)
								{
									if(dictionary[k].size() <= (j+1))//check if we can find the solution on left side
									{
										//if it is possible on left
										for(int l=0, o=j;l<dictionary[k].size()-1, o>(dictionary[k].size()-j)+1;l++, o--)
										{
											if(puzzle[i][o-1] == dictionary[k][l+1])//checking if every char of puzzle is equivalent ot dictionary
											{
												temp = 1;
											}
											else
											{
												temp = 0;
												break;
											}
										}
									}
								}
								if(temp == 0)
								{
									if(dictionary[k].size() <= (i+1))//check if we can find the solution on upwards
									{		
										//if it is possible upwards
										for(int l=0, o=i;l<dictionary[k].size()-1, o>(dictionary[k].size()-i)+1;l++, o--)
										{
											if(puzzle[o-1][j] == dictionary[k][l+1])//checking if every char of puzzle is equivalent ot dictionary
											{
												temp = 1;
											}
											else
											{
												temp = 0;
												break;
											}
										}
									}
								}
								if(temp == 0)
								{
									if(dictionary[k].size() <= (n-i))//check if we can find the solution downwards 
									{	
										//if it is possible downwards
										for(int l=0, o = i;l<dictionary[k].size()-1, o<(dictionary[k].size()+i)-1;l++, o++)
										{
											if(puzzle[o+1][j] == dictionary[k][l+1])//checking if every char of puzzle is equivalent ot dictionary
											{
												temp = 1;
											}
											else
											{
												temp = 0;
												break;
											}
										}
									}
								}
								if(temp == 1)
								{
									output[k][0] = i + 48;
									output[k][1] = j + 48;
									break;
								}
							}
						}
					}
				}
			}
			
			return output;
		}
		
		void put_data()//function to output data to file
		{
			char **ptr;
			ptr = solve();
			ofstream outfile;
			outfile.open("output4.txt");
			for(int i=0;i<a;i++)
			{
				for(int j=0;j<2;j++)
				{
					outfile<<ptr[i][j];
				}
				outfile<<endl;
			}
		}
};

int main(void)
{
	Puzzle P;
	P.get_data();
	P.solve();
	P.put_data();
}
