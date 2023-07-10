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
    
    // int solve(TreeNode* root){
    //     if(!root){
    //         return 0;
    //     }
    //     if(root->left == NULL && root->right == NULL){
    //         return 1;
    //     }
    //     int l=INT_MAX, r = INT_MAX;
    //     if(root->left){
    //         l = solve(root->left);
    //     }
    //     if(root->right){
    //         r = solve(root->right);
    //     }
    //     return 1+min(l,r);
    // }
    
    int solve(TreeNode* root){
        if(!root){
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        int ans = 1;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto top = q.front();
                q.pop();
                if(top->left == NULL && top->right == NULL){
                    return ans;
                }
                if(top->left){
                    q.push(top->left);
                }
                if(top->right){
                    q.push(top->right);
                }
            }
            ans++;
        }
        return ans;
    }
    int minDepth(TreeNode* root) {
        return solve(root);
    }
};