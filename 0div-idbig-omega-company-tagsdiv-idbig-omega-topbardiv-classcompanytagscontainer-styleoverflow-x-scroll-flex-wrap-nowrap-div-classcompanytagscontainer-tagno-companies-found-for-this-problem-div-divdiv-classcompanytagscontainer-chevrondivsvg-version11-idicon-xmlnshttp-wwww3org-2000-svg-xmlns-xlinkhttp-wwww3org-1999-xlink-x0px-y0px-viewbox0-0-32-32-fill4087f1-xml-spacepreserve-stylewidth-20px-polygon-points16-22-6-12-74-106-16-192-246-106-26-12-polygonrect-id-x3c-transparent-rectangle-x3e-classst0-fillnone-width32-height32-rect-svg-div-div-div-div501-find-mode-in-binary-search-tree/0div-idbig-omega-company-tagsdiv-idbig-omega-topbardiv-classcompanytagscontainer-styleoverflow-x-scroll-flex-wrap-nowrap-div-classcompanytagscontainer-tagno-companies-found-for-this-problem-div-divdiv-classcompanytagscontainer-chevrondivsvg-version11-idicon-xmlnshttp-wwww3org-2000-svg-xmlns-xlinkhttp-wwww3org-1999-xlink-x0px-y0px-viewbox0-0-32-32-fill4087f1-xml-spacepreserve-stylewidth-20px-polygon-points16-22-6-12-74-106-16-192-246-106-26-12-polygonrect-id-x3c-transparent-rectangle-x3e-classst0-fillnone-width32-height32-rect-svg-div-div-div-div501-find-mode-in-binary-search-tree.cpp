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
    map<int,int> mp;
    void solve(TreeNode* root){
        if(!root){
            return;
        }
        mp[root->val]++;
        solve(root->left);
        solve(root->right);
        return;
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        solve(root);
        int temp;
        int maxi = 0;
        // cout<<mp.size()<<endl;
        for(auto it: mp){
            if(maxi<it.second){
                maxi = it.second;
                temp = it.first;
            }
        }
        // cout<<temp<<endl;
        ans.push_back(temp);
        for(auto it : mp){
            if(maxi == it.second){
                if(temp != it.first){
                    ans.push_back(it.first);
                }
            }
        }
        return ans;
    }
};