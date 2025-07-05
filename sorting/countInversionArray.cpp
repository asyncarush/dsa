#include <iostream>
#include <vector>
using namespace std;

int merge(int start, int mid, int end, vector<int> &arr) {
    int count = 0;
    vector<int> result;
    int l = start, r = mid+1;

    while (l <= mid && r <= end) {
        if (arr[l] <= arr[r]) {
            result.push_back(arr[l++]);
        } else {
            count += (mid-l)+1;
            result.push_back(arr[r++]);
        }
    }

    while (l <= mid) result.push_back(arr[l++]);
    while (r <= end) result.push_back(arr[r++]);

    for(int i=start; i<=end; i++) {
        arr[i] = result[i-start];
    }
    return count;
}

int mergeSort(int start, int end, vector<int> &arr) {
    int count = 0;
    if(start >= end) return count;
    int mid = (start+end)/2;
    
    count += mergeSort(start, mid, arr);
    count += mergeSort(mid+1, end, arr);
    count += merge(start, mid, end, arr);
    
    return count;
}

int main() {
    vector<int> nums{10,10,10};
    int size = nums.size();
    int count = mergeSort(0, size-1, nums);

    cout << count;

    return 0;
}