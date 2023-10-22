class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int ans = nums[k];
        int n = nums.size() , i = k , j = k;
        int mini = nums[k];
        while(i>=0 && j<n){
            if(nums[i] >= nums[j]){
                mini = min(mini , nums[i]);
                ans = max(ans , mini*(j-i));
                i--;
            }else{
                mini = min(mini , nums[j]);
                ans = max(ans , mini*(j-i));
                j++;
            }
            // cout<<mini<<endl;
            
        }
        while(i>=0){
            mini = min(mini , nums[i]);
            ans = max(ans , mini*(j-i));
            i--;
        }
        while(j<n){
            mini = min(mini , nums[j]);
            ans = max(ans , mini*(j-i));
            j++;
        }
        return ans;
    }
};