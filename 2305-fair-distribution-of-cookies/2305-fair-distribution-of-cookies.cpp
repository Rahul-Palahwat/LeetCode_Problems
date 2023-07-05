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
    
    
    // BinarySearch Approach
    bool possible(int mid , int k , vector<int>& nums){
        int sum = 0;
        for(auto it: nums){
            sum+=it;
            if(sum > mid){
                sum = it;
                k--;
            }
        }
        return (k == 0 && sum == 0) || k>0;
    }
    int BinarySearch(vector<int>& nums , int start , int end , int k){
        int ans = INT_MAX;
        while(start <= end){
            int mid = (start+end)/2;
            if(possible(mid , k , nums)){
                ans = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return ans;
    }
    int distributeCookies(vector<int>& nums, int k) {
        sort(nums.begin() , nums.end());
        int start = *max_element(nums.begin() , nums.end());
        int end = accumulate(nums.begin(), nums.end() , 0);
        int ans= INT_MAX;
        do{
            ans = min(ans , BinarySearch(nums , start, end , k));
        }while(next_permutation(nums.begin() , nums.end()));
        return ans;
    }
};