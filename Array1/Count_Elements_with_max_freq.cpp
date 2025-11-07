/*You are given an array nums consisting of positive integers.

Return the total frequencies of elements in nums such that those elements all have the maximum frequency.

The frequency of an element is the number of occurrences of that element in the array.



Example 1:

Input: nums = [1,2,2,3,1,4]
Output: 4
Explanation: The elements 1 and 2 have a frequency of 2 which is the maximum frequency in the array.
So the number of elements in the array with maximum frequency is 4.*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
int maxFrequencyElements(vector<int> &nums)
{
    unordered_map<int, int> freq;
    int maxi = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        freq[nums[i]]++;
        maxi = max(maxi, freq[nums[i]]);
    }

    int cnt = 0;
    for (auto c : freq)
    {
        if (c.second == maxi)
        {
            cnt += maxi;
        }
    }
    return cnt;
}
int main()
{
    vector<int> arr;
    int x;
    while (cin >> x && x != -1)
    {
        arr.push_back(x);
    }
    int ans = maxFrequencyElements(arr);
    cout << ans;
    return 0;
}