class LRUCache {
public:
    struct Node{
        int key;
        int val;
        Node* left , *right;
        Node(int k , int v){
            key = k;
            val = v;
            left = NULL;
            right = NULL;
        }
    };
    
    
    int sz;
    Node *start = new Node(-1 , -1);
    Node *end = new Node(-1 , -1);
    map<int,Node*> mp;
    
    
    LRUCache(int capacity) {
        sz = capacity;
        start->right = end;
        end->left = start;
    }
    
    void deleteNode(Node* node){
        node->left->right = node->right;
        node->right->left = node->left;
        mp.erase(node->key);
    }
    
    void addNode(Node* node){
        Node *next = start->right;
        start->right = node;
        node->right = next;
        next->left = node;
        node->left = start;
        mp[node->key] = node;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            Node* node = mp[key];
            deleteNode(node);
            addNode(node);
            return mp[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* temp = mp[key];
            temp->val = value;
            deleteNode(temp);
            addNode(temp);
            return;
        }
        if(mp.size() == sz){
            mp.erase(end->left->key);
            deleteNode(end->left);
        }
        Node *newNode = new Node(key , value);
        addNode(newNode);
        mp[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */