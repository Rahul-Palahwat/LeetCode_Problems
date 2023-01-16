class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int flag=0;
            for(int j=i+1;j<nums.size();j++){
                if(nums[i] < nums[j]){
                    ans.push_back(nums[j]);
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                for(int j=0;j<i;j++){
                    if(nums[i] < nums[j]){
                        flag=1;
                        ans.push_back(nums[j]);
                        break;
                    }
                }
            }
            if(flag==0){
                ans.push_back(-1);
            }
        }
        return ans;
    }
};