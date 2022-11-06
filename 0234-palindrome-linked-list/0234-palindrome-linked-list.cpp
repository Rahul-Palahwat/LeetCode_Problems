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
    // brute force approach 
    // vector<int> ans;
    // void solve(ListNode* root){
    //     while(root){
    //         ans.push_back(root->val);
    //         root = root->next;
    //     }
    //     return;
    // }
    // bool isPalindrome(ListNode* head) {
    //     solve(head);
    //     int i=0,j=ans.size()-1;
    //     while(i<j){
    //         if(ans[i] != ans[j]){
    //             return false;
    //         }
    //         i++;
    //         j--;
    //     }
    //     return true;
    // }

    // using stack 
    bool isPalindrome(ListNode* head) {
        if(!head){
            return true;
        }
        if(head->next == NULL){
            return true;
        }
        if(head->next->next == NULL){
            if(head->val == head->next->val){
                return true;
            }
            return false;
        }
        ListNode *s,*f;
        stack<int> st;
        s=head;
        f=head;
        while(f->next != NULL && f->next->next != NULL){
            st.push(s->val);
            s=s->next;
            f=f->next->next;
        }
        if(f->next != NULL){
            st.push(s->val);
            s=s->next;
            while(s!=NULL){
                if(st.top() == s->val){
                    st.pop();
                }
                s=s->next;
            }
        }else{
            // st.pop();
            s=s->next;
            while(s!=NULL){
                if(st.top() == s->val){
                    st.pop();
                }
                s=s->next;
            }
        }
        if(st.empty()){
            return true;
        }
        return false;
    }

    // One more approach can be by reversing list after slow pointer
};