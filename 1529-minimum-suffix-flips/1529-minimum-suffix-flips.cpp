class Solution {
public:
    int minFlips(string target) {
        int ans = 0;
        for(int i=0;i<target.length()-1;i++){
            if(target[i]!=target[i+1]){
                ans++;
            }
        }
        if(target[0]=='1'){
            ans++;
        }
        return ans;
    }
};