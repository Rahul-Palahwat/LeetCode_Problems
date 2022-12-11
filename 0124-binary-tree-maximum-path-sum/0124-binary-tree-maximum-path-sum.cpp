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
    // int res=INT_MIN;
    // int solve(TreeNode* root){
    //     if(root == NULL){
    //         return 0;
    //     }
    //     int l = solve(root->left);
    //     int r = solve(root->right);
    //     int temp = max(root->val + max( l , r) , root->val);
    //     int ans = max(temp , (root->val + l + r));
    //     res=max(res,ans);
    //     return temp;
    // }
    // int maxPathSum(TreeNode* root) {
    //     solve(root);
    //     return res;
    // }
    
    
    // 2nd time try method 
//     int maxi = INT_MIN;
//     int solve(TreeNode* root){
//         if(root == NULL){
//             return 0;
//         }
//         int left = solve(root->left);
//         int right = solve(root->right);
//         if(right<0 && left<0){
//             maxi = max(maxi , root->val);
//         }
//         else if(left<0){
//             maxi = max(maxi , root->val + right);
//         }else if(right<0){
//             cout<<"hello";
//             maxi = max(maxi , root->val + left);
//         }else{
//             maxi = max(maxi , root->val + left + right);
//         }
        
//         return max(root->val , root->val + max(left , right));
//     }
//     int maxPathSum(TreeNode* root) {
//         solve(root);
//         return maxi;
//     }
    
    // 3rd time
    int maxi = INT_MIN;
    int solve(TreeNode* root){
        if(!root){
            return 0;
        }
        int left = solve(root->left);
        int right = solve(root->right);
        if(left < 0 && right <0){
            maxi = max(maxi ,root->val);
        }else if(left < 0){
            maxi = max(maxi , right+root->val);
        }else if(right < 0){
            maxi = max(maxi , left+root->val);
        }else{
            maxi = max(maxi , left+right+root->val);
        }
        return max(root->val , root->val+max(left,right));
        
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxi;
    }
};