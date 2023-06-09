class Solution {
public:
    // BruteForce TC -> O(N^2) 
    // vector<int> majorityElement(vector<int>& nums) {
    //     set<int> ans;
    //     int n = nums.size();
    //     int cnt = 0;
    //     for(int i=0;i<n;i++){
    //         cnt = 1;
    //         for(int j=i+1;j<n;j++){
    //             if(nums[i] == nums[j]){
    //                 cnt++;
    //             }
    //         }
    //         if(cnt > n/3){
    //             ans.insert(nums[i]);
    //         }
    //     }
    //     vector<int> finalAns;
    //     for(auto it: ans){
    //         finalAns.push_back(it);
    //     }
    //     return finalAns;
    // }
    
    
    // HashMap TC-> O(NlogN) , SC -> O(N)
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for(auto it: mp){
            if(it.second > n/3){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};