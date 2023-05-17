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
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> ans;
        ListNode* temp = head;
        while(temp){
            ans.push_back(temp->val);
            temp = temp->next;
        }
        int i=0 , n = ans.size()-1 , maxi = INT_MIN;
        while(i<n){
            maxi = max(maxi , ans[i]+ans[n]);
            i++;
            n--;
        }
        return maxi;
    }
};