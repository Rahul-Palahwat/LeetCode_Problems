class Solution {
public:
    int solve(int i,int j, vector<int>&nums1, vector<int>&nums2, vector<vector<int>> &dp){
        int n = nums1.size() , m = nums2.size();
        if(i>=n || j>=m){
            return -1e7;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = nums1[i]*nums2[j];
        ans = max(ans , ans+solve(i+1 , j+1 , nums1, nums2 , dp));
        ans = max(ans , solve(i , j+1 , nums1 , nums2 , dp));
        ans = max(ans , solve(i+1 , j , nums1,nums2 , dp));
        return dp[i][j] = ans;
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() , m = nums2.size();
        vector<vector<int>> dp(n , vector<int> (m, -1));
        return solve(0, 0 , nums1, nums2, dp);
    }
};