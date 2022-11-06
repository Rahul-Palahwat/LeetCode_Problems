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
    // Brute force approach 
    // ListNode *detectCycle(ListNode *head) {
    //     ListNode* temp = head;
    //     unordered_map<ListNode* , int> mp;
    //     while(temp){
    //         if(mp.find(temp) != mp.end()){
    //             return temp;
    //         }
    //         mp[temp]=1;
    //         temp=temp->next;
    //     }
    //     return NULL;
    // }
    
    // optimized using fast and slow pointer 
     ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head , *fast=head;
         int flag=0;
        while(fast && fast->next){
            if(flag==1 && slow == fast){
                // cout<<slow->val<<"slow"<<endl;
                ListNode* entry=head;
                while(entry != slow){
                    entry=entry->next;
                    slow=slow->next;
                }
                return entry;
            }
            flag=1;
            slow=slow->next;
            fast = fast->next->next;
        }
        return NULL;
    }
    
};