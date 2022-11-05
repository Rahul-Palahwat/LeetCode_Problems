class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int ans = 1;
        int cap = capacity;
        for(int i=0;i<plants.size()-1;i++){
            ans++;
            capacity-=plants[i];
            if(capacity < plants[i+1]){
                cout<<i<<"i"<<ans<<endl;
                ans+=i+1;
                ans+=i+1;
                capacity=cap;
            }
        }
        return ans;
    }
};