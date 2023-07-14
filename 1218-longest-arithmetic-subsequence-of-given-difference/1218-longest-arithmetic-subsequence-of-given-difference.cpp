class Solution {
public:
    
    // Recursion
    // int solve(int index , vector<int>&arr , int prev , int diff){
    //     if(index == arr.size()){
    //         return 0;
    //     }
    //     int ans = solve(index+1 , arr , prev , diff);
    //     if(prev == INT_MIN){
    //         ans = max(ans , 1+solve(index+1 , arr, arr[index] , diff));
    //     }else{
    //         if(arr[index]-prev == diff){
    //             ans = max(ans , 1+solve(index+1 , arr , arr[index] , diff));
    //         }
    //     }
    //     return ans;
    // }
    // int longestSubsequence(vector<int>& arr, int diff) {
    //     return solve(0 , arr , INT_MIN , diff);
    // }
    
    
    
    
    
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        unordered_map<int, int> dp; // Stores the maximum length at each index
        
        int ans = 1; // Initialize with the minimum length of 1
        
        for (int i = 0; i < n; i++) {
            int num = arr[i];
            if (dp.find(num - difference) != dp.end()) {
                dp[num] = dp[num - difference] + 1;
            } else {
                dp[num] = 1;
            }
            
            ans = max(ans, dp[num]);
        }
        
        return ans;
    }
};