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
    
    
    
    
    
    int longestSubsequence(vector<int>& arr, int diff) {
        int n = arr.size();
        unordered_map<int,int> mp;
        int ans = 1;
        for(int i=0;i<n;i++){
            int back = arr[i]-diff;
            if(mp.find(back) != mp.end()){
                mp[arr[i]] = 1+mp[back];
                ans = max(ans , mp[arr[i]]);
            }else{
                mp[arr[i]] = 1;
            }
        }
        return ans;
    }
};