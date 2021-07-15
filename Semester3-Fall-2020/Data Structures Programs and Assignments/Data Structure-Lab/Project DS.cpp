#include<iostream>
#include<string>
#include<string.h>
#include<cmath>
#include<time.h>
#include<sstream>
#include<vector>
#include<fstream>
using namespace std;

double sigmod(double x)
{
    return (1/(1+exp(-x)));
}
double derivative_sigmod(double x)
{
    return x*(1-x);
}
template<class T>
class matrix1
{
    private:
    
    T **data;
    public:
    int row;
    int col;
    matrix1()
    {
        row=0;
        col=0;
        data=NULL;
    }
    matrix1(int row,int col)
    {
        this->row=row;
        this->col=col;
        data=new T*[row];
        for(int i=0;i<row;i++)
        {
            *(data+i)=new T[col];
            for(int j=0;j<col;j++)
            {
                *(*(data+i)+j)=0;
            }
        }
    }
    matrix1(const matrix1<T> &rhs)
    {
        this->row=rhs.row;
        this->col=rhs.col;
        this->data=new T*[row];
        for(int i=0;i<row;i++)
        {
            *(data+i)=new T[col];
            for(int j=0;j<col;j++)
            {
                *(* (data+i)+j)=*(* (rhs.data+i)+j);
            }
        }
        
    }
    matrix1<T>& operator=(const matrix1<T> &rhs)
    {
        if(this!=&rhs)
        {
            this->row=rhs.row;
            this->col=rhs.col;
            this->data=new T*[row];
            for(int i=0;i<row;i++)
            {
                *(data+i)=new T[col];
                for(int j=0;j<col;j++)
                {
                    *(* (data+i)+j)=*(* (rhs.data+i)+j);
                }
            }
        }
        return *this;
    }
    void dot_product(const matrix1<T> &a,const matrix1<T> &b)
    {
        //matrix1<T> ans(a.row,b.col);
        if(a.col!=b.row)
        {
            cout<<"Error In Multiplication"<<endl;
            //return ans;
        }
        else if(a.col==b.row)
        {
            
            for(int i=0;i<a.row;i++)
            {
                for(int j=0;j<b.col;j++)
                {
                    double sum=0;
                    for(int k=0;k<a.col;k++)
                    {
                        sum=sum+(*(*(a.data+i)+k))*(*(*(b.data+k)+j));
                    }
                    *(*(this->data+i)+j)=sum;
                }
            }
        }
       
        //return ans;
    }
    void scalar_product(const double num)
    {
        //matrix1<T> ans(this->row,this->col);
        for(int i=0;i<this->row;i++)
        {
            for(int j=0;j<this->col;j++)
            {
                *(*(this->data+i)+j)= *(*(this->data+i)+j) * num;
            }
        }
            //return ans;
    }

