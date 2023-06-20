class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n , -1);
        if(2*k >= n){
            return ans;
        }
        int i , j = k, start=0;
        long long sum = 0;
        for(i=0;i<(2*k)+1;i++){
            sum+=nums[i];
        }
        // cout<<sum<<" sum "<<j<<endl;
        ans[j] = sum/((2*k)+1);
        j++;
        for(;j<n-k;j++){
            sum-=nums[start];
            sum+=nums[i];
            ans[j] = sum/((2*k)+1);
            i++;
            start++;
        }
        return ans;
    }
};