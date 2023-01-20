class Solution {
public:
    struct Node{
        Node* tries[2];
        
        bool contains(int bit){
            return tries[bit] != NULL;
        }
        
        void put(int bit , Node* node){
            tries[bit] = node;
        }
        
        Node* get(int bit){
            return tries[bit];
        }
    };
    class Trie{
        private:
        Node* root;
        public:
        Trie(){
            root = new Node();
        }
        
        void insert(int n){
            Node* node = root;
            for(int i=31;i>=0;i--){
                int bit = (n>>i)&1;
                if(!node->contains(bit)){
                    node->put(bit , new Node());
                }
                node = node->get(bit);
            }
        }
        
        int findMax(int n){
            Node* node = root;
            int maxi = 0;
            for(int i=31;i>=0;i--){
                int bit = (n>>i)&1;
                if(node->contains(1-bit)){
                    maxi = maxi | (1<<i);
                    node = node->get(1-bit);
                }else{
                    node = node->get(bit);
                }
            }
            return maxi;
        }
    };
    int findMaximumXOR(vector<int>& nums) {
        int ans = 0;
        Trie t;
        for(auto it: nums){
            t.insert(it);
        }
        for(auto it: nums){
            ans = max(ans , t.findMax(it));
        }
        return ans;
    }
};