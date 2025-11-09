//Problem statement
/*Find the elements is present at which index of the array. if not present return -1.*/
#include<iostream>
using namespace std;
int LinearSearch(int* arr, int& n, int k){
    for(int i = 0; i<n; i++){
        if(arr[i] == k){
            return i;
        }
    }
    return -1;
    //TC = O(n);
    //SC = O(1)
}
int binarySearch(int* arr, int n, int k){
    //only use when array is sorted asc.
    int i = 0;
    int j = n-1;
    while(i<=j){
        int mid = (i + j)/2;
        if(arr[mid] == k){
            return mid;
        }
        else if(arr[mid] < k){
            i = mid+1;
        }
        else{
            j = mid-1;
        }
    } 
    return -1;
    //TC = O(log n);
    //SC = O(1);
}
int main(){
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i = 0 ;i<n; i++){
        cin>>arr[i];
    }
    int k;
    cin >> k;
    int ans = binarySearch(arr, n, k);
    cout<<ans; //print 0-based index at whic element is present if not present return -1 
    return 0;
}