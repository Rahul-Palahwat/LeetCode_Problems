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
    ListNode* rotateRight(ListNode* head, int k) {
        int len = 0;
        ListNode *temp = head;
        if(!head || head->next == NULL){
            return head;
        }
        while(temp){
            len++;
            temp = temp->next;
        }
        int mod = k%len;
        if(mod == 0){
            return head;
        }
        int go = len - mod;
        temp = head;
        while(go > 1){
            go--;
            temp = temp->next;
        }
        ListNode *ans = temp->next;
        temp->next = NULL;
        temp = ans;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = head;
        return ans;
    }
};