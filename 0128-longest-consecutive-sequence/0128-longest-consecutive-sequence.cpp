class Solution {
public:
    
    // neive approach
    // int longestConsecutive(vector<int>& nums) {
    //     if(nums.size()==0){
    //         return 0;
    //     }
    //     sort(nums.begin(),nums.end());
    //     int ans = 1;
    //     int temp=1;
    //     for(int i=0;i<nums.size()-1;i++){
    //         if(nums[i]+1 == nums[i+1]){
    //             temp++;
    //             ans = max(ans,temp);
    //         }else if(nums[i] == nums[i+1]){
    //             continue;
    //         }else{
    //             temp=1;
    //         }
    //     }
    //     return ans;
    // }
    
    
    // hashset solution 
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        for(auto it:nums) s.insert(it);
        int ans = 0;
        for(auto it:nums){
            // as we will start from minimal element 
            if(s.count(it-1)){
                continue;
            }else{
                int curr = it;
                curr++;
                int temp = 1;
                while(s.count(curr++)){
                    temp++;
                }
                ans = max(ans,temp);
            }
        }
        return ans;
    }
};