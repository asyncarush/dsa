// 977. Squares of a Sorted Array
// Input: nums = [-4,-1,0,3,10]
// Output: [0,1,9,16,100]
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> squareOfSortedArray(vector<int> nums){
    sort(nums.begin(), nums.end());
    for(int i=0; i<nums.size(); i++){
        nums[i] = nums[i]*nums[i];
    }
    return nums;
}

int main() {



    return 0;
}