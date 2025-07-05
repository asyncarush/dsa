#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
void findPermutations(vector<int>& s, vector<int>& arr, vector<int> &mp, vector<vector<int>>& ans) {
    if(s.size() == arr.size()) {
        ans.push_back(s);
        return;
    }
    
    for(int i=0; i<arr.size(); i++) {
        if(mp[i] == 1) continue;
        
        s.push_back(arr[i]);
        mp[i] = 1;

        findPermutations(s, arr, mp, ans);

        s.pop_back();
        mp[i] = 0;
    }
}

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<int> mp(nums.size(), 0);
        findPermutations(ds,  nums, mp, ans);
        return ans;

    }
};

int main() {
    vector<int> test = {1,2,3};
    auto solve = new Solution();
    auto result = solve->permute(test);
    for(auto a : result) {
        cout << "[";
        for(int i : a) {
            cout << i << ",";
        }
        cout << "],";
    }

}   