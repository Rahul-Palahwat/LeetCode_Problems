/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head){
            return NULL;
        }
        unordered_map<ListNode*,int> mp;
        while(head){
            if(mp.find(head) == mp.end()){
                mp[head]=1;
            }else{
                return head;
            }
            head = head->next;
        }
        return NULL;
    }
};