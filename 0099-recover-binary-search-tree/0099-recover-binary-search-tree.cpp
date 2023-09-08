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
    vector<int> ans;
    vector<TreeNode*> up;
    void Solve(TreeNode* root){
        if(!root){
            return;
        }
        Solve(root->left);
        up.push_back(root);
        ans.push_back(root->val);
        Solve(root->right);
        return;
    }
    void recoverTree(TreeNode* root) {
        TreeNode *node = root;
        Solve(node);
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++){
            up[i]->val = ans[i];
        }
        return;
            
    }
};