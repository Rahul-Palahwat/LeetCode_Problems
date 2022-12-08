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
    void solve(TreeNode *root,vector<int> &v){
        if(root == NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            v.push_back(root->val);
            return;
        }
        solve(root->left,v);
        solve(root->right,v);
        return;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> f,s;
        solve(root1,f);
        solve(root2,s);
        if(f.size() == s.size()){
            for(int i=0;i<f.size();i++){
                if(f[i] != s[i]){
                    return false;
                }
            }
            return true;
        }
        return false;
    }
};