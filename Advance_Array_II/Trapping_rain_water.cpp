/*Given n non-negative integers representing an elevation map where the width of each bar is 1,
compute how much water it can trap after raining.

Example 1
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
find leftmax and rightmax of a point and then calculated the water trapped in that space;

TC= O(3n)   SC = O(2n)
*/
#include <iostream>
#include <vector>
using namespace std;
int trap(vector<int> &height)
{
    int n = height.size();
    vector<int> leftprefix;
    leftprefix.push_back(height[0]);
    for (int i = 1; i < height.size(); i++)
    {
        if (leftprefix[i - 1] < height[i])
        {
            leftprefix.push_back(height[i]);
        }
        else
        {
            leftprefix.push_back(leftprefix[i - 1]);
        }
    }
    vector<int> rprefix(n);
    rprefix[n - 1] = height[n - 1];
    for (int i = n - 1 - 1; i >= 0; i--)
    {
        if (rprefix[i + 1] < height[i])
        {
            rprefix[i] = height[i];
        }
        else
        {
            rprefix[i] = rprefix[i + 1];
        }
    }
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        int leftmax = leftprefix[i];
        int rightmax = rprefix[i];
        if (height[i] < leftmax && height[i] < rightmax)
        {
            total += min(leftmax, rightmax) - height[i];
        }
    }
    return total;
}
int main()
{
    int n;
    cin >> n;
    vector<int> height;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        height[i] = x;
    }

    int trapWater = trap(height);
    cout << trapWater << endl;
    return 0;
}