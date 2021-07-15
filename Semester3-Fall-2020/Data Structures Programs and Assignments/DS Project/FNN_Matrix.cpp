#include<bits/stdc++.h>
using namespace std;

//Neuron activation with sigmoid function
static double sigmoid(double x) {
    return (1 / (1 + exp(-x)));
}

//Derivative-sigmoid function
//Assuming the value is pre-sigmoid
static double derivative_sigmid(double x) {
    return (x * (1-x));
}

//Creating template class of matrix-2d
template<class T>
class matrix {

    private:
        int rows, col;
        int track_row, track_col;
        T **data;

    public:

        //Default Constructor
        matrix() {
            rows = 0; track_row = 0;
            col = 0; track_col = 0;
            data = 0;
        }

        //Constructor Create row * col matrix
        matrix(int r, int c) {
            rows = r; track_row = 0;
            col = c; track_col = 0;
            //Create Array of rows
            data = new T*[rows];
            //Create columns of 2d Array
            for(int i=0; i < rows; i++) 
                data[i] = new T[col];
            //fill zeros
            for(int i=0; i < rows; i++) {
                for(int j=0; j < col; j++)
                    data[i][j] = 0;
            }
        }

        //Destructor
        ~matrix() {
            if(data != 0)
            {
                //free memory in reverse order
                for(int i=rows-1; i >= 0; i--) {
                    if(data[i] != 0) {
                        data[i] = 0;
                        delete [] data[i];
                    }
                }
                rows = 0; col = 0;
                delete [] data;
            }
        }

        //Delete data memory
        void delete_data_memory(void) {
            if(data != 0)
            {
                //free memory in reverse order
                for(int i=rows-1; i >= 0; i--) {
                    if(data[i] != 0) {
                        data[i] = 0;
                        delete [] data[i];
                    }
                }
                rows = 0; col = 0;
                delete [] data;
            }
        }

        //Copy Constructor
        matrix(const matrix &rhs) {
            rows = rhs.rows;
            col = rhs.col;
            //Create Array of rows
            data = new T*[rows];
            //Create columns of 2d Array
            for(int i=0; i < rows; i++) 
                data[i] = new T[col];
            //fill data with rhs-data
            for(int i=0; i < rows; i++) {
                for(int j=0; j < col; j++)
                    data[i][j] = rhs.data[i][j];
            }
        }

        //Assignment Operator overload
        matrix& operator=(const matrix &rhs) {
            if(this != &rhs)
            {
                //Delete previous matrix
                delete_data_memory();
                rows = rhs.rows;
                col = rhs.col;
                //Create matrix
                data = new T*[rows];
                //Create columns of 2d Array
                 for(int i=0; i < rows; i++) 
                    data[i] = new T[col];
                 //fill data with rhs-data
                for(int i=0; i < rows; i++) {
                    for(int j=0; j < col; j++)
                        data[i][j] = rhs.data[i][j];
                }
            }
            return *this;
        }

        //Print the matrix
        void Print_matrix(void) {
            for(int i=0; i < rows; i++) {
                for(int j=0; j < col; j++)
                    cout << data[i][j] << " ";
                cout << "\n";
            }
        }
        
        //Resize the matrix
        void Resize(int r, int c) {
            //Delete old memory
            delete_data_memory();
            rows = r;
            col = c;
            //Create Array of rows
            data = new T*[rows];
            //Create columns of 2d Array
            for(int i=0; i < rows; i++) 
                data[i] = new T[col];
            //fill zeros
            for(int i=0; i < rows; i++) {
                for(int j=0; j < col; j++)
                    data[i][j] = 0;
            }
        }

        //Multiply the matrix with a number
        void scalar_multiply(const T num) {
            //Store the multiplication in the matrix
            for(int i=0; i < rows; i++) {
                for(int j=0; j < col; j++)
                    data[i][j] *= num;
            }
        }

        //Multiplication with another matrix c = r'
        //Hadamard Product
        void multiplication_hadamard(const matrix &rhs) {
            //Store the multiplication in the matrix
            for(int i=0; i < rows; i++) {
                for(int j=0; j < col; j++)
                    data[i][j] *= rhs.data[i][j];
            }
        }

        //Dot product of two matrix
        //Store in another matrix
        void product(const matrix &a, const matrix &b) {
            //Check whether matrix1 column 
            //equal to matrix2 row
            if(a.col != b.rows) {
                cout << "\nDot product is not possible\n";
                return;
            }
            Resize(a.rows, b.col);
            for(int i=0; i < rows; i++) {
                for(int j=0; j < col; j++) {
                    //Dot product of values in column
                    T sum = 0;
                    for(int k=0; k < a.col; k++) {
                        sum += a.data[i][k] * b.data[k][j];
                    }
                    data[i][j] = sum;
                }
            }
        }

