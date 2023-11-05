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
    ListNode* reverse(ListNode* head){
        ListNode *curr = head , *prev = NULL;
        while(curr){
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    bool check(ListNode* f, ListNode* e){
        while(e && f){
            if(f->val != e->val){
                return false;
            }
            e = e->next;
            f = f->next;
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        
        if(head == NULL || head->next == NULL){
            return true;
        }
        if(head->next->next == NULL){
            return head->val == head->next->val;
        }
        // First we will find the middle , then reverse the part after middle
        // Take a dummy pointer at head and start cmp with dummy and reversed
        // Then reverse it back 
        ListNode *f = head, *s = head;
        bool ans = false;
        while(f && f->next && f->next->next){
            s = s->next;
            f = f->next->next;
        }
        ListNode *mid = s;
        mid->next = reverse(mid->next);
        f = head;
        if(check(f , mid->next)){
            ans = true;
        }
        mid = s;
        mid->next = reverse(mid->next);
        return ans;
    }
};