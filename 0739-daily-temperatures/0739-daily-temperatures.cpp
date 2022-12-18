class Solution {
public:
    // Dp approach 
//     vector<int> dailyTemperatures(vector<int>& temperatures) {
//         int n = temperatures.size();
//         vector<int> post(n,0);
//         for(int i=n-2;i>=0;i--){
//             if(temperatures[i]<temperatures[i+1]){
//                 post[i] = 1;
//             }else{
//                 if(post[i+1] > 0){
//                     int j = i+post[i+1];
//                     int flag=0;
//                     while(temperatures[j] <= temperatures[i]){
//                         if(post[j] == 0){
//                             post[i] = 0;
//                             flag=1;
//                             break;
//                         }else{
//                             j = j+post[j];
//                         }
//                     }
//                     if(flag==0){
//                         // cout<<j<<" j "<<i<<endl;
//                         post[i] = j-i;
//                     }
                    
//                 }else{
//                     post[i] = 0;
//                 }
//             }
//         }
//         return post;
//     }
    
    // stack approach 
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        vector<int> ans(n,0);
        stack<pair<int,int>> st;
        st.push({t[n-1],n-1});
        for(int i = n-2;i>=0;i--){
            while((st.size() > 0)&& (st.top().first <= t[i])){
                st.pop();
            }
            if(st.size() > 0){
                ans[i] = st.top().second - i;
            }
            st.push({t[i],i});
        }
        return ans;
    }
};