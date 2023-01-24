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
    priority_queue<pair<int , ListNode*> , vector<pair<int,ListNode*>> , greater<pair<int,ListNode*>>> pq;
    ListNode* solve(){
        ListNode* node = NULL;
        node = pq.top().second;
        pq.pop();
        ListNode* temp = node;
        while(pq.size() > 0){
            node->next = pq.top().second;
            pq.pop();
            node=node->next;
        }
        node->next = NULL;
        return temp;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for(auto it: lists){
            while(it){
                pq.push({it->val ,it});
                it=it->next;
            }
        }
        if(pq.size() == 0){
            return NULL;
        }
        return solve();
    }
};