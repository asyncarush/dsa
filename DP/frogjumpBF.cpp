#include <iostream>
using namespace std;

int f(int n, vector<int> &heights) {
    if(n == 0) return 0;

    int left = f(n-1, heights) + abs(heights[n] - heights[n-1]);

    int right = INT_MAX;

    if(n > 1) {
        right = f(n-2, heights) + abs(heights[n] - heights[n-2]);
    }

    return min(left, right);
}

int frogJump(int n, vector<int> &heights) {
    return f(n-1, heights);
}

int main() {


}