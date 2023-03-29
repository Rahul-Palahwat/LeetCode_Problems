class Solution {
public:
    int solve(int index , int time , vector<int>& sat, int dp[][500]){
        if(index == sat.size()){
            return 0;
        }
        if(dp[index][time] != -1){
            return dp[index][time];
        }
        int skip = solve(index+1 , time , sat ,dp);
        int taken =sat[index]*time + solve(index+1 , time+1 , sat ,dp);
        return dp[index][time] = max(skip , taken);
    }
    int maxSatisfaction(vector<int>& sat) {
        sort(sat.begin() , sat.end());
        int n = sat.size();
        int dp[500][500];
        memset(dp , -1 , sizeof(dp));
        return solve(0 , 1 , sat,dp);
        // for(auto it: dp){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        // return dp[0][0];
    }
};