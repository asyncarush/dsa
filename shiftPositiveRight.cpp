#include<iostream>
#include<vector>
using namespace std;

vector<int> shiftPositiveRight(vector<int> &arr) {	
	vector<int> result;
  	for(int i: arr) {
    if( i < 0) {
      result.push_back(i);
    }
  }
  for(int i: arr) {
    if( i >= 0 ) {
      result.push_back(i);
    }
  }
  return result;
}

void shiftPositiveRightOptimal(vector<int> &arr) {
  int start = 0, end = arr.size()-1;
  while(start<end) {
    while(start < end && arr[start] < 0) start++;
    while(start < end && arr[end] > 0) end--;
    if( start < end ) swap(arr[start], arr[end]);
  }
}

int main() {
  vector<int> test{-12, 11, -13, -5, 6, -7, 5, -3, -6}; 
  shiftPositiveRightOptimal(test);
 
  for(int i: test) {
    cout << i << ", ";
  }
  return 0;
}