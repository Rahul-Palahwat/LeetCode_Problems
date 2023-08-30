/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* node = head;
        while(node){
            if(node->child){
                Node *temp = node->next;
                node->child->prev = node;
                node->next = flatten(node->child);
                node->child = nullptr;
                while(node->next){
                    node = node->next;
                }
                node->next = temp;
                if (temp) {
                    temp->prev = node; // Add this condition to avoid null pointer access
                }
            }
            node = node->next;
        }
        return head;
    }
};