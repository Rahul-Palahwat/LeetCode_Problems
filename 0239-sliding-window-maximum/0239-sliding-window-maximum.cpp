class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        map<int,int , greater<int>> mp;
        int j=0,i=0;
        for(i=0;i<k;i++){
            mp[nums[i]]++;
        }
        
        ans.push_back(mp.begin()->first);
        while(i<nums.size()){
            mp[nums[i]]++;
            mp[nums[j]]--;
            if(mp[nums[j]] == 0){
                mp.erase(nums[j]);
            }
            ans.push_back(mp.begin()->first);
            i++;
            j++;
        }
        return ans;
    }
};