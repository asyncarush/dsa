// Problem 70 - leetode - climbing stairs

#include<iostream>
using namespace std;

int climbStairs(int n) {
    if( n <= 2) return n;
    return climbStairs(n-1) + climbStairs(n-2);
};


int dp(vector<int>& memo, int n) {
    if(n <= 2) return n;
    if (memo[n] == -1) {
        memo[n] = dp(memo, n-1) + dp(memo, n-2); 
        return memo[n];
    }
    return memo[n];
}

int optimizedClimbStairs(int n) {
    vector<int> memo(n+1, -1);
    return dp(memo, n);
}

int storageOptimizedClimbStairs(int n) {
    int one = 1, two = 1;
    for(int i=0; i < n-1; i++) {
        int temp = one;
        one = one + two;
        two = temp;
    }
    return one;
}


int main() {
    cout << storageOptimizedClimbStairs(3);
    return 0;
}