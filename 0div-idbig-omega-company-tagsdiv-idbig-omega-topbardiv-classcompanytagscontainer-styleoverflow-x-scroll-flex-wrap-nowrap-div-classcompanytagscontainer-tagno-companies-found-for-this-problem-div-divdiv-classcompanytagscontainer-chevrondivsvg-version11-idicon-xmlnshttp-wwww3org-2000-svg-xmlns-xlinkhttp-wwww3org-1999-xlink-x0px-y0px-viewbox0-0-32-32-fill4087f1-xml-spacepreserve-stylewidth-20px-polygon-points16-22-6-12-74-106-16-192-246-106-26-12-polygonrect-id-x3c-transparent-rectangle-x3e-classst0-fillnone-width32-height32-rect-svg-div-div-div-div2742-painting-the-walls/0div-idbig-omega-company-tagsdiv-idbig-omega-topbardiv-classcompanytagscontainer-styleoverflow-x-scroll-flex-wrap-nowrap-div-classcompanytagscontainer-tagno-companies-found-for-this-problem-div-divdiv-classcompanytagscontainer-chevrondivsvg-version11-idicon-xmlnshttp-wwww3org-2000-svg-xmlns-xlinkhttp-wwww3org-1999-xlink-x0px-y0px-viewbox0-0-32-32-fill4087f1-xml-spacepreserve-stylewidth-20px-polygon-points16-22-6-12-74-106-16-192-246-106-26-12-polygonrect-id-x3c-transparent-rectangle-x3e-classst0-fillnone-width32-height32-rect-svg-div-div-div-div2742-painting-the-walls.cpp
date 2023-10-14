class Solution {
public:
    int solve(int index, vector<pair<int,int>> &v, int t){
        int n = v.size();
        if(index >= n){
            if(t >= 0){
                return 0;
            }
            return 1e6;
        }
        int ans = v[index].first + solve(index+1 , v , max(v[index].second , t-1));
        if(t > 0){
            ans = min(ans , solve(index+1 , v , t-1));
        }
        return ans;
    }
    static bool cmp(pair<int,int> p1 , pair<int,int> p2){
        if(p1.second <= p2.second){
            return true;
        }
        return p1.second>p2.second;
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<int> dp(n + 1, 1e9);
        dp[0] = 0;
        for (int i = 0; i < n; ++i)
            for (int j = n; j > 0; --j)
                dp[j] = min(dp[j], dp[max(j - time[i] - 1, 0)] + cost[i]);
        return dp[n];
    }
};