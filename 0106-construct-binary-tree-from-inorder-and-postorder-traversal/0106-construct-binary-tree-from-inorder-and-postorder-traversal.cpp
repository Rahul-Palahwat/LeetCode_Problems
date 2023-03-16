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
    // unordered_map<int,int> mp;
    // TreeNode* solve(vector<int> in ,int inStart ,int inEnd , vector<int> p , int pStart , int pEnd){
    //     if(inStart > inEnd){
    //         return NULL;
    //     }
    //     if(pStart == pEnd){
    //         return NULL;
    //     }
    //     TreeNode* node = new TreeNode(p[pEnd]);
    //     int index = mp[p[pEnd]];
    //     node->left = solve(in , inStart , index-1 , p , pStart , pStart+index-1);
    //     node->right = solve(in , index+1 , inEnd , p , pStart+index , pEnd-1);
    //     return node;
    // }
    TreeNode* solve(vector<int> in, vector<int> p){
        if(in.size() == 0 || p.size() == 0){
            return NULL;
        }
        unordered_map<int,int> mp;
        for(int i=0;i<in.size();i++){
            mp[in[i]] = i;
        }
        TreeNode* node = new TreeNode(p[p.size()-1]);
        int index = mp[p[p.size()-1]];
        vector<int> leftIn , rightIn , leftP , rightP;
        for(int i=0;i<index;i++){
            leftIn.push_back(in[i]);
        }
        for(int i=index+1;i<in.size();i++){
            rightIn.push_back(in[i]);
        }
        for(int i=0;i<index;i++){
            leftP.push_back(p[i]);
        }
        for(int i=index;i<in.size()-1;i++){
            rightP.push_back(p[i]);
        }
        node->left = solve(leftIn , leftP);
        node->right = solve(rightIn , rightP);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& post) {
        int n = inorder.size();
        // for(int i=0;i<n;i++){
        //     mp[inorder[i]] = i;
        // }
        // return solve(inorder , 0 , n-1 , post , 0 , n-1);
        return solve(inorder ,post);
    }
};