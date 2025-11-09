/*Given two integer arrays nums1 and nums2, return an array of their intersection.
 Each element in the result must be unique and you may return the result in any order.*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;
vector<int> IntersectionArray(vector<int>& arr1, vector<int>& arr2){
    int n = arr1.size();
    int m = arr2.size();
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());
    vector<int> ans;
    int i = 0;
    int j = 0;
    while(i < n && j < m){
        if(arr1[i]==arr2[j]){
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
        else if(arr1[i]<arr2[j]) i++;
        else j++;
    }

    for(int i = 1; i<ans.size(); i++){
        if(ans[i] == ans[i-1]){
            ans.erase(ans.begin()+i);
            i--;
        }
    }
    return ans;
}

vector<int> IntersectionArray2(vector<int>& arr1, vector<int>& arr2){
    unordered_set<int> s1(arr1.begin(), arr1.end());
    unordered_set<int> result;

    for(int x : arr2){
        if(s1.count(x)){
            result.insert(x);
        }
    }

    // Convert set to vector
    return vector<int>(result.begin(), result.end());
}
int main(){
    vector<int> arr1;
    vector<int> arr2;
    int x;
    while(cin >> x && x != -1){
        arr1.push_back(x);
    }
    int y;
    while(cin >> y && y != -1){
        arr2.push_back(y);
    }
    vector<int> ans = IntersectionArray(arr1, arr2);
    for(int i = 0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return  0;
}

//TC = O(nlogn + mlogm);
//