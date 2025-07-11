#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<char, int> findAllDuplicates(string s)
{
    unordered_map<char, int> mp;
    for (char a : s)
        mp[a]++;

    return mp;
}

int main()
{

    string s = "geeksforgeeks";

    auto result = findAllDuplicates(s);

    for (auto &[key, val] : result)
    {
        cout << key << " : " << val << endl;
    }
    return 0;
}