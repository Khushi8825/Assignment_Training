/*Given an integer array nums sorted in non-decreasing order, 
remove the duplicates in-place such that each unique element 
appears only once. The relative order of the elements should 
be kept the same.

Consider the number of unique elements in nums to be k​​​​​​​​​​​​​​. After 
removing duplicates, return the number of unique elements k.

The first k elements of nums should contain the unique numbers
in sorted order. The remaining elements beyond index k - 1 can 
]be ignored.*/
#include<iostream>
#include<vector>
using namespace std;
    vector<int> helper(vector<int>& nums){
        int size = nums.size();
        vector<int> a;
        int i = 0;
        while(i<size){
            if(i+1 >= size || nums[i] != nums[i+1]){
                a.push_back(nums[i]);
                i++;
            }
            else{
                i++;
            }
        }
        int unique_size = a.size();
        // return unique_size;
        return a;
    }
    int removeDuplicates(vector<int>& nums) {
        nums = helper(nums);
        int count = 0;
        for(auto i : nums){
            count++;
        }
        return count;
    }
int main(){
    vector<int> arr;
    int x;
    while(cin >> x){
        arr.push_back(x);
    }
    int ans = removeDuplicates(arr);
    cout<<ans;
    // cout<<arr.size();
    return 0;

}