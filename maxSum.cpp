#include <iostream>
#include <vector>
using namespace std;

int maxSum(vector<int> arr)
{
    int maxi = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        int currentSum = 0;
        for (int j = i; j < arr.size(); j++)
        {
            currentSum += arr[j];
            maxi = max(maxi, currentSum);
        }
    }
    return maxi;
}

int maxSumOptimal(vector<int> arr)
{
    int maxi = INT_MIN;
    int currentSum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        currentSum += arr[i];
        maxi = max(currentSum, maxi);
        if (currentSum < 0)
            currentSum = 0;
    }
    return maxi;
};

int main()
{
    vector<int> test{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxSumOptimal(test);
    return 0;
}