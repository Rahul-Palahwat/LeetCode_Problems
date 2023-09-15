class Solution {
public:
    int ans = 0;
    vector<int> merge(vector<int> &l, vector<int> &r){
        int n = l.size() , m = r.size();
        int i = 0 , j = 0;
        vector<int> arr;
        while(i<n && j<m){
            long long temp1 = l[i], temp2 = 2*1LL*r[j];
            if(temp1 > temp2){
                ans+=(n-i);
                j++;
            }else{
                i++;
            }
        }
        i=0,j=0;
        while(i<n && j<m){
            if(l[i] > r[j]){
                arr.push_back(r[j]);
                j++;
            }else{
                arr.push_back(l[i]);
                i++;
            }
        }
        while(i<n){
            arr.push_back(l[i]);
            i++;
        }
        while(j<m){
            arr.push_back(r[j]);
            j++;
        }
        return arr;
    }
    vector<int> mergeSort(vector<int> &nums , int start , int end){
        if(start == end){
            return {nums[start]};
        }
        int mid = (start+end)/2;
        vector<int> l = mergeSort(nums , start , mid);
        vector<int> r = mergeSort(nums , mid+1 , end);
        return merge(l , r);
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp = mergeSort(nums , 0 , n-1);
        return ans;
    }
};