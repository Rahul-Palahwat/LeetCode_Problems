class Solution {
public:
    int mod = 1e9+7;
    vector<vector<int>> dp;
    int helper(int i, int steps, int &n){
        if(i==n || i<0)
            return 0;
        if(steps==0)
            return i==0;
        if(dp[i][steps]!=-1)
            return dp[i][steps];
        
        long long res = 0;
        res += helper(i - 1, steps - 1, n);
        res += helper(i, steps - 1, n);
        res += helper(i + 1, steps - 1, n);
        res %= mod;
        
        return dp[i][steps] = res;
    }
    
    int numWays(int steps, int arrLen) {
        int size = min(steps+1, arrLen);
        dp.resize(size, vector<int>(steps+1, -1));
        int res = helper(0, steps, arrLen);
        return res;
    }
};