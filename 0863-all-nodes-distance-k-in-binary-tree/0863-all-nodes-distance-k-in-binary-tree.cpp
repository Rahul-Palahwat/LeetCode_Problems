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
    void addNodes(TreeNode* root , int dis, vector<int> &ans){
        if(!root){
            return;
        }
        if(dis == 0){
            ans.push_back(root->val);
        }
        addNodes(root->left , dis-1 , ans);
        addNodes(root->right , dis-1 , ans);
        return;
    }
    void addPrevNodes(TreeNode* root, int dis , map<TreeNode* , TreeNode*> &mp, vector<int> &ans){
        if(!root){
            return;
        }
        if(dis == 0){
            ans.push_back(root->val);
        }
        if(mp.find(root) != mp.end()){
            if(mp[root]->left == root){
                addPrevNodes(mp[root] , dis-1 , mp , ans);
                addNodes(mp[root]->right , dis-2 , ans);
            }
            else{
                addPrevNodes(mp[root] , dis-1 , mp , ans);
                addNodes(mp[root]->left , dis-2 , ans);
            }
        }
        return;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if(!root){
            return ans;
        }
        map<TreeNode*, TreeNode*> mp;
        solve(root , mp);
        addNodes(target , k, ans);
        if(k == 0){
            return ans;
        }
        addPrevNodes(target , k , mp , ans);
        return ans;
    }
};