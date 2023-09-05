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
    int solve(TreeNode* root , bool &ans){
        if(!root){
            return 0;
        }
        int leftDepth = solve(root->left , ans);
        int rightDepth = solve(root->right , ans);
        if(abs(leftDepth - rightDepth) > 1){
            ans = false;
        }
        return 1+max(leftDepth , rightDepth);
    }
    bool isBalanced(TreeNode* root) {
        if(!root){
            return true;
        }
        bool ans = true;
        TreeNode* node = root;
        int d = solve(node , ans);
        return ans;
    }
};