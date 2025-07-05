#include<iostream>
#include<unordered_map>
using namespace std;

bool checkInclusion(string s1, string s2) {
    unordered_map<char, int> s1Freq;
    for (char s: s1) s1Freq[s] += 1;
    
    for(int i=0; i<=s2.size()-s1.size(); i++) {
        int windowSize = i+s1.size();
        int windowIndex = i;
        unordered_map<char, int> s2Freq;

        // now we have to compare the frequency
        while(windowIndex < windowSize) {
            s2Freq[s2[windowIndex]]++;
            windowIndex++;
        }
        
        if(s1Freq == s2Freq) return true;
    }

    return false;
}

int main(){
    string s1 = "ac";
    string s2 = "adnajdnakjdba";

    cout << checkInclusion(s1, s2);

    return 0;
}
