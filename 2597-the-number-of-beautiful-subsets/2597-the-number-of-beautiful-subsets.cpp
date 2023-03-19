class Solution {
public:
    // map<vector<int>, int> ans;
    int ans=0;
    int mp[1001]={0};
    void solve(vector<int>& nums , int index,int& k){
        if(index == nums.size()){
                ans++;
            return;
        }
        solve(nums , index+1 , k);
        int one = nums[index]-k;
        if(one<=0 || (mp[one] == 0)){
            mp[nums[index]] = 1;
            solve(nums , index+1 , k);
            mp[nums[index]]=0;
        }
        return;
        
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        solve(nums , 0,k);
        return ans-1;
    }
};