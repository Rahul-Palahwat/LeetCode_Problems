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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int , vector<int>> mp;
        vector<vector<int>> ans;
        if(!root){
            return ans;
        }
        queue<pair<TreeNode* , int>> q;
        q.push({root , 0});
        while(!q.empty()){
            int t = q.size();
            unordered_map<int,vector<int>> tmap;
            while(t--){
                TreeNode* node = q.front().first;
                int pos = q.front().second;
                // cout<<pos<<" "<<node->val<<endl;
                q.pop();
                tmap[pos].push_back(node->val);
                if(node->left){
                    q.push({node->left , pos-1});
                }
                if(node->right){
                    q.push({node->right , pos+1});
                }
            }
            for(auto it: tmap){
                sort(it.second.begin() , it.second.end());
                for(auto i: it.second){
                    mp[it.first].push_back(i);
                }
            }
        }
        for(auto it: mp){
            // sort(it.second.begin() , it.second.end());
            ans.push_back(it.second);
        }
        return ans;
    }
};