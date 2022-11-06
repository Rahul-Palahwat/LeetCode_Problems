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
        if(head== NULL || head->next == NULL || k==0){
            return head;
        }
        int count=0;
        ListNode* temp = head;
        vector<int> v;
        while(temp){
            v.push_back(temp->val);
            count++;
            temp=temp->next;
        }
        k=(k%count);
        k=count-k;
        rotate(v.begin(),v.begin()+k,v.end());
        temp=head;
        int i=0;
        while(temp){
            temp->val = v[i];
            temp=temp->next;
            i++;
        }
        return head;
    }
};