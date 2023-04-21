class Solution {
public:
    // int ans = 0;
    // map<vector<int> , int> mp1;
    // void solve(int n , int mini , vector<int>& g , vector<int>& p , int i , vector<int> temp){
    //     if(i >= p.size()){
    //         if(mini <= 0){
    //             if(mp1.find(temp) == mp1.end()){
    //                 // for(auto it: temp){
    //                 //     cout<<it<<" ";
    //                 // }
    //                 // cout<<endl;
    //                 // cout<<mini<<endl;
    //                 ans++;
    //                 mp1[temp]=1;
    //             }
    //         }
    //         return;
    //     }
    //     if(n>=g[i]){
    //         temp.push_back(i);
    //         solve(n-g[i] , mini-p[i] , g , p , i+1 , temp);
    //         temp.pop_back();
    //     }
    //     solve(n , mini , g , p , i+1 , temp);
    //     return;
    // }
    // int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
    //     vector<int> temp;
    //     solve(n , minProfit , group , profit , 0 , temp);
    //     return ans;
    // }
    
    
    
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int MOD = 1000000007;
        vector<vector<int>> dp(minProfit + 1, vector<int>(n + 1));
        dp[0][0] = 1;
        for (int k = 0; k < group.size(); k++) {
            int g = group[k], p = profit[k];
            for (int i = minProfit; i >= 0; i--) {
                for (int j = n - g; j >= 0; j--) {
                    int newProfit = min(i + p, minProfit);
                    dp[newProfit][j + g] += dp[i][j];
                    dp[newProfit][j + g] %= MOD;
                }
            }
        }
        int sum = 0;
        for (int i = 0; i <= n; i++) {
            sum += dp[minProfit][i];
            sum %= MOD;
        }
        return sum;
    }
};