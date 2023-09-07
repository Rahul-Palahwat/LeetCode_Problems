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
    unordered_map<int, int> mp;
    TreeNode *buildTree(vector<int>&pre, int startPre , int endPre, vector<int>& in , int startIn , int endIn){
        if(startPre > endPre || startIn > endIn){
            return NULL;
        }
        int pos = mp[pre[startPre]];
        int count = pos - startIn;
        TreeNode *root = new TreeNode(pre[startPre]);
        root->left = buildTree(pre , startPre+1 , startPre+count , in , startIn , pos-1);
        root->right = buildTree(pre , startPre+count+1 , endPre , in , pos+1 , endIn);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]] = i;
        }
        return buildTree(preorder , 0 , n-1 , inorder , 0 , n-1);
    }
};