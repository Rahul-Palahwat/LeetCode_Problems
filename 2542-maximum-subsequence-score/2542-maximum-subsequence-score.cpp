class Solution {
public:
//     long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
//         long long ans=INT_MIN , sum=0, i=0;
//         priority_queue<int> maxh;
//         while(i<k-1){
//             sum+=nums1[i];
//             maxh.push(nums2[i]);
//             i++;
//         }
//         long long j=0;
//         // ans = max(ans , (sum)* maxh.front());
//         while(i<nums1.size()){
//             sum+=nums1[i];
//             sum-=nums1[j];
//             while(minh.front() != nums[2][j]){
//                 minh.pop();
//             }
//             minh.pop();
//             if(minh.size() > 0){
//                 ans = max(ans , minh.front()*sum);
//             }else{
                
//             }
//             j++;
//             i++;
//         }
//     }
    long long maxScore(vector<int>& numa, vector<int>& numb, int k) {
//         // solve(a,b,k,0,INT_MAX,0);
//         long long sum = 0;
        int n = numb.size();
        long long ans=0;
        long long sum=0;
        priority_queue<int, vector<int>, greater<int>> minh;
        vector<vector<int>> vec;
        for(int i=0;i<n;i++){
            
            vec.push_back({numb[i], numa[i]});
            
        }
        // for(auto it: vec){
        //     cout<<it.first<<endl;
        // }
        sort(vec.begin(), vec.end());
        // for(auto it: vec){
        //     cout<<it.first<<endl;
        // }
        
        for(int i=n-1;i>=n-k;i--){
            sum =sum + vec[i][1];
            minh.push(vec[i][1]);
        }
//         for(int i=0;i<a.size();i++){
//             long long temp;
//             if(min2.size() == k){
//                 temp = sum;
//                 temp*=min2.top().first;
//                 ans = max(ans , temp);
//             }
//             sum+=a[i];
//             min2.push({b[i],i});
//             min1.push({a[i],i});
//             if(min2.size() > k){
//                 auto t = min2.top();
//                 auto tt = min1.top();
//                 if(t.first < b[tt.second]){
//                     long long su = sum;
//                     su-=tt.first;
//                     su*=t.first;
//                     ans = max(ans , su);
//                 }
//                 sum-=a[t.second];
//                 min2.pop();
//                 min1.pop();
                
//             }
//             temp = sum;
//             temp*=min2.top().first;
//             ans = max(ans , temp);
//         }
        ans = sum;
        ans*=vec[n-k][0];
        for(int i=n-k-1 ; i >= 0; i--){
            minh.push(vec[i][1]);
            // cout<<sum<<endl;
            sum += vec[i][1];
            // cout<<sum<<endl;
            sum -= minh.top();
            // cout<<sum<<endl;
            minh.pop();
            // cout<<ans<<endl;
            ans = max(ans, vec[i][0]*sum);
            // cout<<ans<<endl;
        }
        
        return ans;
//         priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> min1,min2;

//         return ans;
    }
};