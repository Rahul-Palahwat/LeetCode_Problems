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
    
    // my approach
        
    // void reve(vector<int> v, ListNode* head){
    //     reverse(v.begin(),v.end());
    //     for(auto it: v){
    //         head->val = it;
    //         head=head->next;   
    //     }
    //     return;
    // }
    // ListNode* reverseKGroup(ListNode* head, int k) {
    //     int i=0;
    //     ListNode *ans=head,*temp=head;
    //     vector<int> v;
    //     while(ans){
    //         i++;
    //         v.push_back(ans->val);
    //         if(i==k){
    //             // cout<<i<<" "<<ans->val<<" "<<temp->val<<endl;
    //             reve(v,temp);
    //             v.clear();
    //             if(ans->next != NULL)
    //             temp=ans->next;
    //             i=0;
    //         }
    //         ans=ans->next;
    //     }
    //     return head;
    // }
    
    // striver's approach 
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || k==1){
            return head;
        }
        ListNode *dummy = new ListNode(0);
        ListNode *cur=dummy , *nex=dummy , *pre=dummy;
        dummy->next = head;
        int count=0;
        
        while(cur->next != NULL){
            cur=cur->next;
            count++;
        }
        
        while(count>=k){
            cur = pre->next;
            nex = cur->next;
            for(int i=1;i<k;i++){
                cur->next = nex->next;
                nex->next = pre->next;
                pre->next=nex;
                nex = cur->next;
            }
            pre=cur;
            count-=k;
        }
        return dummy->next;
    }
};