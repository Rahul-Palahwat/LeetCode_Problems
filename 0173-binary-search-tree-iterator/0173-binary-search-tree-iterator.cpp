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
class BSTIterator {
public:
    vector<int> ans;
    void solve(TreeNode* root){
        if(!root){
            return;
        }
        solve(root->left);
        ans.push_back(root->val);
        solve(root->right);
        return;
    }
    int n;
    BSTIterator(TreeNode* root) {
        solve(root);
        reverse(ans.begin() , ans.end());
        n = ans.size();
    }
    int next() {
        n--;
        return ans[n];
    }
    
    bool hasNext() {
        if(n<=0){
            return false;
        }
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */