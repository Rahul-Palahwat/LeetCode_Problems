class Solution {
public:
    // least ks
    
    bool predicate(vector<vector<int>> &nums, int mid, int k){
        vector<int> copy;
        int i = 0, n = nums.size();
        while(i<n && nums[i][0]<=mid){
            copy.push_back(nums[i][1]);
            i++;
        }
        
        sort(copy.begin(), copy.end());
        int j = 0, prev = -2;
        for(int i:copy){
            if(abs(i-prev)==1)
                continue;
            prev = i;
            j++;
        }
        
        return j>=k;
    }
    
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<vector<int>> temp;
        for(int i=0;i<n;i++){
            temp.push_back({nums[i], i});
        }
        
        sort(temp.begin(), temp.end());
        int res = 0;
        int low = 1, high = 1e9;
        while(low<=high){
            int mid = (low+high)>>1;
            if(predicate(temp, mid, k)){
                res = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        
        return res;
    }
};