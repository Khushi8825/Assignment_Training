/*
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, 
and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
Merge nums1 and nums2 into a single array sorted in non-decreasing order.
The final sorted array should not be returned by the function, but instead be 
stored inside the array nums1. To accommodate this, nums1 has a length of m + n,
where the first m elements denote the elements that should be merged, and the last
n elements are set to 0 and should be ignored. nums2 has a length of n.

Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

TC = O(n+m); 
*/
#include<iostream>
#include<vector>
using namespace std;
vector<int> mergeArray(vector<int>& arr1, vector<int>& arr2){
    int i = 0;
    int j = 0;
    vector<int> ans;
    while(i<arr1.size() && j<arr2.size()){
        if(arr1[i]<arr2[j]){
            ans.push_back(arr1[i]);
            i++;
        }
        else{
            ans.push_back(arr2[j]);
            j++;
        }
    }
    while(i<arr1.size()){
        ans.push_back(arr1[i]);
        i++;
    }
    while(j<arr1.size()){
        ans.push_back(arr1[j]);
        j++;
    }
    return ans;
}
int main(){
    vector<int> arr1;
    vector<int> arr2;
    int x;
    while(cin>>x){
        arr1.push_back(x);
    }
    int y;
    while(cin>>y){
        arr1.push_back(y);
    }
    vector<int> ans = mergeArray(arr1, arr2);
    for(int i = 0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}