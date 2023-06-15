class Solution {
public:
    // Recursion + Memoization
    // int solve(int i, int k , vector<int>& arr , vector<int> &dp){
    //     if(i == arr.size()){
    //         return 0;
    //     }
    //     if(dp[i] != -1){
    //         return dp[i];
    //     }
    //     int ans = INT_MIN;
    //     int j=0,maxi = arr[i];
    //     for(int index=i;index<arr.size() && j<k;index++){
    //         maxi = max(maxi , arr[index]);
    //         int temp = (index+1-i)*maxi + solve(index+1 , k , arr , dp);
    //         // cout<<temp<<" "<<i<<endl;
    //         ans = max(ans , temp);
    //         j++;
    //     }
    //     return dp[i] = ans;
    // }
    // int maxSumAfterPartitioning(vector<int>& arr, int k) {
    //     int n = arr.size();
    //     vector<int> dp(n , -1);
    //     return solve(0 , k , arr , dp);
    // }
    
    
    
    // Tabulation
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1 , 0);
        for(int i=n-1;i>=0;i--){
            int ans = INT_MIN;
            int j=0,maxi = arr[i];
            for(int index=i;index<arr.size() && j<k;index++){
                maxi = max(maxi , arr[index]);
                int temp = (index+1-i)*maxi + dp[index+1];
                // cout<<temp<<" "<<i<<endl;
                ans = max(ans , temp);
                j++;
            }
            dp[i] = ans;
        }
        return dp[0];
    }
};