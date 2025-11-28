/*Given the root of a binary tree and an integer targetSum, return true if the tree has a
root-to-leaf path such that adding up all the values along the path equals targetSum.
A leaf is a node with no children.

Example
Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true
Explanation: The root-to-leaf path with the target sum is shown.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *createBinaryTree(vector<vector<int>> &descriptions)
{
    unordered_map<int, pair<TreeNode *, TreeNode *>> mp;

    for (auto &d : descriptions)
    {
        int parentVal = d[0];
        int childVal = d[1];
        int isLeft = d[2];

        if (!mp[parentVal].first)
            mp[parentVal].first = new TreeNode(parentVal);

        if (!mp[childVal].first)
            mp[childVal].first = new TreeNode(childVal);

        TreeNode *parent = mp[parentVal].first;
        TreeNode *child = mp[childVal].first;

        if (isLeft)
            parent->left = child;
        else
            parent->right = child;

        mp[childVal].second = parent;
    }

    for (auto &p : mp)
    {
        if (p.second.second == NULL)
            return p.second.first;
    }

    return NULL;
}
bool hasPathSum(TreeNode *root, int targetSum)
{
    if (!root)
        return false;

    if (!root->left && !root->right && targetSum == root->val)
    {
        return true;
    }

    return hasPathSum(root->left, targetSum - root->val) ||
           hasPathSum(root->right, targetSum - root->val);
}

int main()
{
    vector<vector<int>> descriptions = {
        {20, 15, 1},
        {20, 17, 0},
        {15, 10, 1}};

    TreeNode *root = createBinaryTree(descriptions);
    cout << root->val;

    bool ans = hasPathSum(root, 6);
    cout<<ans;
}
