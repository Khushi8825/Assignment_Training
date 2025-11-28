/*Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree.
This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.*/
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
int height(TreeNode *root, int &maxi)
{
    if (root == NULL)
        return 0;
    int LH = height(root->left, maxi);
    int RH = height(root->right, maxi);
    maxi = max(maxi, LH + RH);
    return max(LH, RH) + 1;
}
int diameterOfBinaryTree(TreeNode *root)
{
    int diameter = 0;
    height(root, diameter);
    return diameter;
}
int main()
{
    vector<vector<int>> descriptions = {
        {20, 15, 1},
        {20, 17, 0},
        {15, 10, 1}};

    TreeNode *root = createBinaryTree(descriptions);
    cout << root->val;

    int ans = diameterOfBinaryTree(root);
    cout<<ans;
}
