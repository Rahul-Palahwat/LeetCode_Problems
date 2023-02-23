class Solution {
public:
    int ans = 0;
    // void solve(int index , int k , int w , vector<pair<int,int>> v){
    //     if(index == v.size() || k == 0){
    //         ans = max(ans , w);
    //         return;
    //     }
    //     solve(index+1 , k , w , v);
    //     if(w>= v[index].first){
    //         w += v[index].second;
    //         k--;
    //         solve(index+1 , k , w , v);
    //     }else{
    //         return;
    //     }
    // }
    static bool comparator(pair<int,int> &a, pair<int,int> &b){
        return (a.second < b.second);
    }
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& cap) {
        int n = cap.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({profits[i] , cap[i]});
        }
        sort(v.begin() , v.end() , comparator);
        // for(auto it: v){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        // solve(0 , k , w , v);
        priority_queue<int> maxi;
        int i=0;
        while(k--){
            while(i<n && w>=v[i].second){
                maxi.push(v[i].first);
                i++;
            }
            if(maxi.size() == 0){
                continue;
            }
            w+=maxi.top();
            maxi.pop();
        }
        return w;
    }
};