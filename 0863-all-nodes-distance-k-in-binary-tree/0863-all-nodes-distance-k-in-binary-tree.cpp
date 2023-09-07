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
    
    // Function for storing parent nodes
    void solve(TreeNode* root, map<TreeNode* , TreeNode*> &mp){
        if(!root){
            return;
        }
        if(root->left){
            mp[root->left] = root;
        }
        if(root->right){
            mp[root->right] = root;
        }
        solve(root->left , mp);
        solve(root->right , mp);
        return;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if(!root){
            return ans;
        }
        map<TreeNode*, TreeNode*> mp;
        // Function for storing parent Nodes
        solve(root , mp);
        map<TreeNode* , int> vis;
        queue<TreeNode*> q;
        q.push(target);
        int dis = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto top = q.front();
                q.pop();
                vis[top]=1;
                if(dis == k){
                    ans.push_back(top->val);
                }
                if(top->left && vis.find(top->left) == vis.end()){
                    q.push(top->left);
                }
                if(top->right && vis.find(top->right) == vis.end()){
                    q.push(top->right);
                }
                if(mp.find(top) != mp.end() && vis.find(mp[top]) == vis.end()){
                    q.push(mp[top]);
                }
            }
            dis++;
        }
        return ans;
    }
};