/*Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas.
The guards have gone and will come back in h hours.
Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of 
bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of 
them instead and will not eat any more bananas during this hour.
Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
Return the minimum integer k such that she can eat all the bananas within h hours.

Example 1:
Input: piles = [3,6,7,11], h = 8
Output: 4
*/
#include <iostream>
#include <vector>
using namespace std;
int minEatingSpeed(vector<int> &piles, int h)
{

    int max = INT_MIN;
    for (int i = 0; i < piles.size(); i++)
    {
        if (piles[i] > max)
        {
            max = piles[i];
        }
    }
    int low = 1;
    int high = max;
    int ans = INT_MAX;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        long totalHour = 0;
        for (int i = 0; i < piles.size(); i++)
        {
            int hr;
            if (piles[i] % mid == 0)
            {
                hr = piles[i] / mid;
            }
            else
            {
                hr = piles[i] / mid + 1;
            }
            totalHour = totalHour + hr;
        }

        if (totalHour <= h)
        {
            ans = mid;
            high = mid - 1;
        }
        else if (totalHour > h)
        {
            low = mid + 1;
        }
    }
    return ans;
}
int main()
{
    vector<int> piles = {3, 4, 5, 11};
    int h = 8;

    int speed = minEatingSpeed(piles, h);
    cout << speed << endl;
    return 0;
}