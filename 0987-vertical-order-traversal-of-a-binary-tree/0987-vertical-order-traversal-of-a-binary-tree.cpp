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
        vector<vector<int>> ans;
        map<int, vector<pair<int,int>>> mp;
        queue<pair<TreeNode* , int>> q;
        TreeNode* node = root;
        q.push({node , 0});
        int level = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto top = q.front();
                q.pop();
                TreeNode *temp = top.first;
                int pos = top.second;
                mp[pos].push_back({level ,temp->val});
                if(temp->left){
                    q.push({temp->left , pos-1});
                }
                if(temp->right){
                    q.push({temp->right , pos+1});
                }
            }
            level++;
        }
        for(auto &it: mp){
            sort(it.second.begin() , it.second.end());
            vector<int> temp;
            for(auto i: it.second){
                temp.push_back(i.second);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};