    void hadamard_product(const matrix1<T> &a)
    {
       // matrix1<T> ans(this->row,this->col);
        for(int i=0;i<this->row;i++)
        {
            for(int j=0;j<this->col;j++)
            {
                *(*(this->data+i)+j)= (*(*(this->data+i)+j)) * (*(*(a.data+i)+j));
            }
        }
            //return ans;
    }
    void add(const matrix1<T> &a)
    {
       // matrix1<T> ans(a.row,a.col);
        
        if(this->row==a.row && this->col==a.col)
        {
            for(int i=0;i<a.row;i++)
            {
                for(int j=0;j<a.col;j++)
                {
                    *(*(this->data+i)+j)= *(*(this->data+i)+j) + *(*(a.data+i)+j);
                }
            }
            //return ans;
        }
        else
        {
            cout<<"Error In Adding"<<endl;
        }
        

    } 
    void subtract(const matrix1<T> &a,const matrix1<T> &b)
    {
        //matrix1<T> ans(a.row,a.col);
        for(int i=0;i<a.row;i++)
        {
            for(int j=0;j<a.col;j++)
            {
                *(*(this->data+i)+j)= *(*(a.data+i)+j) - *(*(b.data+i)+j);
            }
        }
          //  return ans;
    } 
    void maping1()
    {
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                double val=*(*(this->data+i)+j);
                *(*(this->data+i)+j)=sigmod(val);

            }

        }
    }
    void maping2()
    {
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                double val=*(*(this->data+i)+j);
                *(*(this->data+i)+j)=derivative_sigmod(val);

            }

        }
    }
    void randomize()
    {
        srand((unsigned)time(NULL));
        for(int i=0;i<this->row;i++)
        {
            for(int j=0;j<this->col;j++)
            {
                *(*(data+i)+j)=((double)rand()/RAND_MAX)*2-1;
            }
        }
    }
    
    matrix1<T> transpose(const matrix1<T> &rhs)
    {
        matrix1 ans(rhs.col,rhs.row);
        for(int i=0;i<rhs.row;i++)
        {
            for(int j=0;j<rhs.col;j++)
            *(*(this->data+j)+i)=(*(*(rhs.data+i)+j));
        }
        
        return ans;
    }
    //copy val 
    void set_target(const double val)
    {
        for(int i=0;i<this->row;i++)
        {
            if(i==val)
            {
                *(*(data+i)+0)=1;   
            }
            else
            {
                *(*(data+i)+0)=0;
            }
            
        }
    }
    void copy_data_vel(const vector<T> &rhs)
    {
        
        this->row=rhs.size();
        this->col=1;
        data=new T*[row];
        for(int i=0;i<row;i++)
        {
            *(data+i)=new T[col];
            for(int j=0;j<col;j++)
            {
                *(*(data+i)+j)=rhs[i]/225;
            }
        }
        
    }
    // get max
    int max()
    {
        T val=*(*(this->data+0)+0);
        int num=0;
        for(int i=0;i<this->row;i++)
        {
            if(*(*(this->data+i)+0)>val)
            {
                val=*(*(this->data+i)+0);
                num=i;
            }
        }
        cout<<"     Predicted: "<<num<<" % : "<<(val/1)*100;
		return num;
    }
    void Initiallize(int row,int col)
    {
        this->row=row;
        this->col=col;
        this->data=new T*[row];
        for(int i=0;i<row;i++)
        {
            *(data+i)=new T[col];
            for(int j=0;j<col;j++)
            {
                *(*(data+i)+j)=0;
            }
        }
        
    }
    void memoryfree()
    {
        if(data!=0)
        {
            for(int i=row-1;i>0;i--)
            {
                if(*(data+i)!=0)
                {
                    delete [] *(data+i);
                    *(data+i)=0;
                }
            }
        }
        delete [] data;
        data=0;
    }
    ~matrix1()
    {

        if(data!=0)
        {
            for(int i=row-1;i>0;i--)
            {
                if(*(data+i)!=0)
                {
                    delete [] *(data+i);
                    *(data+i)=0;
                }
            }
        }
        delete [] data;
        data=0;
       
    }

    void save(string name){
        ofstream myfile (name);
        if (myfile.is_open())
        {
            int i=0;
            while(i<this->row){
                for(int j=0;j<this->col;j++){
                    myfile<<data[i][j];
                    myfile<<",";
                }
                myfile<<"\n";
                i++;
                
            }
            myfile.close();
        }	
	}

    void read(string name){
        ifstream input(name);
        int roww=0,coll=0;
        while(input.good()){
            
            string val;
            getline(input,val);
            
            stringstream ss(val);
            string inp;
            while(getline(ss,inp,',')){
                
                data[roww][coll]=stod(inp);
              // cout<<stoi(inp);
                //cout<<data[row][col]<<endl;
                coll++;
                
            // if(col==){
            //     col=0;
            //     row++;
            // }

           }
           coll=0;
           roww++;
        
        }
        input.close();
      //  return label_test;
    }


};
template<class TT>
class neural_network
{
    private:
		int input_nodes,hidden_nodes,output_node;
		matrix1<TT> weight_ih;
        matrix1<TT> weight_ho;
		matrix1<TT> bias_h;
        matrix1<TT> bias_o;
		double learning_rate;
	public:
    neural_network()
    {

    }
	
