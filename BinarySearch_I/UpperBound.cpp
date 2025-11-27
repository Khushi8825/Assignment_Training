/*Given a sorted array arr[] and a number target, the task is to find the upper bound of the target in this
 given array.
The upper bound of a number is defined as the smallest index in the sorted array where the element is greater
 than the given number.

Note: If all the elements in the given array are smaller than or equal to the target, the upper bound will be 
the length of the array.

Examples :

Input: arr[] = [2, 3, 7, 10, 11, 11, 25], target = 9
Output: 3
Explanation: 3 is the smallest index in arr[], at which element (arr[3] = 10) is larger than 9.
*/
// TC = O(log n);
#include <iostream>
#include <vector>
using namespace std;
int upperBound(vector<int> &arr, int target)
{
    int i = 0;
    int j = arr.size() - 1;
    int ans = arr.size();

    while (i <= j)
    {
        int m = i + (j - i) / 2;
        if (arr[m] > target)
        {
            ans = m;
            j = m - 1;
        }
        else
        {
            i = m + 1;
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = {1, 2, 5, 10, 11, 11, 25};
    int trg = 9;
    int idx = upperBound(arr, trg);
    cout << trg;
    return 0;
}