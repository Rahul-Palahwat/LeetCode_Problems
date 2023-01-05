class Solution {
public:
//     vector<vector<int>> ans;
//     bool check(vector<int> temp, int num){
//         for(auto it: temp){
//             if((it%num != 0) &&(num%it !=0)){
//                 return false;
//             }
//         }
//         return true;
//     }
//     void solve(vector<int> nums, int index,vector<int> temp){
//         if(index == nums.size()){
//             ans.push_back(temp);
//             return;
//         }
//         if(check(temp,nums[index])){
//             solve(nums,index+1,temp);
//             temp.push_back(nums[index]);
//             solve(nums,index+1,temp);
//         }else{
//             solve(nums,index+1,temp);
//         }
        
//         return;
//     }
//     vector<int> largestDivisibleSubset(vector<int>& nums) {
//         vector<int> temp;
//         solve(nums,0,temp);
//         int sz = 0;
//         for(auto it: ans){
//             if(it.size() > sz){
//                 temp = it;
//                 sz = it.size();
//             }
//         }
//         return temp;
//     }
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size()==0){
            return nums;
        }
        sort(nums.begin(),nums.end());
        int flag=1;
        if(nums[0]==1){
            flag=0;
        }
        else{
            nums.push_back(1);
            flag=1;
        }
        sort(nums.begin(),nums.end());
        int i,j;
        int dp[nums.size()][2];
        for(i=nums.size()-1;i>=0;i--){
            dp[i][0]=0;
            dp[i][1]=i;
            for(j=i+1;j<nums.size();j++){
                if((nums[j]%nums[i])==0){
                    if(dp[j][0]>dp[i][0]){
                        dp[i][0]=dp[j][0];
                        dp[i][1]=j;
                    }  
                }
            }
            dp[i][0]++;
        }
        i=0;
        vector<int> t;
        t.push_back(nums[i]);
        while(dp[i][1]!=i){
            i=dp[i][1];
            t.push_back(nums[i]);
            
        }
        if(flag==1){
            t.erase(t.begin());
        }
        return t;
        
    }
};