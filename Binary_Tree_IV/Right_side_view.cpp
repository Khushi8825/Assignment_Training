/*Given the root of a binary tree, imagine yourself standing on the right side of it, 
return the values of the nodes you can see ordered from top to bottom.

Example
Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
*/
#include <iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
    unordered_map<int, pair<TreeNode*, TreeNode*>> mp;

    for (auto &d : descriptions) {
        int parentVal = d[0];
        int childVal  = d[1];
        int isLeft    = d[2];

        if (!mp[parentVal].first)
            mp[parentVal].first = new TreeNode(parentVal);

        if (!mp[childVal].first)
            mp[childVal].first = new TreeNode(childVal);

        TreeNode* parent = mp[parentVal].first;
        TreeNode* child  = mp[childVal].first;

        if (isLeft) parent->left = child;
        else        parent->right = child;

        mp[childVal].second = parent;
    }

    for (auto &p : mp) {
        if (p.second.second == NULL)
            return p.second.first;
    }

    return NULL;
}
    void Level(TreeNode* root, int level,vector<int>& ans){
        if(root==NULL){
            return;
        }
        if(level == ans.size()){
            ans.push_back(root->val);
        }
        Level(root->right,level+1,ans);
        Level(root->left,level+1,ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        Level(root,0,ans);
        return ans;
    }
int main() {
    vector<vector<int>> descriptions = {
        {20, 15, 1},
        {20, 17, 0},
        {15, 10, 1}
    };

    TreeNode* root = createBinaryTree(descriptions);
    cout << root->val;
    vector<int> ans = rightSideView(root);
    for(int i = 0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
