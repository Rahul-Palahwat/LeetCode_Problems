class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        int start=intervals[0][0],end=intervals[0][1];
        for(int i=0;i<intervals.size()-1;i++){
            // if(i<intervals.size()-1)
            if(end < intervals[i+1][0]){
                // cout<<end<<"end"<<endl;
                vector<int> temp;
                end = max(intervals[i][1],end);
                temp.push_back(start);
                temp.push_back(end);
                ans.push_back(temp);
                start=intervals[i+1][0];
                end = intervals[i+1][1];
            }
            
            end = max(intervals[i+1][1],end);
            end = max(intervals[i][1],end);
        }
        vector<int> temp;
        temp.push_back(start);
        temp.push_back(end);
        ans.push_back(temp);
        return ans;
    }
};