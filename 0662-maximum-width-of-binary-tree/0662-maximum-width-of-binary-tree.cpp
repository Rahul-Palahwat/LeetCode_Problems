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
    
    // my previous solution 
    int widthOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }
        queue<pair<TreeNode* , long long>> q;
        q.push({root , 0});
        int ans = 0;
        while(!q.empty()){
            int t = q.size();
            long long start=0,end=0,flag=0;
            while(t--){
                TreeNode* node = q.front().first;
                int pos = q.front().second;
                if(flag==0){
                    // cout<<pos<<" start"<<endl;
                    start = pos;
                    flag=1;
                }
                if(t==0){
                    // cout<<end<<" end"<<endl;
                    end = pos;
                }
                q.pop();
                if(node->left){
                    q.push({node->left , 2*(pos-start)});
                }
                if(node->right){
                    q.push({node->right , 2*(pos-start)+1});
                }
            }
            int tt = (int)(end-start+1);
            ans = max(ans , tt);
        }
        return ans;
    }
    
    
    
    // Now my new solution 
    // int widthOfBinaryTree(TreeNode* root) {
    //     if(!root){
    //         return 0;
    //     }
    //     int ans = 0;
    //     queue<pair<TreeNode* , int>> q;
    //     q.push({root , 0});
    //     while(!q.empty()){
    //         int start , end;
    //         int sz = q.size();
    //         while(sz--){
    //             auto top = q.front();
    //             q.pop();
    //             if(top.first->left){
    //                 q.push({top.first->left , top.second-1});
    //             }
    //             if(top.first->right){
    //                 q.push({top.first->right , top.second+1});
    //             }
    //         }
    //     }
    // }
};