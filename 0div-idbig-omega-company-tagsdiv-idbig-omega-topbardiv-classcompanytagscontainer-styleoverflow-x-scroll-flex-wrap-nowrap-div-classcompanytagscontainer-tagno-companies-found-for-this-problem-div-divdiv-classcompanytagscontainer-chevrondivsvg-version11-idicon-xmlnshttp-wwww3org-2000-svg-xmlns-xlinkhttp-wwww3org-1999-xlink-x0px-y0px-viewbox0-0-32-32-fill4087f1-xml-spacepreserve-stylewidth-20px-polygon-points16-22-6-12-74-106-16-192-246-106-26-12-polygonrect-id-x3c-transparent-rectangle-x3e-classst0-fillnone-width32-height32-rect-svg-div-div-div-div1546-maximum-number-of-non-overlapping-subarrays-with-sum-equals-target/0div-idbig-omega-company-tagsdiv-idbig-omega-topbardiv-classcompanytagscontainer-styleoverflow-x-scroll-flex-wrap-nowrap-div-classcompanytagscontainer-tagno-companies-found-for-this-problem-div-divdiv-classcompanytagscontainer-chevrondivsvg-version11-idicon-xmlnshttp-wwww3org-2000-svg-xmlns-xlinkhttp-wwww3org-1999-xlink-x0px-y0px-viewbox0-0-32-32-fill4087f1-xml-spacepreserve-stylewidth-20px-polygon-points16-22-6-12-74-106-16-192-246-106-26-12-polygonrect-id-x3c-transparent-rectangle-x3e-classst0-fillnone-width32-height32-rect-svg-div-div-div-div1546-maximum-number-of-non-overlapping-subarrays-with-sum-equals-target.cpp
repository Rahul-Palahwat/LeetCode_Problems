class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0 , sum = 0, end = -1;
        map<int,int> mp;
        mp[0] = -1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(mp.find(sum-target) != mp.end() && end <= mp[sum-target]){
                ans++;
                end = i;
            }
            mp[sum]=i;
        }
        return ans;
    }
};