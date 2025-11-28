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

int maxDepth(TreeNode *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}
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

int main()
{
    vector<vector<int>> descriptions = {
        {20, 15, 1},
        {20, 17, 0},
        {15, 10, 1}};

    TreeNode *root = createBinaryTree(descriptions);
    cout << root->val << endl;

    int height = maxDepth(root);
    cout<<height<<endl;
}
