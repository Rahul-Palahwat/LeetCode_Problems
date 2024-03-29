class Solution {
public:
    bool possible(string s1 , string s2){
        int i=0,j=0;
        int n = s1.size() , m = s2.size();
        if(n != m+1){
            return false;
        }
        for(int i=0;i<n && j<m;i++){
            if(s1[i] == s2[j]){
                j++;
            }
        }
        return (j == s2.size());
    }
    bool static comp(string &s1 , string &s2){
        return s1.size()<s2.size();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin() , words.end() , comp);
        int ans = 1;
        vector<int> dp(n , 1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(possible(words[i] , words[j])){
                    // cout<<words[i]<<" "<<words[j]<<endl;
                    dp[i] = max(dp[i] , 1+dp[j]);
                    ans = max(ans , dp[i]);
                }
            }
        }
        return ans;
    }
};