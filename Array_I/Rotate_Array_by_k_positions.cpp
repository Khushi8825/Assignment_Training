/*Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
 */
#include<iostream>
#include<vector>
using namespace std;
void rotate(vector<int>& nums, int k) {
    int n = nums.size(); 
    vector<int> temp(n);       //if we don't initialise size then we can
    for(int i=0;i<n;i++){ // not place value directly to a index & the
        temp[(i+k)%n] = nums[i];//assigning value statement will give error
    }                           //run time and we can only push back 
    for(int i=0;i<n;i++){       // elements to the vector
        nums[i]=temp[i];
    }
    return;
}
int main(){
    vector<int> arr;
    int x;
    while(cin>>x && x!=-1){
        arr.push_back(x);
    }
    int k;
    cin>>k;
    rotate(arr,k);
    for(int i = 0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    return 0;
}