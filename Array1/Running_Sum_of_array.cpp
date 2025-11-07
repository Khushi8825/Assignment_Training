/*Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).

Return the running sum of nums.*/

#include<iostream>
#include<vector>
using namespace std;
vector<int> runningSum(vector<int>& nums) {
    vector<int> ans;
    int sum = 0;
    for(int i = 0; i<nums.size(); i++){
        sum += nums[i];
        ans.push_back(sum);
    }
    return ans;
}

int main(){
    vector<int> arr;
    int x;
    while(cin>>x && x!=-1){
        arr.push_back(x);
    }
    vector<int> ans = runningSum(arr);
    for(int i = 0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}