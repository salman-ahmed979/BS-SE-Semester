#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right, int count) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
  int m = (left+right)/2;
  if (a[left] == a[m] && left!=m)
  	count+=1;
  if (count > m)
  {
  	return 1;
  }
  int b = get_majority_element(a,left,m,count);
     
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size() != -1, 1)) << "\n";
}
