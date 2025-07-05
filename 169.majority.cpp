#include <iostream>
using namespace std;

int majorityElementBF(vector<int>& nums) {
        if(nums.size() == 1) return nums[0]; 
        int maxi = INT_MIN;
        sort(nums.begin(), nums.end());
        int maxElement = -1, count = 0;
        
        for(int i=1; i<nums.size(); i++) {
            if(nums[i-1] != nums[i]) count = 0;
            count++;
            if(maxi < count) maxElement = nums[i-1];
            maxi = max(maxi, count);
        }

        return maxElement;
    }

int majorityElementOptimal(vector<int>& nums) {
    int count = 0;
    int candidate = -1;
    for(int n: nums) {
        if( count == 0) candidate = n;
        count += (n == candidate) ? 1 : -1;
    }
    return candidate;
}

int a