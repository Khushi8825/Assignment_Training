/*Given an integer array nums, find a subarray that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

Note that the product of an array with a single element is the value of that element.*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int maximumSubarrayProduct(vector<int> nums)
{
    if (nums.size() == 1)
        return nums[0];
    int maxi = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        int product = nums[i];
        if (product > maxi)
        {
            maxi = product;
        }
        for (int j = i + 1; j < nums.size(); j++)
        {
            product *= nums[j];
            if (product > maxi)
            {
                maxi = product;
            }
        }
    }
    return maxi;
}
int main()
{
    vector<int> nums;
    int x;
    while (cin >> x)
    {
        nums.push_back(x);
    }
    int sum = maximumSubarrayProduct(nums);
    cout << sum;
    return 0;
}