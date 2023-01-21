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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& q) {
        vector<int> ans(q.size(),0);
        Trie t;
        sort(nums.begin(),nums.end());
        // for(auto it: nums){
        //     t.insert(it);
        // }
        map<pair<int,int> , int> mp;
        for(int i=0;i<q.size();i++){
            // ans.push_back(t.findMax(it[0]));
            mp[{q[i][1] , i}] = q[i][0];
        }
        int i=0;
        int flag=0;
        for(auto it: mp){
            int hi = it.first.first;
            while(nums[i] <= hi && i<nums.size()){
                flag=1;
                t.insert(nums[i]);
                i++;
            }
            if(flag==0){
                ans[it.first.second] = -1;
            }else{
                ans[it.first.second] = t.findMax(it.second);
            }
            
        }
        return ans;
    }
};