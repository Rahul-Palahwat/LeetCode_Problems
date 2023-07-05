class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0 , n = nums.size();
        int cnt=0 , flag=0;
        vector<int> store;
        for(int i=0;i<nums.size();i++){
            if(flag==0 && nums[0] == 0){
                flag=1;
                while(nums[i] == 0){
                    i++;
                }
            }
            if(i == n){
                break;
            }
            cnt=1;
            while(i<n-1 && nums[i] == nums[i+1]){
                i++;
                cnt++;
            }
            store.push_back(cnt);
        }
        for(int i=0;i<store.size();i++){
            if(i%2 == 0){
                ans = max(ans , store[i]);
            }else{
                if(store[i] == 1){
                    if(i<store.size()-1){
                        ans = max(ans , store[i-1]+store[i+1]);
                    }
                }
            }
        }
        if(store.size() == 1 && flag == 0){
            return ans-1;
        }
        return ans;
    }
};