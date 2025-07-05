#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int size = arr.size();
    int minDiff = INT_MAX;

    vector<vector<int>> result;
    // this will find us minDiff
    for(int i=1; i<size; i++) {
        minDiff = min(minDiff, arr[i] - arr[i-1]);
    }

    // find the pairs
    for(int i=1; i<size; i++) {
        if((arr[i]-arr[i-1]) == minDiff) {
            result.push_back({arr[i-1], arr[i]});
        }
    }
    return result;
}

int main() {
    vector<int> nums = {4,2,1,3};
    vector<vector<int>> result = minimumAbsDifference(nums);

    for(auto it: result) {
        cout << "[";
        for(int i : it) {
            cout << i << ",";
        }
        cout << "]";
    }
    
    return 0;  
}