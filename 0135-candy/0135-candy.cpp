class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<pair<int,int>> pairs;
        for(int i=0;i<n;i++){
            pairs.push_back({ratings[i] , i});
        }
        int ans = 0;
        vector<int> vis(n , -1);
        sort(pairs.begin() , pairs.end());
        for(int i=0;i<n;i++){
            auto top = pairs[i];
            if(vis[top.second] != -1){
                continue;
            }
            int index = top.second;
            int start = index-1, prev = index;
            ans+=1;
            vis[index] = 1;
            int end = index+1;
            int val = 2;
            while(start >= 0 && vis[start] == -1 && ratings[start] > ratings[prev]){
                ans+=val;
                vis[start] = val;
                val++;
                prev = start;
                start--;
            }
            if(start >= 0 && ratings[start] > ratings[prev] && vis[start] != -1){
                if(vis[start] <= vis[prev]){
                    int temp = max(vis[start]+1 , val);
                    ans+=(temp - vis[start]);
                    vis[start] = temp;
                }
            }
            val = 2;
            prev = index;
            while(end < n && vis[end] == -1 && ratings[end] > ratings[prev]){
                ans+=val;
                vis[end] = val;
                val++;
                prev = end;
                end++;
            }
            if(end < n && ratings[end] > ratings[prev] && vis[end] != -1){
                if(vis[prev] >= vis[end]){
                    int temp = max(vis[end]+1 , val);
                    ans+=(temp - vis[end]);
                    vis[end] = temp;
                }
            }
        }
        return ans;
    }
};