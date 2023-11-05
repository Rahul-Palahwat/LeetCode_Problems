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
    
    // BruteForce approach
    // ListNode *detectCycle(ListNode *head) {
    //     if(!head){
    //         return NULL;
    //     }
    //     unordered_map<ListNode*,int> mp;
    //     while(head){
    //         if(mp.find(head) == mp.end()){
    //             mp[head]=1;
    //         }else{
    //             return head;
    //         }
    //         head = head->next;
    //     }
    //     return NULL;
    // }
    
    
    
    
    ListNode *detectCycle(ListNode *head) {
        if(!head){
            return NULL;
        }
        ListNode *slow = head, *fast = head;
        do{
            if(fast == NULL || fast->next == NULL){
                return NULL;
            }
            slow = slow->next;
            fast = fast->next->next;
        }while(slow != fast);
        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};