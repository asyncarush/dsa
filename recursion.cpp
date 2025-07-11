#include<iostream>
#include<string>
using namespace std;

void printToOne(int n) { 
    if(n == 0) {
        return;
    }
    
    cout << n << " ";
    printToOne(n-1);
}

void reverseString(int pos, const string& s) {
    if (pos == s.size()) {
        return;
    }
    reverseString(pos+1, s);
    cout << s[pos];
}

void reverseArray(vector<int> &arr) {
    int middle = arr.size()/2;
    int last = arr.size()-1;

    for(int i=0; i<middle; i++) {
        swap(arr[i], arr[last-i]);
    }

}

void reverseArrayRecursion(int first, int last, vector<int> &arr){
    if( first == last || first > last) {
        return;
    }
    swap(arr[first], arr[last]);
    reverseArrayRecursion(first+1, last-1, arr);
}

void reverseArrayRecursion2(int index, vector<int> &arr){
    if( index > arr.size()-1-index) {
        return;
    }
    swap(arr[index], arr[arr.size()-1-index]);
    reverseArrayRecursion2(index+1, arr);
}

bool check(int i, const string &s) {
    if( i > s.size()/2){
        return true;
    }

    if( s[i] != s[s.size()-1-i]) {
        return false;
    }

    return check(i+1, s);
};


bool checkPallindrome(const string& s) {
    return check(0, s);
}


int getFibonacci(int n) {

}

int main() {
    return 0;
}