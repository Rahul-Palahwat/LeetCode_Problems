class Solution {
public:
    int solve(string msg){
        int ans = 1;
        for(int i=0;i<msg.length();i++){
            if(msg[i] == ' '){
                ans++;
            }
        }
        return ans;
    }
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string,int> mp;
        for(int i=0;i<senders.size();i++){
            mp[senders[i]]+=solve(messages[i]);
        }
        vector<string> ans;
        int maxi = 0;
        for(auto it: mp){
            if(maxi < it.second){
                maxi = it.second;
            }
        }
        for(auto it: mp){
            if(it.second == maxi){
                ans.push_back(it.first);
            }
        }
        sort(ans.begin(),ans.end());
        // string finalans="";
        // int sz = 0;
        // for(auto it: ans){
        //     cout<<it<<" ";
        //     if(it.length() > sz){
        //         sz = it.length();
        //         finalans = it;
        //     }
        // }
        // cout<<endl;
        return ans[ans.size()-1];
    }
};