/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* solve(vector<int>& list , int l , int r){
        if(l>r){
            return NULL;
        }
        int mid = (l+r)/2;
        TreeNode* ans = new TreeNode(list[mid]);
        ans->left = solve(list , l , mid-1);
        ans->right = solve(list , mid+1 , r);
        return ans;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> list;
        while(head){
            list.push_back(head->val);
            head = head->next;
        }
        int r= list.size()-1;
        return solve(list ,0 , r);
        // TreeNode* ans = new TreeNode(list[mid]);
        // ans->left = solve(list , l , mid-1);
        // ans->right = solve(list , mid+1 , r);
        // return ans;
    }
};