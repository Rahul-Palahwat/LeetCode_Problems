class Solution {
public:
    int solve(int start, int end, vector<int> &cuts, vector<vector<int>> &dp){
        if(start>end){
            return 0;
        }
        if(dp[start][end] != -1){
            return dp[start][end];
        }
        int ans = INT_MAX;
        for(int i = start;i<=end;i++){
            int temp = cuts[end+1]-cuts[start-1];
            temp+=solve(start , i-1 , cuts , dp);
            temp+=solve(i+1 , end , cuts , dp);
            ans = min(ans , temp);
        }
        return dp[start][end] = ans;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        int sz = cuts.size();
        sort(cuts.begin() , cuts.end());
        vector<vector<int>> dp(sz+1 , vector<int>(sz+1 , -1));
        return solve(1 , sz-2  , cuts , dp);
    }
};