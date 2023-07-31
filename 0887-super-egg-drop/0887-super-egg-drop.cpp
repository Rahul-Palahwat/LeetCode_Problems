class Solution {
public:

    int solve(int f , int egg , vector<vector<int>> &dp){
        if(egg <= 1){
            return f;
        }
        if(f<=1){
            return f;
        }
        if(dp[f][egg] != -1){
            return dp[f][egg];
        }
        int ans = INT_MAX;
        int start = 0 , end = f;
        while(start <= end){
            int mid = (start+end)/2;
            int nhiTuta = solve(f-mid , egg , dp);
            int tutGaya = solve(mid-1 , egg-1 , dp);
            if(nhiTuta > tutGaya){
                start = mid+1;
            }else{
                end = mid-1;
            }
            int temp = 1+max(nhiTuta , tutGaya);
            ans = min(ans , temp);
        }
        return dp[f][egg] = ans;
    }
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(n+1 , vector<int>(k+1 , -1));
        return solve(n , k , dp);
    }
};