class Solution {
public:
    int addDigits(int num) {
        string str = to_string(num);
        if(str.size() > 1){
            int ans = 0;
            for(auto it: str){
                ans+=(it-'0');
            }
            return addDigits(ans);
        }else{
            return num;
        }
    }
};