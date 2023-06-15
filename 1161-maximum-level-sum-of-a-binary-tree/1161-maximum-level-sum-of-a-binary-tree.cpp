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
    int maxLevelSum(TreeNode* root) {
        int ans = 0 , sum = INT_MIN , level=1;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            ans++;
            int sz = q.size() , temp = 0;
            while(sz--){
                auto top = q.front();
                q.pop();
                temp+=top->val;
                if(top->left){
                    q.push(top->left);
                }
                if(top->right){
                    q.push(top->right);
                }
            }
            if(temp > sum){
                sum = temp;
                level = ans;
            }
        }
        return level;
    }
};