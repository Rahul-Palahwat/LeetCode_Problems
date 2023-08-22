class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int, pair<int,pair<int,int>>> mp;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i]) == mp.end()){
                mp[nums[i]] = {1 , {i , i}};
            }else{
                mp[nums[i]].first+=1;
                mp[nums[i]].second.second = i;
            }
        }
        int ans = INT_MAX;
        int maxi = 0;
        for(auto it: mp){
            if(it.second.first == maxi){
                ans = min(ans , it.second.second.second - it.second.second.first+1);
            }else if(it.second.first > maxi){
                maxi = it.second.first;
                ans = it.second.second.second - it.second.second.first+1;
            }
        }
        return ans == INT_MAX ? 1 : ans;
    }
};