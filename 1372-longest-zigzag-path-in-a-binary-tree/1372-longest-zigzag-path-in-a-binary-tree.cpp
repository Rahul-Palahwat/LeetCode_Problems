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
    // Recursion getting TLE 
    // int len = 0;
    // int find(TreeNode* node , int dir){
    //     if(!node){
    //         return 0;
    //     }
    //     if(dir == 0){
    //         if(node->right == NULL){
    //             return 0;
    //         }else{
    //             return 1+find(node->right , 1);
    //         }
    //     }else{
    //         if(node->left == NULL){
    //             return 0;
    //         }else{
    //             return 1+find(node->left , 0);
    //         }
    //     }
    //     return 0;
    // }
    // void solve(TreeNode* root){
    //     if(!root){
    //         return;
    //     }
    //     len = max(len , find(root , 0));
    //     len = max(len , find(root , 1));
    //     solve(root->left);
    //     solve(root->right);
    //     return;
    // }
    // int longestZigZag(TreeNode* root) {
    //     solve(root);
    //     return len;
    // }
    
    
    
    
    map<pair<TreeNode* , int> , int> mp;
    int len = 0;
    int find(TreeNode* node , int dir){
        if(!node){
            return 0;
        }
        if(mp.find({node , dir}) != mp.end()){
            return mp[{node , dir}];
        }
        int ans = 0;
        if(dir == 0){
            if(node->right != NULL){
                ans =  1+find(node->right , 1);
            }
        }else{
            if(node->left != NULL){
                ans = 1+find(node->left , 0);
            }
        }
        return mp[{node , dir}] = ans;
    }
    void solve(TreeNode* root){
        if(!root){
            return;
        }
        int left = find(root , 0);
        int right = find(root , 1);
        mp[{root , 0}] = left;
        mp[{root , 1}] = right;
        len = max(len , left);
        len = max(len , right);
        solve(root->left);
        solve(root->right);
        return;
    }
    int longestZigZag(TreeNode* root) {
        solve(root);
        return len;
    }
};