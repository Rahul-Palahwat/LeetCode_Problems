class DisjointSet{
    private:
    vector<int> parent , size;
    public:
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1 , 1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }
    int findParent(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }
    void unionBySize(int u , int v){
        int parU = findParent(u);
        int parV = findParent(v);
        if(parU == parV){
            return;
        }
        if(size[parU] >= size[parV]){
            parent[parV] = parU;
            size[parU] += size[parV];
        }else{
            parent[parU] = parV;
            size[parV] += size[parU];
        }
        return;
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet s(n);
        unordered_map<string , int> mp;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail = accounts[i][j];
                if(mp.find(mail) == mp.end()){
                    mp[mail] = i;
                }else{
                    s.unionBySize(i , mp[mail]);
                }
            }
        }
        vector<string> ans[n];
        for(auto it: mp){
            ans[s.findParent(it.second)].push_back(it.first);
        }
        vector<vector<string>> finalAns;
        for(int i=0;i<n;i++){
            if(ans[i].size() > 0){
                vector<string> tans;
                tans.push_back(accounts[i][0]);
                vector<string> temp = ans[i];
                sort(temp.begin() , temp.end());
                for(auto it: temp){
                    tans.push_back(it);
                }
                finalAns.push_back(tans);
            }
        }
        return finalAns;
    }
};