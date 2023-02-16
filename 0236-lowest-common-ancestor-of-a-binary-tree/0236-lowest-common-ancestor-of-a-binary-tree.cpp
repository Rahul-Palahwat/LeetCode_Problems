/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool solve(TreeNode* root , TreeNode* f , vector<TreeNode*>& path){
        if(!root){
            return false;
        }
        path.push_back(root);
        if(root == f){
            return true;
        }
        if(solve(root->left , f , path) || solve(root->right , f , path)){
            return true;
        }
        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1,path2;
        solve(root , p , path1);
        solve(root , q , path2);
        TreeNode* ans;
        int i=0,j=0;
        while(i<path1.size() && j<path2.size()){
            if(path1[i] != path2[j]){
                break;
            }
            ans = path1[i];
            i++;
            j++;
        }
        return ans;
    }
};