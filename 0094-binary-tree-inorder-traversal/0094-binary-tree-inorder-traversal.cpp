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
    
    
    
    // Iterative approach
    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> ans;
    //     stack<TreeNode*> st;
    //     TreeNode *node = root;
    //     while(true){
    //         if(node){
    //             st.push(node);
    //             node = node->left;
    //         }else{
    //             if(st.empty()){
    //                 break;
    //             }
    //             node = st.top();
    //             st.pop();
    //             ans.push_back(node->val);
    //             node = node->right;
    //         }
    //     }
    //     return ans;
    // }
    
    
    
    
    
    // Morris Traversal
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TreeNode *curr = root;
        while(curr){
            if(curr->left == NULL){
                inorder.push_back(curr->val);
                curr = curr->right;
            }else{
                TreeNode *temp = curr->left;
                while(temp->right && temp->right != curr){
                    temp = temp->right;
                }
                if(temp->right == NULL){
                    temp->right = curr;
                    curr = curr->left;
                }else{
                    temp->right = NULL;
                    inorder.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return inorder;
    }
};