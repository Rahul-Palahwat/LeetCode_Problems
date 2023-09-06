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
    // vector<ListNode*> splitListToParts(ListNode* head, int k) {
    //     vector<ListNode*> ans;
    //     ListNode *node = head;
    //     int sz = 0;
    //     while(node){
    //         sz++;
    //         node = node->next;
    //     }
    //     int parts = sz/k;
    //     node = head;
    //     if(parts > 1 || (parts == 1 && sz%k != 0)){
    //         int mod = sz%k;
    //         cout<<mod<<" mod"<<sz<<endl;
    //         int size = 0;
    //         ans.push_back(node);
    //         while(k-- && node){
    //             size++;
    //             if(size == parts){
    //                 if(mod > 0){
    //                     node = node->next;
    //                     mod--;
    //                 }
    //                 ListNode *temp = NULL;
    //                 if(node)
    //                     temp = node->next;
    //                 node->next = NULL;
    //                 node = temp;
    //                 size = 1;
    //                 ans.push_back(node);
    //                 // continue;
    //             }
    //             node = node->next;
    //         }
    //     }else{
    //         while(k--){
    //             if(!node){
    //                 ans.push_back(NULL);
    //                 continue;
    //             }
    //             ans.push_back(node);
    //             ListNode* temp = node->next;
    //             node->next = NULL;
    //             node = temp;
    //         }
    //     }
    //     return ans;
    // }
    
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> parts(k, nullptr);
        int len = 0;
        for (ListNode* node = root; node; node = node->next)
            len++;
        int n = len / k, r = len % k; // n : minimum guaranteed part size; r : extra nodes spread to the first r parts;
        ListNode* node = root, *prev = nullptr;
        for (int i = 0; node && i < k; i++, r--) {
            parts[i] = node;
            for (int j = 0; j < n + (r > 0); j++) {
                prev = node;
                node = node->next;
            }
            prev->next = nullptr;
        }
        return parts;
    }
};