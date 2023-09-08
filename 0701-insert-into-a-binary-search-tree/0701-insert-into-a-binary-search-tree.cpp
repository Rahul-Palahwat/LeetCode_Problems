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
    void insertNode(TreeNode *root , int val){
        if(!root){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            if(root->val > val){
                root->left = new TreeNode(val);
            }else{
                root->right = new TreeNode(val);
            }
            return;
        }
        if(root->left == NULL && root->val > val){
            root->left = new TreeNode(val);
            return;
        }
        if(root->right == NULL && root->val < val){
            root->right = new TreeNode(val);
            return;
        }
        if(root->val > val){
            insertNode(root->left , val);
        }else{
            insertNode(root->right , val);
        }
        return;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            return new TreeNode(val);
        }
        TreeNode *curr = root;
        insertNode(root , val);
        return curr;
    }
};