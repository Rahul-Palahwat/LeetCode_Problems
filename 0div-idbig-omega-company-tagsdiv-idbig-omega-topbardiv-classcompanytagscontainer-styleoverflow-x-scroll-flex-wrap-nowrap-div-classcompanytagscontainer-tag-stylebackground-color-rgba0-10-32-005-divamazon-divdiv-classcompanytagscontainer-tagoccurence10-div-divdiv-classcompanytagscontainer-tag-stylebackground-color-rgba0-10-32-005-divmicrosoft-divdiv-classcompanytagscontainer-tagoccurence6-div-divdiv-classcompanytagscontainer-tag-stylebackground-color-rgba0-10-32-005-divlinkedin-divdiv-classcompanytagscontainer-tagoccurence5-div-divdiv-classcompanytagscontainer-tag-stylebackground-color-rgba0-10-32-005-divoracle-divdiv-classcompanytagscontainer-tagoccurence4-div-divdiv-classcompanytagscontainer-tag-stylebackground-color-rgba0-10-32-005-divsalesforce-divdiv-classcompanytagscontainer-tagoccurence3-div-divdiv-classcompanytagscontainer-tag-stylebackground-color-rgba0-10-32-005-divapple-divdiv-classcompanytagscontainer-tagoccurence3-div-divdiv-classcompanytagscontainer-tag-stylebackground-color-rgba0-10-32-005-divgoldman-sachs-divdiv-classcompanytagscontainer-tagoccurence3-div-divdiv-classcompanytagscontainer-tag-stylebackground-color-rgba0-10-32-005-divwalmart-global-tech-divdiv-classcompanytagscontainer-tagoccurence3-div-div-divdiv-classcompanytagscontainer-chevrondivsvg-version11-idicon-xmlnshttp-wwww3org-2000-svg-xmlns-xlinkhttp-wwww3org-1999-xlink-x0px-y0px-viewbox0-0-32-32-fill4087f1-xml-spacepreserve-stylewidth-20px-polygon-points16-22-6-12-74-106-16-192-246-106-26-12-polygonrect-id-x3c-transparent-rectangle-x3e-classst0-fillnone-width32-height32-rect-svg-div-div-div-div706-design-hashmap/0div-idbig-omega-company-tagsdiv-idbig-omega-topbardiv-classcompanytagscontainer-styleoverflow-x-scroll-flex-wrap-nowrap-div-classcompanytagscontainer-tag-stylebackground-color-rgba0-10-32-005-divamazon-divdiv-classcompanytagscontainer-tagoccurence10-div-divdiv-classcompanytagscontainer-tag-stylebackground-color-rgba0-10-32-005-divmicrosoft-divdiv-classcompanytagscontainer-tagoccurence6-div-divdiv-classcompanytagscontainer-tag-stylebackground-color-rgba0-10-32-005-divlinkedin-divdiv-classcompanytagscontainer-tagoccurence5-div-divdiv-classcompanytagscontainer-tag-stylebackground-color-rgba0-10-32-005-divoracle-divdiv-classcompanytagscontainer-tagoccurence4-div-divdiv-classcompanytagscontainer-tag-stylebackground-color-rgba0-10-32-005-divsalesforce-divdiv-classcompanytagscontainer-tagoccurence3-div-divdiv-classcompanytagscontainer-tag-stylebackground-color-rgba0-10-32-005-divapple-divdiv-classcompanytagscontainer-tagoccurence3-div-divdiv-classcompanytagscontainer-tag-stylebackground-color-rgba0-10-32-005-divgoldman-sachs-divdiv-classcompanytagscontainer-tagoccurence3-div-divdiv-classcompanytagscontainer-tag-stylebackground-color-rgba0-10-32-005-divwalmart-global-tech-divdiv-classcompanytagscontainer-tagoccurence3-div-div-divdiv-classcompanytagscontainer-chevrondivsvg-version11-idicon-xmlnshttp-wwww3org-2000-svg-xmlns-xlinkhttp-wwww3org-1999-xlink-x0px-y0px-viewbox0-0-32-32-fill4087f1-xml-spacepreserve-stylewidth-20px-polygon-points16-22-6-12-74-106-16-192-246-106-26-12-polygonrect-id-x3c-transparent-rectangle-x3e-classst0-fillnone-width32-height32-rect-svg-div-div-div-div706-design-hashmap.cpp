class Node{
    public:
    int data;
    Node *prev;
    Node *next;
    Node(int val){
        this->data = val;
        prev=NULL;
        next = NULL;
    }
    void update(int val){
        this->data = val;
    }
    int getData(){
        return this->data;
    }
    void updateNext(Node *temp){
        this->next = temp;
    }
    void updatePrev(Node *temp){
        this->prev = temp;
    }
};
class MyHashMap {
public:
    Node *head;
    unordered_map<int, Node*> mp;
    MyHashMap() {
        head = NULL;
    }
    
    void put(int key, int value) {
        if(mp.find(key) == mp.end()){
            Node *temp = new Node(value);
            temp->next = head;
            if(head){
                head->prev = temp;
            }
            mp[key] = temp;
        }else{
            Node *temp = mp[key];
            temp->update(value);
        }
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            return mp[key]->getData();
        }
        return -1;
    }
    
    void remove(int key) {
        if(mp.find(key) != mp.end()){
            Node *temp = mp[key];
            if(temp->prev == NULL){
                if(head){
                    head = head->next;
                }
            }else{
                temp->prev->next = temp->next;
                if(temp->next)
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