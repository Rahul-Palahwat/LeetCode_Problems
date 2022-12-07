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
    //     ans.push_back(root->val);
    //     solve(root->left);
    //     solve(root->right);
    //     return;
    // }
    // int rangeSumBST(TreeNode* root, int low, int high) {
    //     solve(root);
    //     int out=0;
    //     for(int i=0;i<ans.size();i++){
    //         if(ans[i]>=low && ans[i]<=high){
    //             out+=ans[i];
    //         }
    //     }
    //     return out;
    // }
    
    // 2nd method
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == NULL){
            return 0;
        }
        if(root->val > high){
            return rangeSumBST(root->left , low , high);
        }
        if(root->val <low){
            return rangeSumBST(root->right, low , high);
        }
        return root->val + rangeSumBST(root->left,low,high) + rangeSumBST(root->right,low,high);
    }
};