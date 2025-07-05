#include <iostream>
using namespace std;

string convert2Binary(int n) {
    string result = "";
    while (n != 1) {
        if(n%2 == 1) result += '1';
        else result += '0';
        n /= 2;
    }
    result += '1';
    reverse(result.begin(), result.end());
    return result;
}

int convert2Decimal(const string& s) {
    // 11001
    int result = 0;
    int size = s.size();

    vector<int> power(size, 1);
    for(int i=1; i<size; i++) {
        power[i] = (power[i-1]*2); 
    }

    for(int i = 0; i<size; i++) {
        if (s[i] == '1') {
            result += power[size-1-i];
        }
    }
    return result;
};
 
int main() {
    // cout << convert2Binary(12);
    cout << convert2Decimal("101");
    return 0;
}
