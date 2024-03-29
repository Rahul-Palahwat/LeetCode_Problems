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
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int> maxh;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            maxh.push(top->val);
            if(maxh.size() > k){
                maxh.pop();
            }
            if(top->left){
                q.push(top->left);
            }
            if(top->right){
                q.push(top->right);
            }
        }
        return maxh.top();
    }
};