class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i= m-1, j = n-1;
        int total = m+n-1;
        while(j>=0){
            if(i < 0){
                while(j>=0){
                    nums1[total] = nums2[j];
                    j--;
                    total--;
                }
                break;
            }
            if(nums1[i] <= nums2[j]){
                nums1[total] = nums2[j];
                j--;
                total--;
            }else{
                nums1[total] = nums1[i];
                i--;
                total--;
            }
        }
        return;
    }
};