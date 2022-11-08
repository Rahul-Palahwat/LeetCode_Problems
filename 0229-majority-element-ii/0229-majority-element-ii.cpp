class Solution {
public:
    // First approach 
//     vector<int> majorityElement(vector<int>& nums) {
//         long long int count=1,max,flag=0,i,j=0,k,l,ans;
//         vector<int> a;
//         sort(nums.begin(),nums.end());
//         if(nums.size()==1){
//             a.push_back(nums[0]);
//             return a;
//         }
//         if(nums.size()==2){
//             if(nums[1]==nums[0]){
//                 a.push_back(nums[0]);
//                 return a;
//             }else{
//                 a.push_back(nums[0]);
//                 a.push_back(nums[1]);
//                 return a;
//             }
//         }
        
//         for(int i=1;i<nums.size();i++){
//             if(nums[i]==nums[i-1]){
//                 count++;
//                 if(count>(nums.size()/3)&&flag==0){
//                     a.push_back(nums[i]);
//                     flag=1;
//                 }
//             }
//             else{
//                 count=1;
//                 flag=0;
//             }
//         }
//         return a;
//     }
    
    
    // again solving 
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(),nums.end());
        int count=1;
        if(nums.size()==1){
            return nums;
        }
        for(int i=0;i<nums.size();i++){
            if(count>nums.size()/3){
                if(ans.size()>0){
                    if(ans[ans.size()-1] != nums[i]){
                        ans.push_back(nums[i]);
                    }
                }else{
                    ans.push_back(nums[i]);
                }
            }
            if(i<nums.size()-1)
            if(nums[i] == nums[i+1]){
                count++;
            }else{
                count=1;
            }
        }
        return ans;
    }
};