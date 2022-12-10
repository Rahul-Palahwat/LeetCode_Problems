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
    long res = 0, total = 0, sub;
    int maxProduct(TreeNode* root) {
        total = s(root), s(root);
        return res % (int)(1e9 + 7);
    }

    int s(TreeNode* root) {
        if (!root) return 0;
        sub = root->val + s(root->left) + s(root->right);
        res = max(res, sub * (total - sub));
        return sub;
    }
//     int sum=0;
//     int maxi = INT_MIN;
//     void solve(TreeNode* root){
//         if(!root) return;
//         sum+=root->val;
//         solve(root->left);
//         solve(root->right);
//         return;
//     }
//     void findMaxi(TreeNode* root,int &temp){
//         if(!root){
//             return;
//         }
//         maxi = max(maxi , temp*(sum-temp));
//         cout<<temp<<"temp"<<sum<<"sum"<<sum-temp<<endl;
//         findMaxi(root->left , temp);
//         findMaxi(root->right,temp);
//         temp = temp+root->val;
//         return;
//     }
//     int maxProduct(TreeNode* root) {
//         TreeNode* temp = root;
//         solve(temp);
//         temp = root;
//         int t=0;
//         findMaxi(temp,t);
//         return maxi;
        
//     }
};