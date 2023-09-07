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
    unordered_map<int,int> mp;
    TreeNode* solve(vector<int>& in, int sIn, int eIn, vector<int>& post, int sPo, int ePo){
        if(sIn > eIn || sPo > ePo){
            return NULL;
        }
        TreeNode *root = new TreeNode(post[ePo]);
        int pos = mp[post[ePo]];
        int size = pos - sIn;
        root->left = solve(in , sIn , sIn+size , post , sPo , sPo+size-1);
        root->right = solve(in , sIn+size+1, eIn , post , sPo+size , ePo-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]] = i;
        }
        return solve(inorder , 0 , n-1 , postorder , 0 , n-1);
    }
};