
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        
        vector<int> start,end;
        for(auto it: flowers){
            start.push_back(it[0]);
            end.push_back(it[1]);
        }
        sort(start.begin() , start.end());
        sort(end.begin(), end.end());
        int i=0,j=0;
        int n = flowers.size();
        int cnt = 0;
        int p = people.size();
        vector<pair<int,int>> peo;
        vector<int> ans(p);
        for(int i=0;i<p;i++){
            peo.push_back({people[i], i});
        }
        sort(peo.begin(),peo.end());
        for(auto itt: peo){
            int it = itt.first;
            int index = itt.second;
            while(i<n && it>=start[i]){
                i++;
                cnt++;
            }
            while(j<n && it > end[j]){
                j++;
                cnt--;
            }
            ans[index] = cnt;
        }
        return ans;
    }
};