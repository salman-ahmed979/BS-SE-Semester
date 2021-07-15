#include<iostream>
#include<queue>
using namespace std;

//Swap function
void swap(int &a, int &b) 
{
    int t = a;
    a = b;
    b = t;
}

//Sort on the basis of the radix i.e. 10
void Radix_Sort(int arr[], int n) {
    int digits = 10, radix = 0, factor = 1;
    queue<int>q1[radix];

    for(int d=0; d < digits; d++, factor *= radix)
    {
        for(int j=0; j < n; j++)
            q1[ (arr[j] / factor) % radix].push(arr[j]);
        
        for(int j=0, k=0; j < radix; j++) {
            arr[k++] = q1[j].front();
            q1[j].pop();
        }
    }
}

//Sort on basis of largest array position
void Count_Sort(int arr[], int n) {

    //find max
    int largest = arr[0];
    for(int i=1; i < n; i++)
        if(largest < arr[i])
            largest = arr[i];
    
    int count[largest+1], temp[n];
    //initialize all elements to zero
    for(int i=0; i <= largest; i++)
        count[i] = 0;
    
    //initialize the values as per array index
    //with their increment
    for(int i=0; i < n; i++)
        count[ arr[i] ]++;
    
    //sum of previous elements value
    for(int i=1; i <= largest; i++)
        count[i] = count[i-1] + count[i];

    //add the values to specific indexes
    for(int i=0; i < n; i++) {
        temp[ count [arr[i]] -1 ] = arr[i];
        count[arr[i]]--;
    }
    for(int i=0; i < n; i++)
        arr[i] = temp[i];
}

int main(void) {
    int arr[5] = {54,4231,23133,2123,3221};
    Count_Sort(arr,5);
    for(int i=0; i < 5; i++)
            cout << " " << arr[i] << " ";
    return 0;
}