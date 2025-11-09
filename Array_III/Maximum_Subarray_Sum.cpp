/*Given an integer array nums, find the subarray with the largest sum, and return its sum.*/
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int maximumSubarraySum(vector<int> nums){
    int n = nums.size();
    int max_so_far = INT_MIN;
    int max_ending_here = 0;
    for(int i = 0 ;i <nums.size(); i++){
        max_ending_here += nums[i];
        if(max_ending_here<nums[i]){
            max_ending_here = nums[i];
        }
        if(max_so_far<max_ending_here){
            max_so_far = max_ending_here;
        }
    }
    return max_so_far;
}
int main(){
    vector<int> nums;
    int x;
    while(cin >> x){
        nums.push_back(x);
    }
    int sum = maximumSubarraySum(nums);
    cout << sum ;
    return 0;
}