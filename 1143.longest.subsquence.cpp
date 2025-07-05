#include<iostream>
#include <vector>
using namespace std;

int getMeLongestSub(string &s1, string &s2) {
    int count = 0;
    unordered_map<char, int> freq1;
    unordered_map<char, int> freq2;
    
    for(char c : s1) freq1[c]++;
    for(char c : s2) freq2[c]++;

    for(auto& [letter, count] : freq2) {
        if(freq1.find(letter) != freq1.end()) {
            count += min(freq1[letter], count);
        }
    }
    return count;
}
 int longestCommonSubsequence(string text1, string text2) {
     if(text1.length() == 0 || text2.length() == 0) return 0;
     
     if( text1.length() > text2.length()) {
        return getMeLongestSub(text1, text2);
     }  else {
        return getMeLongestSub(text2, text1);   
     } 
}

int main() {
    cout << longestCommonSubsequence("abcde", "ace");
    return 0;
}