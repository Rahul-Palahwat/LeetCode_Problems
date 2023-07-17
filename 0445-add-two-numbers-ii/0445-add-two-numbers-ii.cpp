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
    ListNode* reverse(ListNode* l){
        ListNode* node = l;
        ListNode* prev = nullptr;
        while(node){
            ListNode* temp = node->next;
            node->next = prev;
            prev = node;
            node = temp;
        }
        return prev;
    }
    ListNode* merge(ListNode* l1 , ListNode* l2){
        ListNode* node = l1;
        ListNode* prev = nullptr;
        int carry = 0;
        while(l1 && l2){
            int sum = l1->val + l2->val + carry;
            carry = sum/10;
            sum%=10;
            l1->val = sum;
            prev = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            int sum = l1->val + carry;
            carry = sum/10;
            sum%=10;
            l1->val = sum;
            prev = l1;
            l1 = l1->next;
        }
        while(l2){
            int sum = l2->val + carry;
            carry = sum/10;
            sum%=10;
            prev->next = new ListNode(sum);
            prev = prev->next;
            l2 = l2->next;
        }
        if(carry > 0){
            prev->next = new ListNode(carry);
        }
        return node;
        
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        l1 = merge(l1 , l2);
        return reverse(l1);
    }
};