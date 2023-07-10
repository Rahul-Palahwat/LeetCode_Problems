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
    
    int solve(TreeNode* root){
        if(!root){
            return 0;
        }
        if(root->left == NULL && root->right == NULL){
            return 1;
        }
        int l=INT_MAX, r = INT_MAX;
        if(root->left){
            l = solve(root->left);
        }
        if(root->right){
            r = solve(root->right);
        }
        return 1+min(l,r);
    }
    int minDepth(TreeNode* root) {
        return solve(root);
    }
};