#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

bool checkSub1(const string& s1, const string& s2) {
    for (int i = 0; i <= s2.size() - s1.size(); i++)
        if (s2.substr(i, s1.size()) == s1) return true;
    return false;
}

bool checkSub2(const string& s1, const string& s2) {
    return s2.find(s1) != string::npos;
}

int main() {
    string s1 = "needle";
    string s2(1e6, 'a');  // 1 million 'a's
    s2 += "needle";

    auto start = high_resolution_clock::now();
    cout << checkSub1(s1, s2) << endl;
    auto end = high_resolution_clock::now();
    cout << "substr + ==: " << duration_cast<microseconds>(end - start).count() << " ms\n";

    start = high_resolution_clock::now();
    cout << checkSub2(s1, s2) << endl;
    end = high_resolution_clock::now();
    cout << "find(): " << duration_cast<milliseconds>(end - start).count() << " ms\n";
}
