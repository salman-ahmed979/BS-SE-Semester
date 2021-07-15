#include<iostream>
using namespace std;

void SumOfSubset(int arr[], int current_index, int next_index, int traversal, int sum, int size, int target_sum, bool var, string str) {
	//Checking corner case for size = 1
	if(size==1 && arr[0] == target_sum) {
		cout << "YES";
	//	return;
	}
	//Checking corner case for size = 2
	if(size==2 && (arr[1] == target_sum || arr[0] == target_sum || arr[0]+arr[1] == target_sum)) {
		cout << "YES"; //return;
	}	
	//else cout << "NO"; 
	//If both are not available, then:-
	//If sum is equal to target sum
	if(sum == target_sum) {
		cout << "YES";
		var = true;
		return;
	}
	if(var == true) return;	
	//else cout << "NO";
	//If current_index is traversed completely and increase end of array
	if(current_index > size-1 && sum != target_sum) {
		cout << "NO";
		return;
	}		
	//else cout << "NO";
	
	if(traversal > size-1) return;
	if(next_index > size-1) return;
	//If sum is zero, then it must have current & next value sum
	if(sum == 0) {
		if(current_index!=next_index)
			sum = arr[current_index] + arr[next_index];
	}
	if(traversal != current_index && traversal != next_index && sum != 0 && sum != target_sum && var != true) {
		sum += arr[traversal];
		if(sum > target_sum)
			sum -= arr[traversal];			
	}
	if(var != true) {
	SumOfSubset(arr, current_index, next_index, traversal+1, sum, size, target_sum, var, str);
	
	if(traversal != 0) return;
	if(sum == target_sum) return;
	else
		sum = 0;
		
	SumOfSubset(arr, current_index, next_index+1, traversal, sum, size, target_sum, var, str);
	if(next_index != 0) return;
	
	if(sum == target_sum) return;
	
	else
		sum = 0;
	next_index = 0; traversal = 0;
	
	SumOfSubset(arr, current_index+1, next_index, traversal, sum, size, target_sum, var, str);
	if(sum == target_sum) return;
	if(current_index == 0) cout << str;
	return;
	}
	else return;
}

static int var = false; static string str;
int main() {
	int n;
	cin >> n;
	int arr[n];
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	int sumo = 0;// bool var = false;
    SumOfSubset(arr, 0, 0, 0, sumo, n, 10, var, str);
	return 0;
}
