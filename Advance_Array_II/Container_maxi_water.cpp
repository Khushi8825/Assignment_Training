/*
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

Example 1
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
*/
#include<iostream>
#include<vector>
using namespace std;
int quantity(vector<int>& height){
    int i = 0;
    int j = height.size()-1;
    int maxi = 0;
    while(i < j){
        int l = height[i]<height[j]?height[i]:height[j];
        int b = j-i;
        int area = l*b;
        if(maxi<area){
            maxi = area;
        }
        if(height[i]<height[j]){
            i++;
        }
        else{
            j--;
        }
    }
    return maxi;
}
int main(){
    int n;
    cout<<"enter the size: ";
    cin>>n;
    vector<int> height;
    for(int i = 0; i<n; i++){
        int x;
        cin>>x;
        height.push_back(x);
    }
    int ans = quantity(height);
    cout<<ans;
    return 0;
}

/*
Approach: Use two pointers: one at the start (i = 0) and one at the end (j = n-1).

Calculate area using
min(height[i], height[j]) * (j - i).

Update the maximum area found so far.

Move the pointer with the smaller height inward because a larger height may create a bigger area.

Repeat until both pointers meet.

TC = O(n)*/