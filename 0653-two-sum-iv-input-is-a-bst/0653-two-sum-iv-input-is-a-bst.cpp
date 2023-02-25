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
    void solve(TreeNode* root){
        if(!root){
            return;
        }
        solve(root->left);
        ans.push_back(root->val);
        solve(root->right);
        return;
    }
    bool findTarget(TreeNode* root, int k) {
        solve(root);
        int n = ans.size();
        int i = 0 , j = n-1;
        // cout<<ans.size()<<" "<<ans[i]<<" "<<ans[j]<<endl;
        while(i<j){
            if(k == (ans[i]+ans[j])){
                return true;
            }else if(k> (ans[i]+ans[j])){
                i++;
            }else{
                j--;
            }
        }
        return false;
    }
};