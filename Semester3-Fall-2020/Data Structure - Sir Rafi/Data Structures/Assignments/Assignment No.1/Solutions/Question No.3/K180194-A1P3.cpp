#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

class UniqueCharInString{
	private:
		char* str;
	public:
		UniqueCharInString(){
			this->str = new char [80];
		}
		
		void input(){
			ifstream infile;
			infile.open("input.txt");
			infile.getline(str, 80);
			infile.close();
		}
		
		void transform(){
			for(int i=0; str[i] != '\0'; i++)
			{
				for(int j=0;j<i;j++)
				{
					if((str[i]  != str[j]) && (toupper(str[i]) != str[j]) )
					{
						if(str[i] == (toupper(str[i])))
						{
							if(str[i] == ' ')
							{
								str[i] = ' ';
							}
							else
							{
								str[i] = '-';
							}
						}
						else
						{
							str[i] = str[i];
						}
					}
					else
					{
						if(str[i] == ' ')
						{
							str[i] = str[i];
						}
						else
						{
							str[i] = '-';
						}
					}
				}
			}
		}
		
		void output(){
			int i=0;
			ofstream outfile("output.txt");
			while(str[i] != '\0')
			{
				outfile<<str[i];
				i++;
			}
			cout<<"The Modifications have been applied to the file"<<endl;
			outfile.close();
		}
		
		~UniqueCharInString(){
			delete[] str;
		}
};

int main(void)
{
	UniqueCharInString A;
	A.input();
	A.transform();
	A.output();
}
