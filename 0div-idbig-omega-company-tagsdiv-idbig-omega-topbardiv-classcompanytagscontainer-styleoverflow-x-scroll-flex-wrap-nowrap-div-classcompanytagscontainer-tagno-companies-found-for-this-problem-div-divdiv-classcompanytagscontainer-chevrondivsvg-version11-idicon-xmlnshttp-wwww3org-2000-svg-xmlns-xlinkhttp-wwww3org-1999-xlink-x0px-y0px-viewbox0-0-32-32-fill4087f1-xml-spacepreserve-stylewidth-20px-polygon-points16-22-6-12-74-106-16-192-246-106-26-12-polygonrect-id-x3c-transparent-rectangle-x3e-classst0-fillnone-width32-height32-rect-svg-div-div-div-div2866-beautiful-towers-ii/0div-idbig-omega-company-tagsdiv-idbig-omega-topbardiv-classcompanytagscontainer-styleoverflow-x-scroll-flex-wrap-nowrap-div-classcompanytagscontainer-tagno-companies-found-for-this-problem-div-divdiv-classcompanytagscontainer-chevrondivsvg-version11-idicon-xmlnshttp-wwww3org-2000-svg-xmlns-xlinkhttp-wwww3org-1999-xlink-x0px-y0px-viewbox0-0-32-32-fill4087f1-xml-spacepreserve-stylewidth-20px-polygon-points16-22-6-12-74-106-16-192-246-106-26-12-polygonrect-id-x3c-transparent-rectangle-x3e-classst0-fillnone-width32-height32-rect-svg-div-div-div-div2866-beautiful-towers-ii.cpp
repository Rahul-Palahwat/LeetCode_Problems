class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        long long ans = 0;
        int n = maxHeights.size();
        vector<long long> prefix(n , 0) , suffix(n , 0);
        long long temp = 0;
        stack<pair<long long,long long>> st;
        for(int i=0;i<n;i++){
            if(st.size() == 0){
                temp = maxHeights[i]*1LL*(i+1);
                st.push({maxHeights[i] , i});
            }
            else if(st.size() > 0 && st.top().first > maxHeights[i]){
                int index = 0;
                while(st.size() > 0 && st.top().first > maxHeights[i]){
                    st.pop();
                }
                if(st.size() > 0){
                    index = st.top().second;
                    temp = prefix[index];
                    // cout<<i<<" index "<<index<<" temp "<<temp<<" ";
                    temp += (maxHeights[i])*1LL*(i-index);
                    // cout<<temp<<" "<<(i-temp+1)<<endl;
                    st.push({maxHeights[i] , i});
                }else{
                    temp = maxHeights[i]*1ll*(i+1);
                    st.push({maxHeights[i] , i});
                }
            }else{
                temp+=maxHeights[i];
                st.push({maxHeights[i] , i});
            }
            prefix[i] = temp;
        }
        while(!st.empty()){
            st.pop();
        }
        temp = 0;
        for(int i=n-1;i>=0;i--){
            if(st.size() == 0){
                temp = maxHeights[i]*1ll*(n-i);
                st.push({maxHeights[i] , i});
            }
            else if(st.size() > 0 && st.top().first > maxHeights[i]){
                while(st.size() > 0 && st.top().first > maxHeights[i]){
                    st.pop();
                }
                if(st.size() > 0){
                    int index = st.top().second;
                    temp = suffix[index];
                    // cout<<i<<" index "<<index<<" temp "<<temp<<" ";
                    temp += (maxHeights[i])*1ll*(n-i-(n-index));
                    st.push({maxHeights[i] , i});
                    // cout<<temp<<endl;
                }else{
                    temp = maxHeights[i]*1ll*(n-i);
                    st.push({maxHeights[i] , i});
                }
            }else{
                temp+=maxHeights[i];
                st.push({maxHeights[i] , i});
            }
            suffix[i] = temp;
        }
        for(auto it: prefix){
            cout<<it<<" ";
        }
        cout<<endl;
        for(auto it: suffix){
            cout<<it<<" ";
        }
        cout<<endl;
        for(int i=0;i<n;i++){
            ans = max(ans , prefix[i]+suffix[i] - maxHeights[i]);
        }
        return ans;
    }
};