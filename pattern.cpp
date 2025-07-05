#include <iostream>
using namespace std;

void printSquare(int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << "*";
        }
        cout << endl;
    }

}

void printRightAngle(int n) {
    for(int i=1; i<=n; i++) {
        for(int j=0; j<i;j++) {
            cout << "*";
        }
        cout << endl;
    }
}

void printRightAngleWithNumbers(int n) {
    int count = 1;
    for(int i=1; i<=n; i++) {
        for(int j=0; j<i; j++) {
            cout << count;
        }
        count++;
        cout << endl;
    }
}

void printRightAngleWithIncrementalNums(int n) {
    for(int i=1; i<=n; i++) {
        int count = 1;
        for(int j=0; j<i; j++) {
            cout << count++;
        }
        cout << endl;
    }
}

void printReverseRightAngle(int n) {
    for(int i=n; i-->0; i--) {
        for( int j=i; j>0; j--) {
            cout << "*";
        }
        cout << endl;
    }
}
void printReverseRightAngleWithIncrementalNums(int n) {
    for(int i=n; i>0; i--) {
        int count = 1;
        for(int j=i; j>0; j--) {
            cout << count++;
        }
        cout << endl;
    }
}




int main() {
}