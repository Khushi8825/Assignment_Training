/*Problem Statement: Find all the repeating elements present in an array.*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int> repeatingElement(vector<int> arr){
    unordered_map<int,int> freq;
    for(int i = 0; i<arr.size(); i++){
        freq[arr[i]]++;
    }
    vector<int> ans;
    for(auto i : freq){
        if(i.second > 1){
            ans.push_back(i.first);
        }
    }
    return ans;
}
int main(){
    vector<int> arr;
    int x;
    while(cin>>x){
        arr.push_back(x);
    }
    vector<int> ans;
    ans = repeatingElement(arr);
    for(int i = 0;i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
//TC - O(n);
//SC -O(n);