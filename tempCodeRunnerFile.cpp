#include<iostream>
#include<vector>
using namespace std;

void sort012(vector<int> &arr) {
  int low = -1;
  int mid = 0;
  int high = arr.size()-1;

  while(mid < high) {
    // swap with low if mid = 0
    if(arr[mid] == 0) {
      low++;
      swap(arr[low], arr[mid]);
      mid++;
    }

    if(arr[mid] == 1) mid++;

    if(arr[mid] == 2) {
      while(arr[high] != 2) high--;
      swap(arr[mid], arr[high]);
      mid++;
      high--;
    }
  
}

int main() {
  vector<int> test {0,1,2,0,1,2};
  sort012(test);
  fort(int i : test) {
    cout << i << ", ";
  }

  return 0;
}