#include <iostream>
#include <vector>
using namespace std;

vector<int> merge(vector<int> &left, vector<int> &right, vector<int> &arr) {
    vector<int> result;
    int l = 0, r = 0;

    while (l < left.size() && r < right.size()) {
        if (left[l] < right[r]) {
            result.push_back(left[l++]);
        } else {
            result.push_back(right[r++]);
        }
    }

    while (l < left.size()) {
        result.push_back(left[l++]);
    }

    while (r < right.size()) {
        result.push_back(right[r++]);
    }

    return result;
}

vector<int> mergeSort(int start, int end, vector<int> &arr) {

    if(start == end) return vector<int>{arr[start]};

    int mid = (start+end)/2;

    //left Sort
    vector<int> left = mergeSort(start, mid, arr);
    //rightSort
    vector<int> right = mergeSort(mid+1, end, arr);

    // let merge the left and right
    return merge(left, right, arr);
}



int main() {
    vector<int> nums{4,1,2,6,5,7,3};
    int size = nums.size();
    int start = 0;
    int end = size-1;
    vector<int> result = mergeSort(start, end, nums);
    return 0;
    
}