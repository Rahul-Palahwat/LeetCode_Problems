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
    map<int , int> mp;
    TreeNode* solve(vector<int>& inorder , int inStart , int inEnd , vector<int>& postorder, int poStart , int poEnd){
        if(inStart > inEnd || poStart > poEnd){
            return NULL;
        }
        TreeNode* node = new TreeNode(postorder[poEnd]);
        int pos = mp[node->val];
        node->left = solve(inorder , inStart , pos-1 , postorder , poStart , poStart + pos - inStart-1);
        node->right = solve(inorder , pos+1 , inEnd , postorder ,poStart+pos-inStart , poEnd-1);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]] = i;
        }
        TreeNode* ans = solve(inorder , 0 , n-1 , postorder ,0 , n-1);
        return ans;
    }
};