#include <map>
#include<iostream>

using namespace std;

bool IsSumSubset(int arr[], int size, int find_me) {
    int sum = 0; bool var = false;
    if(size==1 && arr[size-1] == find_me)
        var = true;
    else {
    for(int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            if(i!=j)
                sum = arr[i] + arr[j];
            for (int k=0; k<size; k++)
            {
                if (k!=i && k!=j) {
                    sum += arr[k];
                    if (sum==find_me)
                    {
                        var = true;
                        break;
                    }
                    else {
                    sum -= arr[k];
                    }                         
                }
            }
            sum = 0;
        }
    }
    }
    if (var == true)
        return true;
    else  {
    return false;
    }
} 

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    int arr[n], find;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    cin >> find;
    bool var = IsSumSubset(arr, n, find);
    if (var==true) cout << "YES";
    else {
    cout << "NO";
    }
    return 0;
}
