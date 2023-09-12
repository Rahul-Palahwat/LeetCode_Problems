class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int> mp;
        for(auto it: s){
            mp[it]++;
        }
        map<int,int, greater<int>> cnt;
        int maxi = 0;
        for(auto it: mp){
            cnt[it.second]++;
            // cout<<it.second<<" "<<cnt[it.second]<<endl;
            maxi = max(maxi , it.second);
        }
        int ans = 0;
        while(maxi > 0){
            if(cnt.find(maxi) != cnt.end()){
                int tt = cnt[maxi];
                // cout<<tt<<"tt"<<maxi<<endl;
                if(tt > 1){
                    ans+=(tt-1);
                    cnt[maxi-1]+=(tt-1);
                }
            }
            maxi--;
        }
        return ans;
    }
};