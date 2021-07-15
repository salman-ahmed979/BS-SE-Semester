/****************************************************************************
* Author: Muhammad Rafi                                                    *
* Purpose: Example DynamicSafeArray2D                                      *
*          Linear Memory and two dimensional access                        *
* Dated: September 12, 2010                                                *
* Version: 3.0                                                             *                                                 
* Last modified: September 21, 2010                                        *
****************************************************************************/


#include<iostream>

using namespace std;

class DynamicSafeArray2D{
	
	  private:
	  	int * Data;
	  	unsigned int nRow;
	  	unsigned int nCol;
	  	
	  	
	  public:
	  	
	  	//Default Constructor 
	  	DynamicSafeArray2D(){
	  		nRow=nCol=0;
	  		Data=new int;
	  		Data=0;
	  	};
	  	//Parameteric Constructor 
	  	DynamicSafeArray2D(unsigned int r, unsigned int c){
	  		 nRow=r;
	  		 nCol=c;
	  		 int size=r*c;
	  		 Data = new int[size];
	  	}
	  	//Copy Constructor 
	   DynamicSafeArray2D(DynamicSafeArray2D& rhs){
	  		 nRow=rhs.nRow;
	  		 nCol=rhs.nCol;
	  		 int size=nRow*nCol;
	  		 Data = new int[size];
	  		 memcpy(this->Data, rhs.Data, sizeof(int)*size);
	  	}
	  	// Destructor 
	  	~DynamicSafeArray2D(){
	  		
	  		if (Data != 0)
	  		delete [] Data;
	  		Data=0;
	  		nRow=nCol=0;
	  		
	  		
	  	}
	  	
	  	// Assignment Operator 
	    DynamicSafeArray2D & operator=(const DynamicSafeArray2D & rhs){
	    	    	
			if (this != &rhs){
				
			 delete [] this->Data;
			 Data=0;
			 nRow=rhs.nRow;
	  		 nCol=rhs.nCol;
	  		 int size=nRow*nCol;
	  		 Data = new int[size];
	  		 memcpy(this->Data, rhs.Data, sizeof(int)*size);
					
			}	    	
	    	    	
	    	return (*this);
	    	
	    }
	
	 //lval
	 int& operator()( int i, int j) { 
	 
	  long offset= (i*nCol)+j;
	  return Data[offset];
	  }   // *((Data+ i*nCol)+j)
	 //rval
     const int& operator()( int i, int j) const {	 
	  long offset= (i*nCol)+j;
	  return Data[offset];
	  } 
	
	
	
	
	
};

int main(){
	
	DynamicSafeArray2D MyArray2D(3,3);
	DynamicSafeArray2D HisArray2D();
	DynamicSafeArray2D YourArray(MyArray2D);
	
	MyArray2D=YourArray;
	cout<< sizeof(MyArray2D) << endl;
	cout<< sizeof(YourArray) << endl;
	
	
	for(int i=0; i< 3; i++)
	{
	
	 for (int j=0; j < 3; j++)
	 {
	 	MyArray2D(i,j) = i+j;
	 }
	  
	}
	
	
	
	
	for(int i=0; i< 3; i++)
	{
	 for (int j=0; j < 3; j++)
	 {
	 	cout<< MyArray2D(i,j) << " " ;
	 }
	  cout << endl;
	}
	
	return 0;
}
