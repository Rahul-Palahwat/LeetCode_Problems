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
    // vector<int> majorityElement(vector<int>& nums) {
    //     vector<int> ans;
    //     int n = nums.size();
    //     map<int,int> mp;
    //     for(int i=0;i<n;i++){
    //         mp[nums[i]]++;
    //     }
    //     for(auto it: mp){
    //         if(it.second > n/3){
    //             ans.push_back(it.first);
    //         }
    //     }
    //     return ans;
    // }
    
    
    // Moore's Voting Algorithm 
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        int cnt1=0 , cnt2=0 , el1=INT_MIN, el2=INT_MIN;
        for(int i=0;i<n;i++){
            if(cnt1 == 0 && el2 != nums[i]){
                cnt1++;
                el1 = nums[i];
            }else if(cnt2 == 0 && el1 != nums[i]){
                cnt2++;
                el2 = nums[i];
            }else if(el1 == nums[i]){
                cnt1++;
            }else if(el2 == nums[i]){
                cnt2++;
            }else{
                cnt1--;
                cnt2--;
            }
        }
        if(el1 != INT_MIN){
            cnt1=0;
            for(auto it: nums){
                if(it == el1){
                    cnt1++;
                }
            }
            if(cnt1 > n/3){
                ans.push_back(el1);
            }
        }
        if(el2 != INT_MIN){
            cnt2=0;
            for(auto it: nums){
                if(it == el2){
                    cnt2++;
                }
            }
            if(cnt2 > n/3){
                ans.push_back(el2);
            }
        }
        sort(ans.begin() , ans.end());
        return ans;
    }
};