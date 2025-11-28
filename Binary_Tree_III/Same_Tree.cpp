/*Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

Example
Input: p = [1,2,3], q = [1,2,3]
Output: true
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL) return true;
        if((p!=NULL && q==NULL) || (q!=NULL && p==NULL)) return false;
        if(p->val != q->val){
            return false;
        }
        if(!isSameTree(p->left,q->left) || !isSameTree(p->right,q->right)){
            return false;
        }
        return true;
    }
int main() {
    vector<vector<int>> descriptions = {
        {20, 15, 1},
        {20, 17, 0},
        {15, 10, 1}
    };
    vector<vector<int>> descriptions2 = {
        {20, 15, 1},
        {20, 17, 0},
        {15, 10, 1}
    };
    TreeNode* root = createBinaryTree(descriptions);
    cout << root->val;
    TreeNode* root2 = createBinaryTree(descriptions2);
    cout << root->val;
    bool ans = isSameTree(root, root2);
    cout<<ans<<endl;
    return 0;
}
