/*Search an element in given 2D array return true id found target else return false*/
#include<iostream>
using namespace std;
bool search(int arr[][101], int m, int n, int target){
    if(m == 0 && n == 0) return 0;
    int s = 0;
    int e = m*n - 1;
    int mid;
    while(s <= e){
        mid = s + (e - s)/2;
        int rowIdx = mid/n;
        int colIdx = mid%m;

        if(arr[rowIdx][colIdx] == target){
            return true;
        }
        else if( arr[rowIdx][colIdx] > target){
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    } 
    return false;
}

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
    int target;
    cin>>target;
    cout<<search(arr, m, n, target);
    return 0;
}