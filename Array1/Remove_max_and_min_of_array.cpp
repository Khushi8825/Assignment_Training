/*You are given a 0-indexed array of distinct integers nums.

There is an element in nums that has the lowest value and an element that has the highest value. We call them the minimum and maximum respectively. Your goal is to remove both these elements from the array.

A deletion is defined as either removing an element from the front of the array or removing an element from the back of the array.

Return the minimum number of deletions it would take to remove both the minimum and maximum element from the array.

 

Example 1:

Input: nums = [2,10,7,5,4,1,8,6]
Output: 5
Explanation: 
The minimum element in the array is nums[5], which is 1.
The maximum element in the array is nums[1], which is 10.
We can remove both the minimum and maximum by removing 2 elements from the front and 3 elements from the back.
This results in 2 + 3 = 5 deletions, which is the minimum number possible.*/


#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
int minimumDeletions(vector<int>& nums) {
    if(nums.size() == 1) return 1;
    int mini = INT_MAX;
    int maxi = INT_MIN;
    int minIdx = -1;
    int maxIdx = -1;
    for(int i = 0; i<nums.size(); i++){
        if(nums[i]<mini){
        mini = nums[i];
            minIdx = i;
        }
        if(nums[i]>maxi){
            maxi = nums[i];
            maxIdx = i;
        }
    }
    int mid = nums.size()/2;
    int dlt = 0;
    if(minIdx < maxIdx){
        dlt = dlt + minIdx+1+((int)nums.size()-maxIdx);
        dlt = min(dlt,maxIdx+1);
        dlt = min(dlt,(int)nums.size()-minIdx);
    }
    else if( minIdx == maxIdx){
        dlt = minIdx+1;
        dlt = min(dlt,(int) nums.size()-minIdx);
    }
    else{
        dlt = dlt + maxIdx + 1 + ((int)nums.size() - minIdx);
        dlt = min(dlt, minIdx+1);
        dlt = min(dlt, (int)nums.size()-maxIdx);
    }
    return dlt;
}

int main(){
    vector<int> arr;
    int x;
    while(cin>>x && x != -1){
        arr.push_back(x);
    }
    int ans=minimumDeletions(arr); //function call to find minimum no. of deletion
    cout<<ans<<" ";
    return 0;
}

//TC = O(n);
//SC = O(1);