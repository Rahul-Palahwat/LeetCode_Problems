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
    int maxi = 0;
    int solve(TreeNode* root){
        if(!root){
            return 0;
        }
        int left = solve(root->left);
        int right = solve(root->right);
        maxi = max(maxi , left+right);
        return 1+max(left , right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        auto ans = 0;
        if(!root){
            return ans;
        }
        ans = solve(root);
        return maxi;
    }
};