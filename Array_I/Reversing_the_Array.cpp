/*Problem statement
Given an array/list 'ARR' of integers and a position ‘M’. You have to reverse the array after that position.

Example:

We have an array ARR = {1, 2, 3, 4, 5, 6} and M = 3 , considering 0 
based indexing so the subarray {5, 6} will be reversed and our 
output array will be {1, 2, 3, 4, 6, 5}.*/

#include<iostream>
#include<vector>
using namespace std;
void reverseArray(vector<int> &arr , int m) {
    if(m+1 >= arr.size()) return;
    int i = m+1;
    int j = arr.size()-1;
    while(i<j){
        int temp = arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        i++;
        j--;
    }      	
}
int main(){
    int m; //position after which array needs to be reversed
    cin>>m;
    int x; // Enter the elements of array ... enter -1 to stop
    vector<int> arr;
    while(cin>>x && x != -1){
        arr.push_back(x);
    }
    reverseArray(arr, m); //call function to reverse the array
    for(int i = 0; i<arr.size(); i++){
        cout<<arr[i]<<" "; //print the array
    }
    return 0;
}

// TC = O(n);
// SC = O(1)