/*Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times.
 You may assume that the majority element always exists in the array.*/
#include <iostream>
#include <vector>
#include <climits>
#include<hash_map>
#include<unordered_map>
#include<algorithm>

using namespace std;
int majorityElement(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int size = nums.size() / 2;
    unordered_map<int, int> hash;
    int ans;
    for (int i = 0; i < nums.size(); i++)
    {
        hash[nums[i]]++;
        if (hash[nums[i]] > size)
        {
            ans = nums[i];
            break;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums;
    int x;
    while (cin >> x)
    {
        nums.push_back(x);
    }
    int sum = majorityElement(nums);
    cout << sum;
    return 0;
}