#include <iostream>
#include <unordered_set>
#define vi vector<int>
using namespace std;

vi unionOfArray(vi ar1, vi ar2)
{
    unordered_set<int> result;
    for (int i : ar1)
        result.insert(i);
    for (int i : ar1)
        result.insert(i);
    return vi(result.begin(), result.end());
};

int main()
{
    vi a = {1, 2, 3, 2, 1}, b = {3, 2, 2, 3, 3, 2};
    auto result = unionOfArray(a, b);
    return 0;
}

/*
    a = 1 2 3
    b = 3 2
    result = 3 2


    a = 1 2 3
    b = 4 5 6

*/