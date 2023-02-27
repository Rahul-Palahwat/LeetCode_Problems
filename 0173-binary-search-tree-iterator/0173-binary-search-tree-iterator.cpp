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
    
    // Brute force approach time O(n) & O(1) , Space O(N) but we need to solve this in O(H)
//     vector<int> ans;
//     void solve(TreeNode* root){
//         if(!root){
//             return;
//         }
//         solve(root->left);
//         ans.push_back(root->val);
//         solve(root->right);
//         return;
//     }
//     int n;
//     BSTIterator(TreeNode* root) {
//         solve(root);
//         reverse(ans.begin() , ans.end());
//         n = ans.size();
//     }
//     int next() {
//         n--;
//         return ans[n];
//     }
    
//     bool hasNext() {
//         if(n<=0){
//             return false;
//         }
//         return true;
//     }
    
    
    
    
    // Now here comes the space complexity where we solve it in O(H)
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        while(root){
            st.push(root);
            root = root->left;
        }
    }
    int next() {
        auto top = st.top();
        st.pop();
        if(top->right){
            TreeNode* right = top->right;
            while(right){
                st.push(right);
                right = right->left;
            }
        }
        return top->val;
    }
    
    bool hasNext() {
        return st.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */