class Solution {
public:
    // int maxPoints(vector<vector<int>>& points) {
    //     int ans =1;
    //     for(int i=0;i<points.size();i++){
    //         for(int j=0;j<points.size();j++){
    //             if(i==j){
    //                 continue;
    //             }
    //             long long m = 1LL;
    //             int den = (points[j][0] - points[i][0]);
    //             int flag=0;
    //             if(den == 0){
    //                 m=0;
    //                 // cout<<m<<endl;
    //                 flag=1;
    //             }else{
    //                 m = (points[j][1] - points[i][1])/den;
    //             }
    //             int c = points[j][1] - m*(points[j][0]);
    //             int temp=0;
    //             for(int k=0;k<points.size();k++){
    //                 if(flag==1){
    //                     if(points[k][0] == m){
    //                         temp++;
    //                     }
    //                 }
    //                 else if((points[k][1] - c) == (m*points[k][0])){
    //                     temp++;
    //                 }
    //             }
    //             ans = max(ans,temp);
    //         }
    //     }
    //     return ans;
    // }
    int maxPoints(vector<vector<int>>& pt) {
        int ans=1; 
        int n=pt.size();
       // slope of every point with selected point
        for(int i=0;i<n-1;i++){
            map<double,int> mp;
            for(int j=i+1;j<n;j++){
                //calculating the slope
                double x = (double)(pt[j][1]-pt[i][1])/(double)(pt[j][0]-pt[i][0]);
                if(pt[j][1]-pt[i][1]<0 &&(pt[j][0]-pt[i][0])==0 ) //infinite slop for Perpendicular line
                mp[abs(x)]++; 
                else
               //storing the slop into map
                    mp[x]++;
            }
            // same slope w.r.t.that selected point
            int temp = 0;
            for(auto it:mp)
                temp = max(temp, it.second+1);    // +1 for the current point(point itself)
            ans = max(temp, ans);
        }
        return ans;
    }
};