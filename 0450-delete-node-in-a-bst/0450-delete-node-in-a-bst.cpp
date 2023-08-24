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
    int findLeftMini(TreeNode* root){
        while(root->left){
            root = root->left;
        }
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root){
            return root;
        }
        if(root->val > key){
            root->left = deleteNode(root->left , key);
        }else if(root->val < key){
            root->right = deleteNode(root->right , key);
        }else{
            if(root->right == NULL){
                return root->left;
            }
            if(root->left == NULL){
                return root->right;
            }
            int val = findLeftMini(root->right);
            root->val = val;
            root->right = deleteNode(root->right , val);
        }
        return root;
    }
};