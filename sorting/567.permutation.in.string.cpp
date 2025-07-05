#include<iostream>
using namespace std;

void findPermutations(string& s, string arr, vector<int>& mp,
                        vector<string>& ans) {
    if (s.size() == arr.size()) {
        ans.push_back(s);
        return;
    }

    for (int i = 0; i < arr.size(); i++) {
        if (mp[i] == 1) continue;
        s += arr[i];
        mp[i] = 1;
        findPermutations(s, arr, mp, ans);
        s.pop_back();
        mp[i] = 0;
    }
}

vector<string> permute(string str) {
    vector<string> ans;
    string ds;
    vector<int> mp(str.size(), 0);
    findPermutations(ds, str, mp, ans);
    return ans;
}

bool checkInclusion(string s1, string s2) {
    vector<string> allS1Permutation = permute(s1);
   
    for(int i=0; i<allS1Permutation.size(); i++)
        if( s2.find(allS1Permutation[i]) != std::string::npos) return true;
    
    return false;
}

int main(){
    string s1 = "ab";
    string s2 = "adnajdnakjdba";

    cout << checkInclusion(s1, s2);

    return 0;
}
