#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    int size = nums.size();
    set<vector<int>> uniqueTriplets; 
    for (int i = 0; i < size; i++) {
        set<int> hash;
        for (int j = i + 1; j < size; j++) {
            int third = -(nums[i] + nums[j]);
            if(hash.find(third) != hash.end()) {
                vector<int> temp = {nums[i], nums[j], third};
                sort(temp.begin(), temp.end());
                uniqueTriplets.insert(temp);
            }
            hash.insert(nums[j]);
        }
    }

    vector<vector<int>> result(uniqueTriplets.begin(), uniqueTriplets.end());
    return result;
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    auto results = threeSum(nums);

    for (auto& triplet : results) {
        cout << "[ ";
        for (int val : triplet) {
            cout << val << " ";
        }
        cout << "] ";
    }
    return 0;
}
