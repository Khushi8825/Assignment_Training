// Problem Statement:
// Given an m x n matrix, return all elements of the matrix in spiral order.
#include<iostream>
using namespace std;
void spiralTraversal(int arr[][11], int m, int n){
    int element = m*n;
    int count = 0;
    int rs = 0;
    int re = m-1;
    int cs = 0;
    int ce = n-1;
    while(count<element){
        for(int i = cs; i<=ce;i++){
            cout<<arr[rs][i]<<" ";
            count++;
        }
       
        rs++;
        for(int i = rs; i<= re; i++){
            cout<<arr[i][ce]<<" ";
            count++;
        }
      
        ce--;
        for(int i = ce;i>=cs;i--){
            cout<<arr[re][i]<<" ";
            count++;
        }
      
        re--;
        for(int i =re; i>=rs; i--){
            cout<<arr[i][cs]<<" ";
            count++; 
        }
     
        cs++;
    }
    return;
}
int main(){
    int m;
    int n;
    cin >> m >> n;
    int arr[11][11]; 
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            cin >> arr[i][j];
        }
        cout<<endl;
    }
    spiralTraversal(arr, m ,n);
    return 0;
}