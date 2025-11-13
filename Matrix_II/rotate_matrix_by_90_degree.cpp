/*You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. 
DO NOT allocate another 2D matrix and do the rotation.*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        for(int i = 0; i<row; i++){
            for(int j = i+1; j<col; j++){
               swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i = 0; i<row; i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
int main(){
    int m;
    int n;
    cin >> m >> n;
    // int arr[100][100];
    vector<vector<int>> arr(m, vector<int>(n));
    // vector<int> nums= arr;
    for(int i = 0;i <m; i++){
        for(int j = 0; j<n; j++){
            cin>>arr[i][j];
        }
    }
    rotate(arr);
    for(int i = 0;i <m; i++){
        for(int j = 0; j<n; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}