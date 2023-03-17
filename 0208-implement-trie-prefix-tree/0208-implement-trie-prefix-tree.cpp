struct Node{
    Node* links[26];
    bool flag=false;
    
    bool contains(char ch){
        return links[ch-'a'] != NULL;
    }
    
    void setEnd(){
        flag = true;
    }
    
    bool isEnd(){
        return flag;
    }
    
    void put(char ch , Node* node){
        links[ch-'a'] = node;
    }
    
    Node* get(char ch){
        return links[ch-'a'];
    }
};
class Trie {
    private:
    Node *root;
public:
    
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        int n = word.length();
        for(int i=0;i<n;i++){
            if(!node->contains(word[i])){
                node->put(word[i] , new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        int n = word.length();
        for(int i=0;i<n;i++){
            if(!node->contains(word[i])){
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        int n = prefix.length();
        for(int i=0;i<n;i++){
            if(!node->contains(prefix[i])){
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */