class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> st;
        vector<vector<int>> ans;
        int n = nums.size();
        if(n<=3){
            return ans;
        }
        sort(nums.begin(), nums.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int start = j+1 , end = n-1;
                while(start < end){
                    long long sum = (long long)nums[i]+ (long long)nums[j]+ (long long)nums[start]+ (long long)nums[end];
                    if(sum == target){
                        st.insert({nums[i] , nums[j] , nums[start] , nums[end]});
                        end--;
                    }else if(sum > target){
                        end--;
                    }else{
                        start++;
                    }
                }
            }
        }
        for(auto it: st){
            ans.push_back(it);
        }
        return ans;
    }
};