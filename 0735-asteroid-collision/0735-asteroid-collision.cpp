class Solution {
public:
    bool check(int a , int b){
        return b>0 && a<0;
    }
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        int n = asteroids.size();
        for(int i=0;i<n;i++){
            if(ans.size() > 0){
                int flag = 0;
                ans.push_back(asteroids[i]);
                while(ans.size() > 1 && check(ans[ans.size()-1] , ans[ans.size()-2])){
                    int s = ans[ans.size()-1] , f = ans[ans.size()-2];
                    if(abs(f) > abs(s)){
                        flag = 1;
                        ans.pop_back();
                        break;
                    }else if(abs(f) == abs(s)){
                        ans.pop_back();
                        ans.pop_back();
                        flag=1;
                        break;
                    }else{
                        ans.pop_back();
                        ans.pop_back();
                        ans.push_back(s);
                    }
                }
            }else{
                ans.push_back(asteroids[i]);
            }
        }
        return ans;
    }
};