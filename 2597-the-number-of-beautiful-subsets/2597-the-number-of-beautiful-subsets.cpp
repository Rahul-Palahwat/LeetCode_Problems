class Solution {
public:
    // map<vector<int>, int> ans;
    int ans=0;
    int mp[2001]={0};
    void solve(vector<int>& nums , int index,int& k){
        if(index > nums.size()){
            return;
        }
        if(index == nums.size()){
            // if(v.size() > 0){
                // for(auto it: v){
                //     cout<<it<<" ";
                // }
                // cout<<endl;
                ans++;
            // }
            return;
        }
        solve(nums , index+1 , k);
        int one = nums[index]-k;
        if(one<=0 || (mp[one] == 0)){
            // v.push_back(nums[index]);
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
        // int finalans = ans.size();
        
        // cout<<finalans<<endl;
        // return finalans;
        return ans-1;
    }
};