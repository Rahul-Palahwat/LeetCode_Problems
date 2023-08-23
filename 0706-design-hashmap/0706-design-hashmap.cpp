class MyHashMap {
public:
//     vector<int> v;
//     MyHashMap() {
//         v.resize(1e6+1 , -1);
//     }
    
//     void put(int key, int value) {
//         v[key] = value;
//     }
    
//     int get(int key) {
//         return v[key];
//     }
    
//     void remove(int key) {
//         v[key] = -1;
//     }
    
    
    
    class Node{
        public:
        int val;
        Node* next;
        Node* prev;
        Node(int v){
            val = v;
            next = NULL;
            prev = NULL;
        }
    };
    
    unordered_map<int, Node*> mp;
    Node* head;
    MyHashMap() {
        head = NULL;
    }
    
    void put(int key, int value) {
        if(mp.find(key) == mp.end()){
            Node* temp = head;
            Node* nn = new Node(value);
            nn->next = head;
            if(temp)
            temp->prev = nn;
            head = temp;
            mp[key] = nn;
        }else{
            Node* temp = mp[key];
            temp->val = value;
        }
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            return mp[key]->val;
        }
        return -1;
    }
    
    void remove(int key) {
        if(mp.find(key) != mp.end()){
            Node* temp = mp[key];
            if(temp->prev == NULL){
                if(head)
                head = head->next;
            }else{
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }
            mp.erase(key);
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */