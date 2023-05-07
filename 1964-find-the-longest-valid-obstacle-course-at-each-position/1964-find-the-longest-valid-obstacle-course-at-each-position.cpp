class Solution {
public:
    
    
    // O(N^2) solution 
    // vector<int> longestObstacleCourseAtEachPosition(vector<int>& A) {
    //     int n = A.size();
    //     vector<int> ans(n,1);
    //     for(int i=1;i<n;i++){
    //         int j=i-1;
    //         int maxi = 0;
    //         while(j>=0){
    //             if(A[j] <= A[i]){
    //                 maxi = max(maxi , ans[j]);
    //             }
    //             j--;
    //         }
    //         // cout<<maxi<<"maxi"<<endl;
    //         ans[i]+=maxi;
    //     }
    //     return ans;
    // }
    
    
    
    
    // O(NlogN) solution 
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& A) {
        int n = A.size();
        vector<int> ans(n) , curr;
        for(int i=0;i<n;i++){
            if(curr.size() == 0 || curr.back() <= A[i]){
                curr.push_back(A[i]);
                ans[i] = curr.size();
            }else{
                int index = upper_bound(curr.begin() , curr.end() , A[i])-curr.begin();
                curr[index] = A[i];
                ans[i] = index+1;
            }
        }
        return ans;
    }
    
};