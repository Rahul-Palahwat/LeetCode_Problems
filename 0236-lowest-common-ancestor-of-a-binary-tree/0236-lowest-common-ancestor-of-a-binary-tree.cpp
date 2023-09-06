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
    bool findPath(TreeNode *root , TreeNode *node , vector<TreeNode*> &ans){
        if(!root){
            return false;
        }
        ans.push_back(root);
        if(root == node){
            return true;
        }
        if(findPath(root->left , node , ans) || findPath(root->right , node , ans)){
            return true;
        }
        ans.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> first , second;
        findPath(root , p , first);
        findPath(root , q , second);
        int n = first.size(), m = second.size();
        int mini = min(n , m);
        TreeNode *ans = NULL;
        // cout<<n<<" "<<m<<endl;
        for(int i=0;i<mini;i++){
            if(first[i] == second[i]){
                ans = first[i];
            }
        }
        return ans;
    }
};