#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int f(vector<int>& nums, int n) {
    if( n == 0) return nums[n];
    if( n < 0) return 0;

    int pick = f(nums, n-2) + nums[n];
    int notPick = f(nums, n-1) + 0;

    return max(pick, notPick);
}

int rob(vector<int>& nums) {
    int size = nums.size()-1;
    return f(nums, size);
}


int robTabulatedForm(vector<int> &nums) {
    int size = nums.size();
    
    int prev = nums[0];
    int prev2 = 0;

    for(int i=1; i<size; i++ ) {
        int take = nums[i];
        
        if(i > 1) 
            take+= prev2;
        int notTake = prev;
        int curr = max(take, notTake);
        
        int temp = prev;
        prev = curr;
        prev2 = temp;
    }
    return prev;
}

int main() {
    vector<int> house{2,7,9,3,1};
    
    cout << robTabulatedForm(house);

    return 0;
}