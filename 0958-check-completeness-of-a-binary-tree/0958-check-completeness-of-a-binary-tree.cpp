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
     bool isCompleteTree(TreeNode* root) {
        vector<TreeNode*> bfs;
        bfs.push_back(root);
        int i = 0;
        while (i < bfs.size() && bfs[i]) {
            bfs.push_back(bfs[i]->left);
            bfs.push_back(bfs[i]->right);
            i++;
        }
        while (i < bfs.size() && !bfs[i])
            i++;
        return i == bfs.size();
    }
    // bool isCompleteTree(TreeNode* root) {
    //     queue<TreeNode*> q;
    //     int i = 0;
    //     int flag=0;
    //     q.push(root);
    //     while(!q.empty()){
    //         int sz = q.size();
    //         int pw = pow(2,i);
    //         i++;
    //         if(flag==0 && sz != pw){
    //             cout<<"Hello1 "<<sz<<" "<<pw<<endl;
    //             return false;
    //         }
    //         if(flag == 2){
    //             cout<<"Hello2"<<endl;
    //             return false;
    //         }
    //         if(flag==1){
    //             flag++;
    //         }
    //         while(sz--){
    //             auto top = q.front();
    //             if((flag == 1) && (top->left || top->right)){
    //                 return false;
    //             }
    //             q.pop();
    //             if(!top->left && top->right){
    //                 cout<<"Hello3"<<endl;
    //                 return false;
    //             }
    //             if(top->left)
    //                 q.push(top->left);
    //             else
    //                 flag=1;
    //             if(top->right)
    //                 q.push(top->right);
    //             else
    //                 flag=1;
    //         }
    //     }
    //     return true;
    // }
};