class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        int i=0,j=n/2;
        while(j<n){
            ans.push_back(nums[i]);
            ans.push_back(nums[j]);
            i++;
            j++;
        }
        return ans;
    }
};