#include <iostream>
#include <vector>
using namespace std;

int longestSubarray(vector<int>& arr) {
    int sum = 0;
    for(int i=0; i<arr.size(); i++) {
        int currentSum = 0;
        for(int j=i+1; j<arr.size(); j++) {
        
        }
    }
    return sum;
}x

int main() {
    vector<int> nums = {-1};
    auto result = longestSubarray(nums);
    cout << "Ans : " << result;
    return 0;  
}