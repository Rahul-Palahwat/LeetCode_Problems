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
    TreeNode *target = NULL;
    void addParent(TreeNode *root , map<TreeNode*, TreeNode*> &mp, int val){
        if(!root){
            return;
        }
        if(root->val == val){
            target = root;
        } 
        if(root->left){
            mp[root->left] = root;
        }
        if(root->right){
            mp[root->right] = root;
        }
        addParent(root->left , mp , val);
        addParent(root->right , mp , val);
        return;
    }
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode* , TreeNode*> mp;
        addParent(root, mp , start);
        int ans = 0;
        map<TreeNode* , int> vis;
        queue<TreeNode*> q;
        q.push(target);
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto top = q.front();
                q.pop();
                vis[top] = 1;
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
            ans++;
        }
        return ans-1;
    }
};