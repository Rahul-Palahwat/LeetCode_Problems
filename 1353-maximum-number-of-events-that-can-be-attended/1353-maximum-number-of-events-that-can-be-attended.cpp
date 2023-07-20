class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin() , events.end());
        int ans = 0 , n = events.size();
        int i=0;
        priority_queue<int, vector<int> , greater<int>> pq;
        for(int d = 1;d<=1e5;d++){
            while(!pq.empty() && pq.top() < d){
                pq.pop();
            }
            while(i<n && events[i][0] == d){
                pq.push(events[i][1]);
                i++;
            }
            if(!pq.empty()){
                pq.pop();
                ans++;
            }
        }
        return ans;
    }
};