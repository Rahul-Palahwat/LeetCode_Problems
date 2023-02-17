/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorder;
    void solve(TreeNode* root){
        if(!root){
            return;
        }
        solve(root->left);
        preorder.push_back(root->val);
        solve(root->right);
        return;
    }
    int minDiffInBST(TreeNode* root) {
        int ans = INT_MAX;
        solve(root);
        for(int i=0;i<preorder.size()-1;i++){
            ans = min(ans , preorder[i+1]-preorder[i]);
        }
        return ans;
    }
};