#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

void findAllCombination(int currIndex, vector<int> &candidates, vector<int> &ds, int target, vector<vector<int>> &result) {
    if (target == 0) {
        vector<int> temp = ds;
        sort(temp.begin(), temp.end()); // sort before inserting into set later
        result.push_back(temp);
        return;
    }

    if (currIndex == candidates.size()) {
        return;
    }

    // Include the current element if it's not greater than the target
    if (candidates[currIndex] <= target) {
        ds.push_back(candidates[currIndex]);
        findAllCombination(currIndex + 1, candidates, ds, target - candidates[currIndex], result);
        ds.pop_back();
    }

    // Skip to next index **without including current**
    findAllCombination(currIndex + 1, candidates, ds, target, result);
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    vector<vector<int>> result;
    vector<int> ds;

    // Sort first so that duplicate combinations can be handled via set later
    sort(candidates.begin(), candidates.end());

    findAllCombination(0, candidates, ds, target, result);

    // Use set to remove duplicate combinations (since you allowed duplicates in recursion)
    set<vector<int>> unique_vectors(result.begin(), result.end());
    result.assign(unique_vectors.begin(), unique_vectors.end());

    return result;
}

int main() {
    vector<int> test{2, 5, 2, 1, 2}; // Input

    auto results = combinationSum2(test, 5);

    for (auto arr: results) {
        cout << "[";
        for (int i : arr) {
            cout << i << ",";
        }
        cout << "]" << endl;
    }

    return 0;
}
