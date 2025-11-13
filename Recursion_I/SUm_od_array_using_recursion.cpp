// You are given an integer array arr[]. The task is to find the sum of it.
#include<iostream>
#include<vector>
using namespace std;
int sumArray(vector<int>& arr, int idx){
    if(idx == arr.size()) return 0;

    return arr[idx] + sumArray(arr, idx+1);
}
int main(){
    vector<int> arr;
    int x;
    while(cin >> x){
        arr.push_back(x);
    }
    int sum = sumArray(arr, 0);
    cout<<sum;
    return 0;
}