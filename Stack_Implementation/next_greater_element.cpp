/*The next greater element of some element x in an array is the first greater element
that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, 
where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] 
and determine the next greater element of nums2[j] in nums2. If there is no next 
greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater 
element as described above.*/
#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;

#define STACK_MAX 1000
int stackArr[STACK_MAX];
int topIndex = -1;

bool isStackEmpty() { return topIndex == -1; }
bool isStackFull() { return topIndex == STACK_MAX - 1; }

void pushInt(int val) {
    if (!isStackFull()) stackArr[++topIndex] = val;
}

int popInt() {
    if (!isStackEmpty()) return stackArr[topIndex--];
    return -1;
}

int topInt() {
    if (!isStackEmpty()) return stackArr[topIndex];
    return -1;
}

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    unordered_map<int,int> nextGreater;

    // RESET STACK before using
    topIndex = -1;
    pushInt(-1);

    for(int i = nums2.size() - 1; i >= 0; i--) {

        while(topInt() != -1 && topInt() <= nums2[i]) {
            popInt();
        }

        nextGreater[nums2[i]] = topInt();
        pushInt(nums2[i]);
    }

    vector<int> ans;
    for(int num : nums1) {
        ans.push_back(nextGreater[num]);
    }

    return ans;
}

int main()
{
    int n1, n2;
    cin >> n1;

    vector<int> nums1(n1);
    for(int i = 0; i < n1; i++) cin >> nums1[i];

    cin >> n2;

    vector<int> nums2(n2);
    for(int i = 0; i < n2; i++) cin >> nums2[i];

    vector<int> ans = nextGreaterElement(nums1, nums2);

    for(int x : ans) cout << x << " ";
    cout << endl;
}
