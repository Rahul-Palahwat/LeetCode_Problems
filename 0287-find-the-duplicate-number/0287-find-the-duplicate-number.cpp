class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // first method
        // sort(nums.begin(),nums.end());
        // for(auto i=0;i<nums.size()-1;i++){
        //     if(nums[i]==nums[i+1]){
        //         return nums[i];
        //     }
        // }
        // return 1;
        
        // 2nd method 
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto it: mp){
            if(it.second>1){
                return it.first;
            }
        }
        return 1;
    }
};