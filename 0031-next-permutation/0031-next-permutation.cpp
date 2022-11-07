class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        vector<int> ans;
        int flag=0,temp,index;
        for(int i=nums.size()-1;i>0;i--){
            ans.push_back(nums[i]);
            if(nums[i]>nums[i-1]){
                index=i-1;
                temp=nums[i-1];
                flag=1;
                break;
            }
        }
        if(flag==0){
            sort(nums.begin(),nums.end());
            return;
        }
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++){
            if(ans[i]>temp){
                nums[index]=ans[i];
                ans.erase(ans.begin()+i);
                break;
            }
        }
        ans.push_back(temp);
        sort(ans.begin(),ans.end());
        index++;
        for(int i=0;i<ans.size();i++){
            nums[index]=ans[i];
            index++;
        }
        return;
    }
};