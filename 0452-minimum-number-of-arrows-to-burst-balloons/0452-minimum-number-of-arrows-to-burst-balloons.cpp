class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int ans=0;
        sort(points.begin(),points.end());
        int start=points[0][0];
        int end = points[0][1];
        for(int i=1;i<points.size();i++){
            int tempstart = max(start , points[i][0]);
            int tempend = min(end,points[i][1]);
            if(tempstart > tempend){
                ans++;
                start = points[i][0];
                end = points[i][1];
            }else{
                start = tempstart;
                end = tempend;
            }
        }
        return ans+1;
    }
};