	neural_network(int input_n,int hidden_n,int output_n){
		input_nodes=input_n;
		hidden_nodes=hidden_n;
		output_node=output_n;
		
		weight_ih.Initiallize(hidden_nodes,input_nodes);
		weight_ho.Initiallize(output_node,hidden_nodes);

        weight_ih.randomize();
        weight_ho.randomize();

		bias_h.Initiallize(hidden_nodes,1);
		bias_o.Initiallize(output_node,1);

		bias_h.randomize();
		bias_o.randomize();

		learning_rate=0.1;
        

	}
	
	
	matrix1<TT> feedforward(matrix1<TT> &input){
		matrix1<TT> hidden(weight_ih.row,input.col);
		hidden.dot_product(weight_ih,input);
		hidden.add(bias_h);
		hidden.maping1();

		matrix1<TT> outputt(weight_ho.row,hidden.col);
		outputt.dot_product(weight_ho,hidden);
		outputt.add(bias_o);
		outputt.maping1();
		
		return outputt;
	}

	void train(matrix1<TT> &input,matrix1<TT> &targets){
		
		matrix1<TT> hidden(weight_ih.row,input.col);
       
		hidden.dot_product(weight_ih,input);
        
        hidden.add(bias_h);
      
        hidden.maping1();
	
		//second layer
		matrix1<TT> output(weight_ho.row,hidden.col);
		output.dot_product(weight_ho,hidden);
        
		output.add(bias_o);
		output.maping1();
		
		
		//calculating output error
		matrix1<TT> output_errors(targets.row,targets.col);
		output_errors.subtract(targets,output);
		

		// calculate gradint   
	
		//matrix1<TT> gradient;
		//gradient=output;
		output.maping2();
		output.hadamard_product(output_errors);
		output.scalar_product(learning_rate);

		//gradient delta
		//matrix1<TT> hidden_T;

	    
       matrix1<TT> h= h.transpose(hidden);
		matrix1<TT> weight_ho_delta(output.row,h.col);
        
		weight_ho_delta.dot_product(output,h);
       
        

		//adjust weights
	    weight_ho.add(weight_ho_delta);

		//adjust biases
	    bias_o.add(output);
		

   
		//calculating hidden erros:
		matrix1<TT> w=w.transpose(weight_ho);
        
		w.dot_product(w,output_errors);
       
	
		
	
		hidden.maping2();
		hidden.hadamard_product(w);
		hidden.scalar_product(learning_rate);

		//calculatig of gradient delta of input layer
		matrix1<TT> in=in.transpose(input);
        matrix1<TT> dot(hidden.row,in.col);
		dot.dot_product(hidden,in);
        

		//adjust weights
		weight_ih.add(dot);
		//adjust bias
		bias_h.add(hidden);
        





	}

    void save_Data(){
        weight_ih.save("weight_ih.csv");
        weight_ho.save("weight_ho.csv");
        bias_h.save("bias_h.csv");
        bias_o.save("bias_o.csv");
    }
    void feed_data(){
        weight_ih.read("weight_ih.csv");
        weight_ho.read("weight_ho.csv");
        bias_h.read("bias_h.csv");
        bias_o.read("bias_o.csv");
    }
 /*   void store()
    {
        fstream file_in;
            file_in.open("result.bin",ios::out);
            if(!file_in)
            {
                cout<<"Error In Loading..."<<endl;
            }
            else
            {
                file_in.write((char*)this,sizeof(this));
                cout<<"Save In File Succesfully"<<endl;

            }
            file_in.close();
            
    }
    void store_run()
    {
        fstream file_out;
            file_out.open("result.bin",ios::in);
            if(!file_out)
            {
                
                cout<<"Error In Loading..."<<endl;
            }
            else
            {
               file_out.read((char*)this,sizeof(this));

            }
            file_out.close();
    }*/
	

};

