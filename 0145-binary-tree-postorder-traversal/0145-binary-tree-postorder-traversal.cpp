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
    // vector<int> postorderTraversal(TreeNode* root) {
    //     vector<int> ans;
    //     if(!root){
    //         return ans;
    //     }
    //     stack<TreeNode*> st;
    //     st.push(root);
    //     while(!st.empty()){
    //         auto top = st.top();
    //         st.pop();
    //         ans.push_back(top->val);
    //         if(top->left != NULL){
    //             st.push(top->left);
    //         }
    //         if(top->right != NULL){
    //             st.push(top->right);
    //         }
    //     }
    //     reverse(ans.begin(), ans.end());
    //     return ans;
    // }
    
    
    
    
    // All traversal in one go
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans[3];
        if(!root){
            return ans[2];
        }
        // ans[0] -> PreOrder
        // ans[1] -> InOrder
        // ans[2] -> PostOrder
        stack<pair<TreeNode* , int>> st;
        st.push({root , 1});
        while(!st.empty()){
            auto top = st.top();
            st.pop();
            if(top.second == 1){
                ans[0].push_back(top.first->val);
                st.push({top.first , 2});
                if(top.first->left)
                    st.push({top.first->left , 1});
            }else if(top.second == 2){
                ans[1].push_back(top.first->val);
                st.push({top.first , 3});
                if(top.first->right)
                    st.push({top.first->right , 1});
            }else{
                ans[2].push_back(top.first->val);
            }
        }
        return ans[2];
    }
};