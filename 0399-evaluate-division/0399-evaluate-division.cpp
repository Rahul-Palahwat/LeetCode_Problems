class Solution {
public:
    void dfs(map<string , vector<pair<string , double>>>& mp , string start , string end , map<string , bool>& vis , vector<double>& finalAns , double ans){
        vis[start] = true;
        if(start == end){
            finalAns.push_back(ans);
            return;
        }
        for(auto it: mp[start]){
            if(!vis[it.first])
            dfs(mp , it.first , end , vis ,finalAns, it.second*ans);
        }
        vis[start] = false;
        return;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ans;
        map<string , vector<pair<string , double>>> mp;
        for(int i=0;i<values.size();i++){
            mp[equations[i][0]].push_back({equations[i][1] , values[i]});
            mp[equations[i][1]].push_back({equations[i][0] , 1.0/values[i]});
        }
        int k=0;
        for(auto it: queries){
            if(mp[it[0]].size() == 0 || mp[it[1]].size() == 0){
                ans.push_back(-1.0);
            }else{
                map<string , bool> vis;
                (dfs(mp , it[0] , it[1] , vis , ans , 1.0));
                if(ans.size() == k){
                    ans.push_back(-1.0);
                }
            }
            k++;
        }
        return ans;
    }
};