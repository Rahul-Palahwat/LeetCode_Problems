class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        sort(in.begin() , in.end());
        int n = in.size();
        vector<vector<int>> ans;
        int start = in[0][0] , end = in[0][1];
        for(int i=1;i<n;i++){
            if(end < in[i][0]){
                ans.push_back({start , end});
                start = in[i][0];
                end = in[i][1];
            }else{
                end = max(end , in[i][1]);
            }
        }
        ans.push_back({start , end});
        return ans;
    }
};