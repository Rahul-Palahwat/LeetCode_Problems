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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        if(n == 0){
            return NULL;
        }
        TreeNode *root = new TreeNode(preorder[0]);
        int i=1;
        while(i<n && preorder[i] < preorder[0]){
            i++;
        }
        vector<int> left(preorder.begin()+1 , preorder.begin()+i);
        root->left = bstFromPreorder(left);
        vector<int> right(preorder.begin()+i , preorder.begin()+n);
        root->right = bstFromPreorder(right);
        return root;
    }
};