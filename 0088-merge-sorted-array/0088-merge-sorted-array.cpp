class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i= 0, j = 0;
        int total = m+n-1;
        int dis = m;
        // cout<<total<<endl;
        while(j<n){
            if(nums1[i] <= nums2[j] && i<dis){
                i++;
            }else{
                int index = total;
                while(index > i){
                    nums1[index] = nums1[index-1];
                    index--;
                }
                nums1[i] = nums2[j];
                i++;
                j++;
                dis++;
            }
        }
        return;
    }
};