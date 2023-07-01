class Solution {
public:
    // map<vector<int> , int> mp;
    // int solve(vector<int>& cookies , int index , vector<int> ans){
    //     if(index == cookies.size()){
    //         int mini = INT_MAX , maxi = INT_MIN;
    //         for(auto it: ans){
    //             mini = min(mini , it);
    //             maxi = max(maxi , it);
    //         }
    //         return maxi;
    //     }
    //     if(mp.find(ans) != mp.end()){
    //         return mp[ans];
    //     }
    //     int cal = INT_MAX;
    //     for(int i=0;i<ans.size();i++){
    //         int temp = ans[i];
    //         ans[i] = ans[i]+cookies[index];
    //         cal =  min(cal , solve(cookies , index+1 , ans));
    //         ans[i] = temp;
    //     }
    //     return mp[ans] = cal;
    // }
    // int distributeCookies(vector<int>& cookies, int k) {
    //     vector<int> ans(k , 0);
    //     return solve(cookies  , 0 , ans);
    // }
    int ans = INT_MAX;
    void solve(int start, vector<int>& nums, vector<int>& v, int k){
        if(start==nums.size()){
            int maxm = INT_MIN;
            for(int i=0;i<k;i++){
                maxm = max(maxm,v[i]);
            }
            ans = min(ans,maxm);
            return;
        }
        for(int i=0;i<k;i++){
            v[i] += nums[start];
            solve(start+1,nums,v,k);
            v[i] -= nums[start];
        }
    }
    
    int distributeCookies(vector<int>& nums, int k) { // nums is the cookies vector
        int n = nums.size();
        vector<int> v(k,0); // v is to store each sum of the k subsets
        solve(0,nums,v,k);
        return ans;
    }
};