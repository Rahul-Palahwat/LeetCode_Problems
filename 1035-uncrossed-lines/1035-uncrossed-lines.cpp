class Solution {
public:
//     int solve(vector<int>& nums1 , vector<int>& nums2 , int i , int j , map<int,pair<int , vector<int>>>& first , map<int,pair<int , vector<int>>>& second , vector<vector<int>>& dp){
//         if(i>=nums1.size() || j>=nums2.size()){
//             return 0;
//         }
//         // if(i == nums1.size() - 1){
//         //     if(second.find(nums1[i]) != second.end())
//         //     if(second[nums1[i]]>= j){
//         //         return 1;
//         //     }
//         //     return 0;
//         // }
//         // if(j == nums2.size() - 1){
//         //     if(first.find(nums2[j]) != first.end())
//         //     if(first[nums2[j]] >= i){
//         //         return 1;
//         //     }
//         //     return 0;
//         // }
//         if(dp[i][j] != -1){
//             return dp[i][j];
//         }
//         int taken1 = 0 , taken2 = 0 , notTaken = 0;
//         if(second.find(nums1[i]) != second.end())
//         if(second[nums1[i]].second[first] >= j){
//             taken1 = 1+solve(nums1 , nums2 , i+1 , second[nums1[i]]+1 , first,second , dp);
//         }
//         if(first.find(nums2[j]) != first.end())
//         if(first[nums2[j]] >= i){
//             taken2 = 1+solve(nums1 , nums2 , first[nums2[j]]+1 , j+1 , first , second , dp);
//         }
//         notTaken = solve(nums1 , nums2 , i+1 , j , first , second , dp);
//         notTaken = max(notTaken , solve(nums1 , nums2 , i, j+1 , first , second , dp));
//         notTaken = max(notTaken , solve(nums1 , nums2 , i+1 , j+1 , first , second , dp));
//         return dp[i][j] = max(taken1 , max(taken2 , notTaken));
//     }
//     int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
//         map<int,pair<int,vector<int>>> first , second;
        
//         int n = nums1.size(),m = nums2.size();
//         vector<vector<int>> dp(n+1 , vector<int>(m+1 , -1));
//         for(int i=0;i<n;i++){
//             first[nums1[i]].second.push_back(i);
//             first[nums1[i]].first = 0;
//         }
//         for(int i=0;i<m;i++){
//             second[nums2[i]].second.push_back(i);
//             second[nums2[i]].first = 0;
//         }
//         return solve(nums1 , nums2 , 0 , 0 , first , second , dp);
//     }
    
    
    
    
    
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int m = A.size(), n = B.size(), dp[m+1][n+1];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
                dp[i][j] = A[i - 1] == B[j - 1] ? dp[i - 1][j - 1] + 1 : max(dp[i][j - 1], dp[i - 1][j]);
        return dp[m][n];
    }
};