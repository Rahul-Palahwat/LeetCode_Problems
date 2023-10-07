class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int n = nums1.size() , m = nums2.size();
        sort(nums1.begin() , nums1.end());
        sort(nums2.begin() , nums2.end());
        
        
        for(int i=0;i<n;i++){
            int start = 0 , end = m-1;
            long long find = nums1[i]*1LL*nums1[i];
            long long temp = 0;
            while(start < end){
                temp = nums2[start]*1LL*nums2[end];
                if(temp == find){
                    int tempi = end;
                    int cnt1 = 0 , cnt2 = 0;
                    while(end>start && nums2[end] == nums2[tempi]){
                        cnt1++;
                        end--;
                    }
                    tempi = start;
                    // cout<<cnt1<<" "<<start<<" st "<<end<<endl;
                    if(start == end && nums2[start] == nums2[start+1]){
                        ans+=(cnt1*(cnt1+1))/2;
                        break;
                    }
                    if(start == end){
                        ans+=cnt1;
                        break;
                    }
                    while(start <= end && nums2[start] == nums2[tempi]){
                        cnt2++;
                        start++;
                    }
                    // if(start == end){
                    //     ans+=(cnt2*(cnt2+1))/2;
                    //     break;
                    // }
                    ans+=(cnt1 * cnt2);
                }else if(temp < find){
                    start++;
                }else{
                    end--;
                }
            }
            // cout<<ans<<" "<<i<<" find "<<find<<endl;
        }
        // cout<<ans<<endl;
        for(int i=0;i<m;i++){
            int start = 0 , end = n-1;
            long long find = nums2[i]*1LL*nums2[i];
            long long temp = 0;
            while(start < end){
                temp = nums1[start]*1LL*nums1[end];
                if(temp == find){
                    int tempi = end;
                    int cnt1 = 0 , cnt2 = 0;
                    while(end>start && nums1[end] == nums1[tempi]){
                        cnt1++;
                        end--;
                    }
                    tempi = start;
                    cout<<cnt1<<" "<<start<<" st "<<end<<endl;
                    if(start == end && nums1[start] == nums1[start+1]){
                        ans+=(cnt1*(cnt1+1))/2;
                        break;
                    }
                    if(start == end){
                        ans+=cnt1;
                        break;
                    }
                    while(start <= end && nums1[start] == nums1[tempi]){
                        cnt2++;
                        start++;
                    }
                    // if(start == end){
                    //     ans+=(cnt2*(cnt2+1))/2;
                    //     break;
                    // }
                    ans+=(cnt1 * cnt2);
                }else if(temp < find){
                    start++;
                }else{
                    end--;
                }
            }
        }
        return ans;
    }
};