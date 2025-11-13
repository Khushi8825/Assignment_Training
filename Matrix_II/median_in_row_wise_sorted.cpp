/*Given a row-wise sorted matrix mat[][] of size n*m, 
where the number of rows and columns is always odd. 
Return the median of the matrix.*/
#include<iostream>
using namespace std;
void sort(int arr[10000], int s){
    for(int i = 0; i<s-1; i++){
        for(int j = i+1; j<s; j++){
            if(arr[i]>arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return;
}
int median(int arr[][100], int m, int n){
    int s = m*n;
    int nums[10000];
    int k=0;
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            nums[k] = arr[i][j];
            k++;
        }
    }
    sort(nums, s);
    for(int i =0; i<s; i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    int i =0;
    int j = s-1;
    int mid = i + (j-i)/2;
    cout<<nums[mid]<<endl;
    return nums[mid];
}
int main(){
    int m;
    int n;
    cin>>m>>n;
    int arr[100][100];
    for(int i = 0;i <m; i++){
        for(int j = 0; j<n; j++){
            cin>>arr[i][j];
        }
    } 
    int ans = median(arr, m, n);  
    cout<<ans;
    return 0;
}