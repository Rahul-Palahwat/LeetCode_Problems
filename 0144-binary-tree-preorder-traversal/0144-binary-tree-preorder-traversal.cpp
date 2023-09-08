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
    
    // using stack Iterative
    // vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int> ans;
    //     stack<TreeNode*> st;
    //     st.push(root);
    //     while(!st.empty()){
    //         auto t = st.top();
    //         st.pop();
    //         if(t == NULL){
    //             continue;
    //         }
    //         ans.push_back(t->val);
    //         st.push(t->right);
    //         st.push(t->left);
    //     }
    //     return ans;
    // }
    
    
    
    
    
    // Morris traversal
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        TreeNode *curr = root;
        while(curr){
            if(curr->left == NULL){
                preorder.push_back(curr->val);
                curr = curr->right;
            }else{
                TreeNode *prev = curr->left;
                while(prev->right && prev->right != curr){
                    prev = prev->right;
                }
                
                if(prev->right == NULL){
                    prev->right = curr;
                    preorder.push_back(curr->val);
                    curr = curr->left;
                }else{
                    prev->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return preorder;
    }
};