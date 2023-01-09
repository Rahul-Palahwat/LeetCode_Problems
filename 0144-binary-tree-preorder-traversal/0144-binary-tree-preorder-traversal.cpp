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
    void solve(TreeNode* root,vector<int>& v){
        stack<TreeNode*> q;
        if(root == NULL){
            return;
        }
        q.push(root);
        while(q.size() > 0){
            auto t = q.top();
            cout<<t->val<<" ";
            q.pop();
            v.push_back(t->val);
            if(t->right != NULL){
                q.push(t->right);
            }
            if(t->left != NULL){
                q.push(t->left);
            }
        }
        return;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        solve(root,v);
        return v;
    }
};