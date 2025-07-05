#include<iostream>
#include<vector>
using namespace std;    

void findAllCombination(
    int currIndex, 
    vector<int> nums, 
    vector<int> &ds, 
    int target, 
    vector<vector<int>> &result
) {

    if( currIndex == nums.size()) {
        if( target == 0) result.push_back(ds);
        return;
    }

    if(nums[currIndex] <= target) {
        ds.push_back(nums[currIndex]);
        findAllCombination(currIndex, nums, ds, target-nums[currIndex], result);
        ds.pop_back();
    }
    
    findAllCombination(currIndex+1, nums, ds, target, result);
}

vector<vector<int>> combinationSum(vector<int> &nums, int target){
    vector<vector<int>> result;
    vector<int> ds;
    findAllCombination(0, nums, ds, target, result);
    return result;

}

int main() {

    vector<int> test{2,3,6,7};

    auto results = combinationSum(test, 7);

    for(auto arr: results) {
        cout << "[";
        for(int i : arr) {
            cout << i << ",";
        }
        cout << "]" << endl;
    }

    return 0;
}