vector< vector<double> > data_test;
vector<double> read_data()
{
    ifstream input("mnist_test.csv");
    vector<double> label_test;
	
	
	int row=0,col=0;
	while(input.good()){
		
		string val;
		getline(input,val);
		if(row!=0){
			stringstream ss(val);
			string inp;
			vector<double> dat_row;
			while(getline(ss,inp,',')){
				if(col==0)
					label_test.push_back(stod(inp));
				else
					dat_row.push_back(stod(inp));
				col++;
			}

			data_test.push_back(dat_row);
				
			if(col==785){
				col=0;
				row++;
			}
		}
		else{
			row++;
		}
	}
	input.close();
    return label_test;
}
void test_run(vector<vector<double>> & data_train,vector<double> &label_train,vector<double> &label_test)
{
    	//create network
        neural_network<double> nn(784,30,10);
        matrix1<double> input_arr(1,1);
        matrix1<double> target_arr(10,1);
        fflush(stdin);	
        for(int	i=0;i<60000;i++)
        {
			
			input_arr.copy_data_vel(data_train[i]);
			target_arr.set_target(label_train[i]);
			nn.train(input_arr,target_arr);
            input_arr.memoryfree();
            target_arr.memoryfree();
            input_arr.Initiallize(1,1);
            target_arr.Initiallize(10,1);
			cout<<i<<endl;
		}
        nn.save_Data();

         //nn.store();
        int success=0;
	    for(int i=0;i<10000;i++)
        {
			
			cout<<"Target: "<<label_test[i];
			
			input_arr.copy_data_vel(data_test[i]);
			if(nn.feedforward(input_arr).max()==label_test[i])
            {
                success++;
            }
            input_arr.memoryfree();
            input_arr.Initiallize(1,1);
			cout<<endl;

	}

	    cout<<endl<<"  Total % Of Successfull Prediction: "<<success<<endl;
       
}
void test_run2(vector<double> &label_test)
{
        neural_network<double> nnn(784,30,10);//(784,30,10);
      // nnn.store_run();nnn
        nnn.feed_data();
        matrix1<double> input_arr(1,1);
         int success=0;
	    for(int i=0;i<10000;i++)
        {
			
			cout<<"Target: "<<label_test[i];
			
			input_arr.copy_data_vel(data_test[i]);
			if(nnn.feedforward(input_arr).max()==label_test[i])
            {
                success++;
            }
            input_arr.memoryfree();
            input_arr.Initiallize(1,1);
			cout<<endl;

	}

	    cout<<endl<<"  Total % Of Successfull Prediction: "<<success<<endl;

}
void read_train(vector<double>& label_test,int check)
{
    //read train data
	ifstream input2("mnist_train.csv");
		vector< vector<double> > data_train;
        vector<double> label_train;
		
		int row=0,col=0;
		while(input2.good()){
			
			string val2;
			getline(input2,val2);
			if(row!=0){
				stringstream ss2(val2);
				string inp2;
				vector<double> dat_row2;
				while(getline(ss2,inp2,',')){
					if(col==0)
						label_train.push_back(stod(inp2));
					else
						dat_row2.push_back(stod(inp2));
					col++;
				}

				data_train.push_back(dat_row2);
					
				if(col==785){
					col=0;
					row++;
				}
			}
			else{
				row++;
			}
		}
		input2.close();
        if(check==1)
        {
            test_run(data_train,label_train,label_test);
        }
        else if( check==2)
        {
            test_run2(label_test);
        }
        
        
}


int main()
{
    
    int choice;
    cout<<"Enter [1] To Train Again "<<endl;
    cout<<"Enter [2] To Predict On Previous Trainng "<<endl;
    cout<<"Enter [3] To Exit Code "<<endl<<endl;
    cin>>choice;
    
    switch (choice)
    {
        case 1:
        { 
            vector<double> label_testt=read_data();
            read_train(label_testt,1);
            break;
        
        }
        case 2:
        {
            vector<double> label_testt=read_data();
            read_train(label_testt,2);
            break;
        }
        case 3:
        {
            exit(0);
            break;
        }
        default:
        {
            cout<<" Wrong Choice "<<endl;
            break;
        }
    }

    
	

	
    return 0;
}