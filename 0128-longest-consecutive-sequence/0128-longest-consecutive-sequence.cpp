class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int ans = 1;
        int temp=1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]+1 == nums[i+1]){
                temp++;
                ans = max(ans,temp);
            }else if(nums[i] == nums[i+1]){
                continue;
            }else{
                temp=1;
            }
        }
        return ans;
    }
};