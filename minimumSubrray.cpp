// problem num 209 Minimum Sub array
#include <iostream>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int ans = INT_MAX;
    int total = 0;
    for(int i=0; i<nums.size(); i++) {
        for(int j=i; j<nums.size(); j++) {
            total += nums[j];
            if(total >= target) {
                ans = min(ans, (j-i)+1);
                break;
            }
        }
        total = 0;
    }
    return (ans != INT_MAX) ? ans : 0;
}


int minSumArrayOptimized(int target, vector<int> &nums){ 
    int left=0, right=0, total=0;
    int ans = INT_MAX;
    while(left <= right && right < nums.size()) {
        total+=nums[right];
        while(total >= target) {
            ans = min(ans, (right-left)+1);
            total -= nums[left];
            left++;
        }
        right++;
    }
    return ans != INT_MAX ? ans : 0;
}

int main() {
    vector<int> nums = {2,3,1,2,4,3};
    int result = minSumArrayOptimized(7, nums);
    cout << result;
    return 0;
}