class Solution {
public:
//     vector<string> ans;
//     struct Node{
//         Node* links[26];
//         int count=0;
        
//         bool contains(char c){
//             return links[c-'a'] != NULL;
//         }
        
//         void put(char c , Node* node){
//             links[c-'a'] = node;
//         }
        
//         Node* get(char c){
//             return links[c-'a'];
//         }
        
//         void increaseCount(){
//             count++;
//         }
        
//         int getCount(){
//             return count;
//         }
        
//     };
//     class Trie{
//         private:
//         Node* root;
//         public:
//         Trie(){
//             root = new Node();
//         }
//         void insert(string s){
//             Node* node = root;
//             int flag=0,check=0;
//             for(auto it: s){
//                 if(!node->contains(it)){
//                     node->put(it , new Node());
//                 }
//                 // if(node->getCount() >= 1){
//                 //     flag=1;
//                 // }
//                 node = node->get(it);
//                 node->increaseCount();
//                 // if(node->getCount() == 1 && flag==1 && check==0){
//                 //     ans.push_back(s);
//                 //     check = 1;
//                 // }
//             }
//         }
//         bool findAns(string s){
//             Node* node = root;
//             int flag=0;
//             for(auto it: s){
//                 node = node->get(it);
//                 if(node->getCount() >= 2){
//                     cout<<s<<" s "<<node->getCount()<<" count "<<it<<endl;
//                     flag=1;
//                 }
//                 if((flag == 1) && (node->getCount() == 1)){
//                     return true;
//                 }
                
//             }
//             return false;
//         }
//     };
//     vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
//         Trie t;
//         for(auto it: words){
//             t.insert(it);
//         }
//         for(auto it: words){
//             if(t.findAns(it)){
//                 ans.push_back(it);
//             }
//         }
//         return ans;
//     }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> words_set;
        for (string word : words) words_set.insert(word);
        vector<string> res;
    
        for (string word : words) {
            int n = word.size();
            vector<int> dp(n + 1, 0);
            dp[0] = 1;
            for (int i = 0; i < n; i++) {
                if (!dp[i]) continue;
                for (int j = i + 1; j <= n; j++) {
                    if (j - i < n && words_set.count(word.substr(i, j - i))) {
                        dp[j] = 1;
                    }
                }
                if (dp[n]) {
                    res.push_back(word);
                    break;
                }
            }
        }
        return res;
    }
};