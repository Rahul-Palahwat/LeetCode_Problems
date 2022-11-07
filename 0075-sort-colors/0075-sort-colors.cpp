class Solution {
public:
    void sortColors(vector<int>& nums) {
        // 1st method 
        // int zero=0,one=0,two=0;
        // for(auto i=0;i<nums.size();i++){
        //     if(nums[i]==0){
        //         zero++;
        //     }else if(nums[i]==1){
        //         one++;
        //     }else{
        //         two++;
        //     }
        // }
        // for(auto i=0;i<nums.size();i++){
        //     if(zero>0){
        //         nums[i]=0;
        //         zero--;
        //     }else if(one>0){
        //         nums[i]=1;
        //         one--;
        //     }else{
        //         nums[i]=2;
        //     }
        // }
        
        // 2nd method
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int i=0;
        for(auto it: mp){
            int count = it.second;
            while(count--){
                nums[i] = it.first;
                i++;
            }
        }
        return;
    }
};