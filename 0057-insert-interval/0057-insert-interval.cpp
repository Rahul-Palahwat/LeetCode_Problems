class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& ne) {
        
        vector<vector<int>> ans;
        intervals.push_back(ne);
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
        
        
        
        
        // vector<vector<int>> ans;
        // if(intervals.size() == 0){
        //     ans.push_back(ne);
        //     return ans;
        // }
        // int start = intervals[0][0];
        // int end = intervals[0][1];
        // int flag=0;
        // for(int i=1;i<intervals.size();i++){
        //     vector<int> temp;
        //     if(end >= ne[0] && start<=ne[0]+1){
        //         flag=1;
        //         start = min(start , ne[0]);
        //         end = max(end , ne[1]);
        //     }
        //     if(end >= intervals[i][0]){
        //         start = min(start , intervals[i][0]);
        //         end = max(end , intervals[i][1]);
        //         continue;
        //     }else{
        //         temp.push_back(start);
        //         temp.push_back(end);
        //         ans.push_back(temp);
        //         start = intervals[i][0];
        //         end = intervals[i][1];
        //     }
        // }
        // vector<int> temp;
        // if(end >= ne[0] && start<=ne[0]+1 && flag==0){
        //     start = min(start , ne[0]);
        //     end = max(end , ne[1]);
        //     flag=1;
        // }
        // temp.push_back(start);
        // temp.push_back(end);
        // ans.push_back(temp);
        // if(flag==0){
        //     ans.push_back(ne);
        // }
        // return ans;
    }
};