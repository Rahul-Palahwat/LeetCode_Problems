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
    vector<TreeNode*> solve(int l , int r){
        if(l>r){
            return {NULL};
        }
        vector<TreeNode*> ans;
        for(int i=l;i<=r;i++){
            vector<TreeNode*> left = solve(l , i-1);
            vector<TreeNode*> right = solve(i+1 , r);
            for(auto itl: left){
                for(auto itr: right){
                    TreeNode* node = new TreeNode(i);
                    node->left = itl;
                    node->right = itr;
                    ans.push_back(node);
                }
            }
            
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1 , n);
    }
};