        //Transpose of the right-hand side matrix
        void transpose(const matrix &rhs) {
            Resize(rhs.rows, rhs.col);
            for(int i=0; i < rows; i++) {
                for(int j=0; j < col; j++)
                    data[j][i] = rhs.data[i][j];
            }
        }

        //Input the data in matrix
        void Input_data(T d) {
            if(track_col < col)
            {
                data[track_row][track_col] = d;
                track_col++;
            }
            else if(track_row < rows) { 
                track_row++;
                track_col = 0;
                data[track_row][track_col] = d;
                track_col++;
            }
        }

        //Add matrix with onther matrix
        void add(const matrix &rhs) {
            //If dimension are not same
            if(rows != rhs.rows)
            {
                cout << "\nAddition is not possible\n";
                return;
            }
            for(int i=0; i < rows; i++) {
                for(int j=0; j < col; j++)
                    data[i][j] += rhs.data[i][j];
            }
        }

        //Add matrix with a value
        void add_value(int num) {
            for(int i=0; i < rows; i++) {
                for(int j=0; j < col; j++)
                    data[i][j] += num;
            }
        }

        //Subtract two matrix and store it in other
        void subtract(const matrix &a, const matrix &b) {
            //If dimension are not same
            if(a.rows != b.rows)
            {
                cout << "\nSubtraction is not possible\n";
                return;
            }
            //Resize and change the calling object
            Resize(a.rows, a.col);
            for(int i=0; i < rows; i++) {
                for(int j=0; j < col; j++)
                    data[i][j] = a.data[i][j] - b.data[i][j];
            }
        }

        //Random function to generate random value
        void randomize(void) {
            //take seek value of time
            srand((unsigned) time (NULL));
            for(int i=0; i < rows; i++) {
                for(int j=0; j < col; j++)
                    data[i][j] = ((T) rand() / RAND_MAX) * 2 - 1;
            }
        }

        //Sigmoid map to neurons
        void map_sigmoid(void) {
            for(int i=0; i < rows; i++) {
                for(int j=0; j < col; j++) {
                    double value = data[i][j];
                    data[i][j] = sigmoid(value);
                }
            }
        }

        //Derivative map to neurons
        void map_derivative_sigmoid(void) {
            for(int i=0; i < rows; i++) {
                for(int j=0; j < col; j++) {
                    double value = data[i][j];
                    data[i][j] = derivative_sigmoid(value);
                }
            }
        }

        //function to set target of a particular train value
        void set_target(double value) {
            for(int i=0; i < rows; i++) {
                if(i == value) 
                    data[i][0] = 1;
                else 
                    data[i][0] = 0;
            }
        }

        //Copy the right-handside matrix data value
        //with Max pixel range division
        void copy_data_value(const matrix<T> &rhs) {
            Resize(rhs.rows, 1);
            for(int i=0; i < rows; i++) {
                for(int j=0; j < rhs.col; j++) {
                   data[i][0] = rhs.data[i][j] / 255;
                }
            }
        }

        //function to get max prediction
        int max(void) {
            T max_value = data[0][0];
            int index = 0;
            for(int i=0; i < rows; i++) {
                if(max_value < data[i][j]) {
                    max_value = data[i][j];
                    index = i;
                }
            }
            cout << "\nPredicted " << index << " % : " << (max_value / 1)*100;
            return index;
        }

        //Save function to store the input
        void save(string name) {
            ofstream myfile(name);
            if(myfile.is_open())
            {
                for(int i=0; i < rows; i++) {
                    for(int j=0; j < col; j++) {
                        myfile << data[i][j];
                        myfile << ",";
                    }
                    myfile << "\n";
                }
                myfile.close();
            }
        }

        //Read function to read the data from file
        void read(string name) {
            ifstream myfile(name);
            int row = 0, column = 0;
            while(myfile.good())
            {
                string value;
                getline(myfile, value);
                stringstream string_stream (value);
                string input;
                while(getline(string_stream, input, ","))
                {
                    data[row][column] = stod(input);
                    column++;
                }
                row++;
                column = 0;
            }
            myfile.close();
        }
};

//Class for Neural Network
template<class T>
class neural_network {

