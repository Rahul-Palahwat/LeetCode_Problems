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
    map<int , vector<TreeNode*>> mp;
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> ans;
        if(n == 0 || n%2 == 0){
            return ans;
        }
        if(mp.find(n) != mp.end()){
            return mp[n];
        }
        if(n == 1){
            TreeNode* node = new TreeNode(0);
            ans.push_back(node);
            mp[1] = ans;
            return ans;
        }
        for(int i=1;i<n;i+=2){
            vector<TreeNode*> left = allPossibleFBT(i);
            vector<TreeNode*> right = allPossibleFBT(n-i-1);
            
            for(auto it: left){
                for(auto i: right){
                    TreeNode* root = new TreeNode(0);
                    root->left = it;
                    root->right = i;
                    ans.push_back(root);
                }
            }
        }
        return mp[n] = ans;
    }
};