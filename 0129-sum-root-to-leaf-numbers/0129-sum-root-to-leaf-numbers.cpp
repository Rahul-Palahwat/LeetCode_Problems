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
    int ans = 0;
    void solve(TreeNode* root , int sum){
        if(!root->left && !root->right){
            sum*=10;
            sum+=root->val;
            ans+=sum;
            return;
        }
        sum*=10;
        if(root->left)
        solve(root->left , sum+root->val);
        if(root->right)
        solve(root->right , sum+root->val);
        return;
    }
    int sumNumbers(TreeNode* root) {
        solve(root , 0);
        return ans;
    }
};