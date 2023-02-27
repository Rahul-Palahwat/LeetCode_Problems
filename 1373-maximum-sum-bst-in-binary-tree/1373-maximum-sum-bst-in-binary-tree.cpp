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
    int ans = 0;
    vector<int> solve(TreeNode* root , int &ans){
        if(!root){
            return {0 , INT_MIN , INT_MAX};
        }
        vector<int> left = solve(root->left , ans);
        vector<int> right = solve(root->right , ans);
        if(left.size() == 0 || right.size() == 0){
            return {};
        }
        if(root->val <= left[1] || root->val >= right[2]){
            return {};
        }
        int sum = left[0]+right[0]+root->val;
        ans = max(ans , sum);
        return {sum , max(right[1] , root->val) ,min(root->val , left[2]) };
        
    }
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        solve(root , ans);
        return max(0 , ans);
    }
};