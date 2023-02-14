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
    // vector<int> ans;
    // void solve(TreeNode* root){
    //     if(!root){
    //         return;
    //     }
    //     solve(root->left);
    //     ans.push_back(root->val);
    //     solve(root->right);
    //     return;
    // }
    
    
    
    // Morris Traversal
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TreeNode* cur = root;
        while(cur){
            // when there is no one in left 
            if(cur->left == NULL){
                inorder.push_back(cur->val);
                cur = cur->right;
            }
            // when there are nodes in left so we will move to left and then bottom of right to connect to cur node by threading 
            else{
                TreeNode* prev = cur->left;
                while(prev->right && prev->right != cur){
                    prev = prev->right;
                }
                if(prev->right == NULL){
                    prev->right = cur;
                    cur = cur->left;
                }else{
                    cur = prev->right;
                    inorder.push_back(cur->val);
                    prev->right = NULL;
                    cur = cur->right;
                }
            }
        }
        return inorder;
    }
};