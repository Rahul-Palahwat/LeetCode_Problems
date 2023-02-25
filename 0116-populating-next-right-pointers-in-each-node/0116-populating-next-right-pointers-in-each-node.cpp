/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if(!root){
            return root;
        }
        q.push(root);
        while(!q.empty()){
            int t = q.size();
            for(int i=0;i<t;i++){
                Node* top = q.front();
                if(i == t-1){
                    top->next = NULL;
                    q.pop();
                }else{
                    q.pop();
                    top->next = q.front();
                }
                if(top->left){
                    q.push(top->left);
                }
                if(top->right){
                    q.push(top->right);
                }
            }
        }
        return root;
    }
};