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
    int findLeftHeight(TreeNode* root){
        if(!root){
            return 0;
        }
        int ans =0;
        while(root){
            root = root->left;
            ans++;
        }
        return ans;
    }
    int findRightHeight(TreeNode* root){
        if(!root){
            return 0;
        }
        int ans = 0;
        while(root){
            root = root->right;
            ans++;
        }
        return ans;
    }
    int countNodes(TreeNode* root) {
        if(!root){
            return 0;
        }
        int ans = 0;
        int l = findLeftHeight(root->left);
        int r = findRightHeight(root->right);
        if(l==r){
            return 1+2*((1<<l)-1);
        }else{
            return 1+countNodes(root->left)+countNodes(root->right);
        }
    }
};