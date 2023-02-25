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
    TreeNode* bstFromPreorder(vector<int>& pre) {
        int n = pre.size();
        if(n == 0)
            return NULL;
        
        TreeNode* node = new TreeNode(pre[0]);
        if(n==1)
            return node;
        
        int i=1;
        while(i<n && (pre[i]< pre[0]))
            i++;
        
        vector<int> left(pre.begin()+1 , pre.begin()+i);
        node->left = bstFromPreorder(left);
        vector<int> right(pre.begin()+i , pre.begin()+n);
        node->right = bstFromPreorder(right);
        return node;
        
    }
};