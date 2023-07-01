class Solution {
public:
    bool check(string s , int sum){
        if(s == ""){
            return sum == 0;
        }
        if(sum<0){
            return false;
        }
        string temp = "";
        bool ans = false;
        for(int i=0;i<s.size();i++){
            temp+=s[i];
            int sub = stoi(temp);
            ans |= check(s.substr(i+1 , s.size()) , sum-sub);
        }
        return ans;
    }
    int punishmentNumber(int n) {
        int ans = 0;
        for(int i=1;i<=n;i++){
            int temp = i*i;
            string s = to_string(temp);
            if(check(s,i)){
                ans+=i*i;
            }
        }
        return ans;
    }
};