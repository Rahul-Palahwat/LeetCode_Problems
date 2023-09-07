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
    ListNode* reverse(ListNode *node){
        ListNode *prev = NULL , *temp = NULL;
        while(node){
            temp = node->next;
            node->next = prev;
            prev = node;
            node = temp;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *node = head, *prev = NULL , *next = NULL;
        int cnt = 0;
        while(node && cnt < left-1){
            prev = node;
            node = node->next;
            cnt++;
        }
        if(prev)
        prev->next = NULL;
        ListNode *start = node;
        while(node && cnt < right-1){
            node = node->next;
            cnt++;
        }
        if(node){
            next = node->next;
            node->next = NULL;
        }
        node = reverse(start);
        if(!prev){
            head = node;
            while(node->next){
                node = node->next;
            }
            node->next = next;
        }else{
            ListNode* temp = head;
            while(temp->next){
                temp = temp->next;
            }
            temp->next = node;
            while(node->next){
                node = node->next;
            }
            node->next = next;
        }
        return head;
    }
};