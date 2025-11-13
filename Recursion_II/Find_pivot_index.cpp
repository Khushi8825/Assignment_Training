/*Given an array of integers nums, calculate the pivot index of this array.

The pivot index is the index where the sum of all the numbers strictly to 
the left of the index is equal to the sum of all the numbers strictly to the index's right.

If the index is on the left edge of the array, then the left sum is 0 
because there are no elements to the left. This also applies to the right edge of the array.

Return the leftmost pivot index. If no such index exists, return -1.*/
#include<iostream>
#include<vector>
using namespace std;
int helper(vector<int>& arr, int sum, int LIdx){
    if(LIdx == arr.size()) return -1;

    if((sum - arr[LIdx]) % 2 == 0 ) return LIdx;
    else{
        return helper(arr, sum, LIdx+1);
    }
}
int pivot_idx(vector<int>& arr){
    int sum  = 0;
    for(int i = 0; i<arr.size(); i++){
        sum += arr[i];
    }
    return helper(arr, sum, 0);
}
int main(){
    vector<int> arr;
    int x;
    while(cin >> x){
        arr.push_back(x);
    }
    int ans = pivot_idx(arr);
    cout<<ans;
}