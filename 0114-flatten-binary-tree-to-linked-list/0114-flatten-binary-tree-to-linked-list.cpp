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
    void flatten(TreeNode* root) {
        if(!root){
            return;
        }
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            auto top = st.top();
            st.pop();
            if(top->right){
                st.push(top->right);
            }
            if(top->left){
                st.push(top->left);
            }
            top->left = NULL;
            if(st.size() > 0){
                top->right = st.top();
            }else{
                top->right = NULL;
            }
        }
        return;
    }
};