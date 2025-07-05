#include <iostream>
#include <vector>
using namespace std;

void merge(int start, int mid, int end, vector<int> &arr) {
    vector<int> result;
    int l = start, r = mid+1;

    while (l <= mid && r < end) {
        if (arr[l] < arr[r]) {
            result.push_back(arr[l++]);
        } else {
            result.push_back(arr[r++]);
        }
    }

    while (l <= mid) result.push_back(arr[l++]);

    while (r < end) result.push_back(arr[r++]);

    // assign new temps to arr
    for(int i=start; i<end; i++) {
        arr[i] = result[i-start];
    }
}

void mergeSort(int start, int end, vector<int> &arr) {
    if(start >= end) return;
    int mid = (start+end)/2;
    //left Sort
    mergeSort(start, mid, arr);
    //rightSort
    mergeSort(mid+1, end, arr);
    // let merge the left and right
    merge(start, mid, end, arr);
}

int main() {
    vector<int> nums{4,1,2,6,5,7,3};
    int size = nums.size();
    mergeSort(0, size-1, nums);
    return 0;
}