    private:
        int input_nodes, hidden_nodes, output_nodes;
        matrix<T> weight_ih, weight_ho, bias_h, bias_o;
        double learning_rate;

        public:

            //Constructor
            neural_network(int input_nod, int hidden_nod, int output_nod) {
                //Setting the layers
                input_nodes = input_nod;
                hidden_nodes = hidden_nod;
                output_nodes = output_nod;

                //Setting the weights
                weight_ih(hidden_nodes, input_nodes);
                weight_ho(output_nodes, hidden_nodes);

                //Randomize the weights value
                weight_ih.randomize();
                weight_ho.randomize();

                //Setting the biases
                bias_h(hidden_nodes, 1);
                bias_o(output_nodes, 1);

                //Randomize the biases value
                bias_h.randomize();
                bias_o.randomize();

                learning_rate = 0.1;
            } 

            //Feed-Forward Neural network
            matrix<T> feedforward(matrix<T> &input) {
                //matrix for input to hidden
                matrix<T> hidden(weight_ih.rows, input.col);
                //dot product
                hidden.product(weight_ih, input);
                hidden.add(bias_h);
                hidden.map_sigmoid(); // fire the neurons

                //matrix for hidden to output
                matrix<T> output(weight_ho.rows, hidden.col);
                //dot product
                output.product(weight_ho, hidden);
                output.add(bias_o);
                output.map_sigmoid(); // fire the neurons

                return output;
            }

            //Train the neural network
            //Adjust the weights
            void train(matrix<T> &input, matrix<T> &targets) {
                //matrix for input hidden layer
                matrix<T> hidden(weight_ih.rows, input.col);
                
                //dot product
                hidden.product(weight_ih, input);
                hidden.add(bias_h);
                hidden.map_sigmoid(); // fire the neurons

                //matrix for hidden to output
                matrix<T> output(weight_ho.rows, hidden.col);
                //dot product
                output.product(weight_ho, hidden);
                output.add(bias_o);
                output.map_sigmoid(); // fire the neurons

                //Calculate the output errors
                matrix<T> output_errors(targets.rows, target.col);
                output_errors.subtract(targets, output);

                //Calculate the gradients
                output.map_derivative_sigmoid();
                output.multiplication_hadamard(output_errors);
                output.scalar_multiply(learning_rate);

                //Weights deltas
                //W' = learning_rate*E(error)*Derivative_sigmoid(output)*hidden^transpose
                
                matrix<T> hidden_trans;
                hidden_trans.transpose(hidden);
                matrix<T> weights_ho_delta(output.rows, hidden_trans.col);
                weights_ho_delta.product(output, hidden_trans);

                //Adjust weights by deltas
                weight_ho.add(weights_ho_delta);

                //Adjust bias hidden to output
                bias_o.add(output);

                //Calculate the hidden errors
                matrix<T> hidden_error;
                hidden_error.transpose(weight_ho);
                hidden_error.product(hidden_error,output_errors);

                //Calculate the hidden gradients
                hidden.map_derivative_sigmoid();
                hidden.multiplication_hadamard(hidden_error);
                hidden.scalar_multiply(learning_rate);

                //Calculate input -> hidden deltas
                matrix<T> input_trans;
                input_trans.transpose(input);
                matrix<T> weights_ih_delta(hidden.rows, input_trans.col);
                weights_ih_delta.product(hidden, input_trans);

                //Adjust weights of input to hidden by deltas
                weight_ih.add(weights_ih_delta);

                //Adjust the bias input to hidden
                bias_h.add(hidden);
            }

            //Save the data of neural network
            void save_Data(void) {
                weight_ih.save("weight_ih.csv");
                weight_ho.save("weight_ho.csv");
                bias_h.save("bias_h.csv");
                bias_o.save("bias_o.csv");
            }
            
            //Read the data of neural network
            void feed_data(void) {
                weight_ih.read("weight_ih.csv");
                weight_ho.read("weight_ho.csv");
                bias_h.read("bias_h.csv");
                bias_o.read("bias_o.csv");
            }

            
};
int main()
{
    matrix<int>m1(4,3), m2(1,2),m3;
    m1.Print_matrix();
    m1 = m2;
    m1.Print_matrix();
    for(int k=3; k < 5; k++)
        m1.Input_data(k);
    m1.Print_matrix();
    m2.Resize(2,1);
    m2.Input_data(7); m2.Input_data(77);m3.product(m1,m2);
    m3.Print_matrix();

    //Neural network
    neural_network<double> nn(2,1,1);
    

    return 0;
}