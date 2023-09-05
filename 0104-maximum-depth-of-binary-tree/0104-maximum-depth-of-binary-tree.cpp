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
    int findDepth(TreeNode* root){
        if(!root){
            return 0;
        }
        int leftDepth = findDepth(root->left);
        int rightDepth = findDepth(root->right);
        return 1+max(leftDepth , rightDepth);
    }
    int maxDepth(TreeNode* root) {
        TreeNode* node = root;
        return findDepth(node);
    }
};