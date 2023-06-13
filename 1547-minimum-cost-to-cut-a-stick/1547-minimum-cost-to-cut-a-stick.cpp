class Solution {
public:
    int solve(vector<int> &cuts , int i , int j, vector<vector<int>> &dp){
        if(i > j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int mini = INT_MAX;
        for(int k=i;k<=j;k++){
            int cost = cuts[j+1]-cuts[i-1]+solve(cuts , i , k-1 , dp)+solve(cuts , k+1 , j , dp);
            mini = min(mini , cost);
        }
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.push_back(0);
        sort(cuts.begin() , cuts.end());
        int sz = cuts.size();
        vector<vector<int>> dp(sz , vector<int>(sz , -1));
        return solve(cuts , 1 , sz-2 , dp);
    }
};