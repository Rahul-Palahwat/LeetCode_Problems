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
    // int ans = 0;
    // int solve(TreeNode* root , bool taken){
    //     if(root == NULL){
    //         return 0;
    //     }
    //     if(taken){
    //         return solve(root->left , false)+solve(root->right , false);
    //     }else{
    //         int one = root->val + solve(root->left , true) + solve(root->right , true);
    //         int two = solve(root->left ,false)+solve(root->right , false);
    //         return max(one,two);
    //     }
    // }
    // int rob(TreeNode* root) {
    //     int one = solve(root , false);
    //     int two = solve(root , true);
    //     return max(one,two);
    // }
    
    
    
     vector<int> traverser(TreeNode* curr){
        if(!curr){
            return {0, 0};
        }
        
        vector<int>l, r, t;
        l = traverser(curr->left);
        r = traverser(curr->right);
        
        t.push_back( l[1] + r[1] + curr->val );
        t.push_back( max(l[0], l[1]) + max(r[0], r[1]) );
        
        return t;
    }
    int rob(TreeNode* root) {
        vector<int>holder = traverser(root);
        return max(holder[0], holder[1]);
    }
};