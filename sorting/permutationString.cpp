#include<iostream>
#include<vector>
using namespace std;

void permute(string& s, const string& str, vector<int> &mp, vector<string>& ans) {

    if(s.size() == str.size()) {
        ans.push_back(s);
        return;
    }
    
    for(int i=0; i<str.size(); i++) {
        if(mp[i] == 1) continue;
        
        s += str[i];
        mp[i] = 1;

        permute(s, str, mp, ans);

        s.pop_back();
        mp[i] = 0;
    }
}


int main() {

    string str = "abc";
    vector<string> ans; 
    vector<int> mp(str.size(), 0);
    string s = "";
    permute(s, str, mp, ans);
    return 0;
}