class Solution {
public:
    // Bruteforce TC -> O(N^2)
    // int majorityElement(vector<int>& nums) {
    //     int cnt = 0;
    //     int n = nums.size();
    //     for(int i=0;i<n;i++){
    //         cnt=1;
    //         for(int j=i+1;j<n;j++){
    //             if(nums[i] == nums[j]){
    //                 cnt++;
    //             }
    //         }
    //         if(cnt > n/2){
    //             return nums[i];
    //         }
    //     }
    //     return -1;
    // }
    
    
    // HashMap TC-> O(NlogN) , SC-> O(N)
    // int majorityElement(vector<int>& nums) {
    //     int n = nums.size();
    //     map<int,int> mp;
    //     for(auto it: nums){
    //         mp[it]++;
    //     }
    //     for(auto it: mp){
    //         if(it.second > n/2){
    //             return it.first;
    //         }
    //     }
    //     return -1;
    // }
    
    
    // Using Moore's Voting Algorithm
    int majorityElement(vector<int>& nums) {
        int cnt=1;
        int n = nums.size();
        int start=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i] != start){
                cnt--;
            }else{
                cnt++;
            }
            if(cnt == 0 && i<n){
                start = nums[i+1];
                cnt=1;
                i++;
            }
        }
        cnt=0;
        for(auto it: nums){
            if(it == start){
                cnt++;
            }
        }
        if(cnt > n/2){
            return start;
        }
        return -1;
    }
        
};