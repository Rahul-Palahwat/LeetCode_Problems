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
    bool Check(TreeNode* node){
        if(!node){
            return false;
        }
        if(node->val == 1){
            return true;
        }
        return Check(node->left) || Check(node->right);
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(!root){
            return NULL;
        }
        if(Check(root)){
            root->left  = pruneTree(root->left);
            root->right = pruneTree(root->right);
        }else{
            return NULL;
        }
        return root;
    }
};