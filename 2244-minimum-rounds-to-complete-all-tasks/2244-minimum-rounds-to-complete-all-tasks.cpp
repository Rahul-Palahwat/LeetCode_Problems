class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> mp;
        int ans = 0;
        for(auto it: tasks){
            mp[it]++;
        }
        for(auto it: mp){
            cout<<it.second<<" "<<it.first<<endl;
            if(it.second % 3 ==0){
                ans+=(it.second/3);
            }else if(it.second % 2 ==0){
                int q3 = it.second/6;
                it.second-=(6*q3);
                ans+=(q3*2);
                ans+=(it.second/2);
            }else{
                if(it.second <= 1){
                    return -1;
                }
                int q3 = it.second/3;
                it.second -= (3*q3);
                ans+=q3;
                if(it.second % 2 ==0){
                    ans+=(it.second/2);
                }else{
                    it.second+=3;
                    ans--;
                    ans+=(it.second/2);   
                }
            }
        }
        return ans;
    }
    // [69,65,62,64,70,68,69,67,60,65,69,62,65,65,61,66,68,61,65,63,60,66,68,66,67,65,63,65,70,69,70,62,68,70,60,68,65,61,64,65,63,62,62,62,67,62,62,61,66,69]
};