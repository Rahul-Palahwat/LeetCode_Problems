class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string , int> mp , vis;
        for(auto it: wordList){
            mp[it]++;
        }
        queue<string> q;
        q.push(beginWord);
        int ans = 0;
        while(!q.empty()){
            int sz = q.size();
            ans++;
            while(sz--){
                auto top = q.front();
                q.pop();
                if(top == endWord){
                    return ans;
                }
                if(vis.find(top) != vis.end()){
                    continue;
                }
                vis[top] = 1;
                for(int i=0;i<top.size();i++){
                    for(int j=0;j<26;j++){
                        char ch = top[i];
                        top[i] = char('a'+j);
                        if(mp.find(top) != mp.end()){
                            q.push(top);
                        }
                        top[i] = ch;
                    }
                }
            }
        }
        return 0;
    }
};