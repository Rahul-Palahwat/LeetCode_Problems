class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() , m = nums2.size();
        long long ans=0, tempSum1 = 0 , tempSum2 = 0;
        int i=0,j=0;
        long long MOD = 1e9+7;
        while(i<n && j<m){
            if(i<n && j<m && nums1[i] == nums2[j]){
                ans=(ans+nums1[i]+max(tempSum1 , tempSum2))%MOD;
                tempSum1 = 0 , tempSum2 = 0 , i++ , j++;
            }
            while(i<n && j<m && nums1[i] < nums2[j]){
                tempSum1 = (tempSum1+nums1[i]);
                i++;
            }
            while(j<m && i<n && nums2[j] < nums1[i]){
                tempSum2 = (tempSum2+nums2[j]);
                j++;
            }
        }
        while(i<n){
            tempSum1 = (tempSum1+nums1[i]);
            i++;
        }
        while(j<m){
            tempSum2 = (tempSum2+nums2[j]);
            j++;
        }
        ans = (ans+max(tempSum1 , tempSum2))%MOD;
        return ans;
    }
};