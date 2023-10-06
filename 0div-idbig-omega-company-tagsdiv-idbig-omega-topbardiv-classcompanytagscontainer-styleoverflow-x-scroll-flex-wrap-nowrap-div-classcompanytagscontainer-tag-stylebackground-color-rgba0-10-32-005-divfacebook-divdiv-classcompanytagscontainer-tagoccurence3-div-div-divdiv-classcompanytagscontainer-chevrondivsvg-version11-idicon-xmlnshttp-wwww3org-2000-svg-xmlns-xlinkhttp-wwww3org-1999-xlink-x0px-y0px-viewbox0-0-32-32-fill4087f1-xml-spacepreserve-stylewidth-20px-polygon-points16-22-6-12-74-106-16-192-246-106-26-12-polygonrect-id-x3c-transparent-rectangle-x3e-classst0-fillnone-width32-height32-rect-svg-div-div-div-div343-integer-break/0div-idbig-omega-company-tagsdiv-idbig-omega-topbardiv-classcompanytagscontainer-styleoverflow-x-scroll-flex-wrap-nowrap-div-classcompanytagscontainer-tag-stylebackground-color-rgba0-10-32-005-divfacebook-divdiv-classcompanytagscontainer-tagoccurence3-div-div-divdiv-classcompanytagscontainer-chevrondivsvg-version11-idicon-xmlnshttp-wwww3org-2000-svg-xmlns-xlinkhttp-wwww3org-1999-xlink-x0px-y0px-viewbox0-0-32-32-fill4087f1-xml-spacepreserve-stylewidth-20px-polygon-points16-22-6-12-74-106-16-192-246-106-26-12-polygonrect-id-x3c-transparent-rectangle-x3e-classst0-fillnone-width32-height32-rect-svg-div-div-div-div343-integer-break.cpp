class Solution {
public:
    unordered_map<int,int> mp;
    int solve(int n){
        int ans = 0;
        if(n==0 || n==1){
            return 1;
        }
        if(mp.find(n) != mp.end()){
            return mp[n];
        }
        for(int i=1;i<=n;i++){
            ans = max(ans , i*solve(n-i));
        }
        return mp[n] = ans;
    }
    int integerBreak(int n) {
        int ans = 0;
        for(int i=1;i<n;i++){
            int temp = i*solve(n-i);
            ans = max(ans , temp);
        }
        return ans;
    }
};