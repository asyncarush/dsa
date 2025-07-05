// leetcode problem 219
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

bool containerDuplicateUsingHash(vector<int> &nums, int k) {
    unordered_map<int, int> mpp;
    for(int i=0; i<nums.size(); i++) {
        if(mpp.find(nums[i]) != mpp.end() && abs(i-mpp[nums[i]]) <= k ) return true;
        mpp[nums[i]] = i;
    }
    return false;
};

bool containDuplicateUsingSW(vector<int>& nums, int k) {
    
}

int main() {
    vector<int> test = {1,2,3,1};
    cout << containerDuplicateUsingHash(test, 3);
    return 0;
}