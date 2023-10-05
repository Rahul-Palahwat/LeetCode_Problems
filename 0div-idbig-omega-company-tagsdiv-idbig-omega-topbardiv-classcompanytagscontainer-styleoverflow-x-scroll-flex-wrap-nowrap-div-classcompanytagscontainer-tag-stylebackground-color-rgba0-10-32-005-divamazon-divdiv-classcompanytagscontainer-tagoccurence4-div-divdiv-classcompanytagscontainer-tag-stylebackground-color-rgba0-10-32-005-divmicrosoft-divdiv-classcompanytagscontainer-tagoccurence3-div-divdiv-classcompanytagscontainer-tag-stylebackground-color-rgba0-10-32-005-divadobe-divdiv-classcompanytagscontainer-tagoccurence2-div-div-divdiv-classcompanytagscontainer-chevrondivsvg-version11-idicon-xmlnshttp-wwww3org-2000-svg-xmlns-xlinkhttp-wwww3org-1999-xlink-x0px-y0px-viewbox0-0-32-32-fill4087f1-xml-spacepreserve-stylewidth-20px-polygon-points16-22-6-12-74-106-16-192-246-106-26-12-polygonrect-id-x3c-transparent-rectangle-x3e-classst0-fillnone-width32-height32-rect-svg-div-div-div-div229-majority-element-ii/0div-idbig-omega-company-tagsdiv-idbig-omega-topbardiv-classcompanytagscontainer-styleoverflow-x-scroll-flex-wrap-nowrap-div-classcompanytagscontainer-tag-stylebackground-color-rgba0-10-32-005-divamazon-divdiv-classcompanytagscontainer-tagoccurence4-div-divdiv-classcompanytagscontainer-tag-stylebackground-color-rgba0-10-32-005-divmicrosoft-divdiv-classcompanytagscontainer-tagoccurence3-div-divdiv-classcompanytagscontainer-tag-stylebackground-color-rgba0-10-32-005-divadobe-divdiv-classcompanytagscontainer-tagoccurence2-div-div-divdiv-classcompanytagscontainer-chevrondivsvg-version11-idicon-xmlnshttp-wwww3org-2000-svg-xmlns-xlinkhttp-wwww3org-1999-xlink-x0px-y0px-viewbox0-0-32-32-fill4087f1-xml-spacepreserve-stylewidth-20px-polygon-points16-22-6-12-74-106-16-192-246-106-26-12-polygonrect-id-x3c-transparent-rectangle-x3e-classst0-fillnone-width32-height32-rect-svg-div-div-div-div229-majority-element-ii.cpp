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
    vector<int> majorityElement(vector<int>& arr) {
        vector<int> ans;
        int cnt1=0,cnt2=0,ele1=INT_MAX,ele2=INT_MAX;
        int n = arr.size();
        for(int i=0;i<n;i++){
            if(cnt1 == 0 && ele2 != arr[i]){
                cnt1++;
                ele1 = arr[i];
            }else if(cnt2 == 0 && ele1 != arr[i]){
                cnt2++;
                ele2 = arr[i];
            }else if(ele1 == arr[i]){
                cnt1++;
            }else if(ele2 == arr[i]){
                cnt2++;
            }else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1 =0 , cnt2 = 0;
        for(auto it: arr){
            if(it == ele1){
                cnt1++;
            }
            if(it == ele2){
                cnt2++;
            }
        }
        if(cnt1 > n/3){
            ans.push_back(ele1);
        }
        if(cnt2 > n/3){
            ans.push_back(ele2);
        }
        return ans;
    }
};