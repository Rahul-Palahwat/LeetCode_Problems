class Solution {
public:
    string largestGoodInteger(string num) {
        int maxi = 0;
        string ans="";
        for(int i=2;i<num.length();i++){
            if(num[i] == num[i-1] && num[i-1] == num[i-2]){
                string temp="";
                temp+=num[i];
                temp+=num[i-1];
                temp+=num[i-2];
                if(stoi(temp) >= maxi){
                    ans = temp;
                    maxi = stoi(temp);
                }
            }
        }
        return ans;
    }
};