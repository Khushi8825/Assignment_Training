/*Given an array of integers nums, calculate the pivot index of this array.

The pivot index is the index where the sum of all the numbers strictly to 
the left of the index is equal to the sum of all the numbers strictly to the index's right.

If the index is on the left edge of the array, then the left sum is 0 
because there are no elements to the left. This also applies to the right 
edge of the array.

Return the leftmost pivot index. If no such index exists, return -1.*/
#include<iostream>
#include<vector>
using namespace std;
int pivotIdx(vector<int> arr){
    int sum = 0;
    for(int i = 0; i<arr.size(); i++){
        sum += arr[i];
    }
    int i = 0;
    int ans = -1;
    int leftsum = 0;
    while(i<arr.size()){
       if(leftsum == sum - arr[i] - leftsum){
            ans = i;
            break;
       }
       leftsum += arr[i];
       i++;
    }
    return ans;
}
int main(){
    vector<int> arr;
    int x;
    while(cin>>x){
        arr.push_back(x);
    }
    int ans = pivotIdx(arr);
    cout << ans;
    return 0;
}