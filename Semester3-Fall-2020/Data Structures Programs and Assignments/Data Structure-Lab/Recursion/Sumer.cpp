#include<iostream>
#include<cstdlib>
using namespace std;

//This function will check individual elements whether they are target-sum or Not 
bool Individual_existance_sum(int arr[], int size, int target_sum) {
	for(int i = 0; i<size; i++) {
		if(arr[i] == target_sum)
			return true;
	}
	return false;
}

//Function for making of elements to acheive target-sum
void Sumer (int arr[], int size, int current_index, int next_index, int traversal, int sum, int target_sum) {
	//Base Case
	
	//If current_index exceed from size and unable to find target-sum
	//Program must say 'No' and terminate 
	//There was problem in getting perfect answer due to too many return call 
	//As answer was accurate but program was not terminating
	//That's why used Exit function	
	if(current_index > size-1) {
		cout << "NO";
		exit(0);
	}
	//go back if next-index or traversal exceed size 
	if(next_index > size-1 || traversal > size-1) {
		sum = 0;
		return;
	}
	
	if(sum == 0) {
		if(current_index!=next_index)
			sum = arr[current_index] + arr[next_index];
	}
	//If target-sum is acheived then print 'YES' and terminate program
	if(sum == target_sum && sum != 0) {
		cout << "YES";
		exit(0);
		//return;
	}
	
	// Always check traversal that it must not be on same index and next index
	if(traversal != current_index && traversal != next_index && sum != 0 && sum != target_sum) {
		sum += arr[traversal];
		if(sum > target_sum)
			sum -= arr[traversal];			
	}
	
	
	Sumer(arr, size, current_index, next_index, traversal+1, sum, target_sum);
	//Backtracking Concept
	//Going back to first call of function
	//I don't want to stack overflow
	// Go back and start everything again
	
	if(traversal != 0) return;
	sum = 0; // Make sum zero everytime
	//if(sum == target_sum) return;
	
	Sumer(arr, size, current_index, next_index+1, traversal, sum, target_sum);
	if(next_index != 0) return;
	sum = 0;
	//if(sum == target_sum) return;
	
	Sumer(arr, size, current_index+1, next_index, traversal, sum, target_sum);
	//if(sum == target_sum) return;
	sum = 0;
	//else return;
	return;
}


int main() {
	int n, target_sum;
	cin >> n;
	int arr[n];
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	cin >> target_sum;
	int sumo = 0;
	bool var = Individual_existance_sum(arr, n, target_sum);
	if(var == true) {
		cout << "YES";
	}
	else {
		Sumer(arr, n, 0, 0, 0, sumo, target_sum);	
	}
    
	return 0;
}
