class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> rightsmall(n,0),leftsmall;
        stack<pair<int,int>> st,st2;
        for(int i=0;i<heights.size();i++){
            while(st.size() > 0 && st.top().second >= heights[i]){
                st.pop();
            }
            if(st.size() > 0){
                leftsmall.push_back(st.top().first+1);
            }else{
                leftsmall.push_back(0);
            }
            st.push({i , heights[i]});
        }
        for(auto it: leftsmall){
            cout<<it<<" ";
        }
        cout<<endl;
        for(int i=heights.size()-1;i>=0;i--){
            while(st2.size() > 0 && st2.top().second >= heights[i]){
                st2.pop();
            }
            if(st2.size()>0){
                rightsmall[i] = (st2.top().first);
            }else{
                rightsmall[i] = n;
            }
            st2.push({i , heights[i]});
        }
        for(auto it: rightsmall){
            cout<<it<<" ";
        }
        cout<<endl;
        int ans;
        for(int i=0;i<n;i++){
            ans = max(abs(rightsmall[i] - leftsmall[i])*heights[i] , ans);
        }
        return ans;
    }
};