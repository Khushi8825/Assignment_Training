/*Given a m x n binary matrix mat, find the 0-indexed position of the row that 
contains the maximum count of ones, and the number of ones in that row.

In case there are multiple rows that have the maximum count of ones, the row 
with the smallest row number should be selected.

Return an array containing the index of the row, and the number of ones in it.*/
#include<iostream>
#include<vector>
#include<limits>
#include<algorithm>
using namespace std;
int main(){
    int m;
    int n;
    cin >> m >> n;
    int arr[101][101]; 
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            cin >> arr[i][j];
        }
        cout<<endl;
    }
    int maxi = 0;
    int idx= -1;
    vector<int> nums;
    for(int i = 0; i<m; i++){
        int count = 0;
        vector<int> a;
        for(int j = 0; j<n; j++){
            a.push_back(arr[i][j]);
            if(arr[i][j] == 1){
                count++;
            }

        }
        if(count > maxi){
            maxi = count;
            idx = i;
            nums = a;
        }
    }
    for(int i = 0; i<nums.size(); i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl<<idx;
}