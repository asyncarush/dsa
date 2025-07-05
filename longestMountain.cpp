#include <iostream>
#include <vector>
using namespace std;

int longestMountain(vector<int>& arr) {
    int n = arr.size();
    int longest = 0;

    for (int i = 1; i < n - 1; i++) {
        // Check if i is a peak
        if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) {
            int left = i - 1;
            int right = i + 1;

            // Expand to the left
            while (left > 0 && arr[left - 1] < arr[left]) {
                left--;
            }

            // Expand to the right
            while (right < n - 1 && arr[right] > arr[right + 1]) {
                right++;
            }

            longest = max(longest, right - left + 1);
        }
    }

    return longest;
}
int main() {
    vector<int> arr {2, 1, 4, 7, 3, 2, 5};
    int result = longestMountain(arr);
    cout << result;
    return 0;
}