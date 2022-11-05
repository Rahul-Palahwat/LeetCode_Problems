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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp = list1;
        int i=0;
        while(i<a-1){
            temp=temp->next;
            i++;
        }
        ListNode* bnext=temp->next;
        temp->next = list2;
        while(temp->next != NULL){
            temp=temp->next;
        }
        while(i<b-1){
            bnext=bnext->next;
            i++;
        }
        temp->next=bnext->next;
        return list1;
    }
};