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
    void reve(vector<int> v, ListNode* head){
        reverse(v.begin(),v.end());
        for(auto it: v){
            head->val = it;
            head=head->next;   
        }
        return;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int i=0;
        ListNode *ans=head,*temp=head;
        vector<int> v;
        while(ans){
            i++;
            v.push_back(ans->val);
            if(i==k){
                cout<<i<<" "<<ans->val<<" "<<temp->val<<endl;
                reve(v,temp);
                v.clear();
                if(ans->next != NULL)
                temp=ans->next;
                i=0;
            }
            ans=ans->next;
        }
        return head;
    }
};