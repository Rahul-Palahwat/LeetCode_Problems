// class LRUCache {
// public:
//     class Node{
//         public:
//         int key;
//         int val;
//         Node* prev;
//         Node* next;
//         Node(int _key , int _val){
//             key = _key;
//             val = _val;
//         }
//     };
    
    
//     Node* head = new Node(-1,-1);
//     Node* tail = new Node(-1,-1);
    
//     int cap;
//     unordered_map<int, Node*> mp;
    
    
    
//     LRUCache(int capacity) {
//         cap = capacity;
//         head->next = tail;
//         tail->prev = head;
//     }
    
//     void addNode(Node* newNode){
//         Node* temp = head->next;
//         newNode->next = temp;
//         newNode->prev = head;
//         temp->prev = newNode;
//         head->next = newNode;
//     }
    
//     void deleteNode(Node* delNode){
//         Node* back = delNode->prev;
//         Node* front = delNode->next;
//         back->next = front;
//         front->prev = back;
//     }
    
//     int get(int key) {
//         if(mp.find(key) != mp.end()){
//             Node* resNode = mp[key];
//             int res = resNode->val;
//             mp.erase(key);
//             deleteNode(resNode);
//             addNode(resNode);
//             mp[key] = head->next;
//             return res;
//         }else{
//             return -1;
//         }
        
//     }
    
//     void put(int key, int value) {
//         if(mp.find(key) != mp.end()){
//             Node* existing = mp[key];
//             mp.erase(key);
//             deleteNode(existing);
//         }
//         if(mp.size() == cap){
//             mp.erase(tail->prev->val);
//             deleteNode(tail->prev);
//         }
//         addNode(new Node(key , value));
//         mp[key] = head->next;
//     }
// };

// /**
//  * Your LRUCache object will be instantiated and called as such:
//  * LRUCache* obj = new LRUCache(capacity);
//  * int param_1 = obj->get(key);
//  * obj->put(key,value);
//  */




class LRUCache {
public:
    class node {
        public:
            int key;
            int val;
            node* next;
            node* prev;
        node(int _key, int _val) {
            key = _key;
            val = _val; 
        }
    };
    
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    
    int cap;
    unordered_map<int, node*>m;
    
    LRUCache(int capacity) {
        cap = capacity;    
        head->next = tail;
        tail->prev = head;
    }
    
    void addnode(node* newnode) {
        node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }
    
    void deletenode(node* delnode) {
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    
    int get(int key_) {
        if (m.find(key_) != m.end()) {
            node* resnode = m[key_];
            int res = resnode->val;
            m.erase(key_);
            deletenode(resnode);
            addnode(resnode);
            m[key_] = head->next;
            return res; 
        }
    
        return -1;
    }
    
    void put(int key_, int value) {
        if(m.find(key_) != m.end()) {
            node* existingnode = m[key_];
            m.erase(key_);
            deletenode(existingnode);
        }
        if(m.size() == cap) {
          m.erase(tail->prev->key);
          deletenode(tail->prev);
        }
        
        addnode(new node(key_, value));
        m[key_] = head->next; 
    }
};