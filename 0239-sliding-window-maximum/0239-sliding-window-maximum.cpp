class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        map<int,int, greater<int>> mp;
        int i=0;
        while(i<k){
            mp[nums[i]]++;
            i++;
        }
        int j=0;
        int maxi = 0;
        maxi = (*mp.begin()).first;
        ans.push_back(maxi);
        while(i<n){
            mp[nums[i]]++;
            mp[nums[j]]--;
            if(mp[nums[j]] == 0){
                mp.erase(nums[j]);
            }
            maxi = (*mp.begin()).first;
            ans.push_back(maxi);
            i++;
            j++;
        }
        return ans;
    }
};