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
    // brute force 
    // int countNodes(TreeNode* root) {
    //     if(!root){
    //         return 0;
    //     }
    //     if(root->left){
    //         return 1+countNodes(root->left)+countNodes(root->right);
    //     }else{
    //         return 1;
    //     }
    // }
    int ans=0;
    int level=0;
    int solveRight(TreeNode* root){
        if(!root){
            return 0;
        }
        return 1+solveRight(root->right);
    }
    int solveLeft(TreeNode* root){
        if(!root){
            return 0;
        }
        return 1+solveLeft(root->left);
    }
    
    int countNodes(TreeNode* root) {
        if(!root){
            return 0;
        }
        int left = solveLeft(root->left);
        int right = solveRight(root->right);
        // cout<<left<<right<<endl;
        if(left == right){
            // cout<<(pow(2,left))*2 - 1<<"ANs"<<endl;
            return (pow(2,left))*2 - 1;
        }else{
            return 1+countNodes(root->left)+countNodes(root->right);
        }
    }
};