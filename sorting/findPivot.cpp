#include <iostream>
using namespace std;


int findPivot(vector<int> &nums) {
    int size = nums.size();
    vector<int> prefix (size+1, 0);

    // creating prefix sum
    for(int i=0; i < size; i++) {
        prefix[i+1] = prefix[i] + nums[i];
    }

    for(int i=0; i < size; i++) {
        int leftSum = prefix[i];
        int rightSum = prefix[size]-prefix[i+1];
        if(leftSum == rightSum) return i;
    }

    return -1;
}

int main() {
    vector<int> test{1,7,3,6,5,6};

    cout << findPivot(test);

    return 0;
}