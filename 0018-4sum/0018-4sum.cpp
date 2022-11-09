class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if(nums.size() <=3){
            return ans;
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-3;){
            for(int j=i+1;j<nums.size()-2;){
                int k=j+1,l=nums.size()-1;
                while(k<l){
                    
                    long long sum=0;
                    sum+=nums[i];
                    sum+=nums[j];
                    sum+=nums[k];
                    sum+=nums[l];
                    long long tar = target;
                    if(sum > tar){
                        l--;
                    }else if(sum < tar){
                        k++;
                    }else{
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        temp.push_back(nums[l]);
                        int kval = nums[k];
                        ans.push_back(temp);
                        while(k<l && nums[k] == kval){
                            k++;
                        }
                        l--;
                    }
                }
                int jval = nums[j];
                while(j<nums.size()-2 && nums[j] == jval){
                    j++;
                }
            }
            int ival = nums[i];
            while((i<nums.size()-3) && (nums[i] == ival)){
                i++;
            }
        }
        return ans;
    }
};