class Solution {
public:
    string convert(string s, int numRows) {
        vector<int> v[numRows];
        int j=0,flag=0;
        for(int i=0;i<s.length();i++){
            cout<<j<<"j";
            if(j<=0){
                flag=0;
                j=0;
            }
            if(j==numRows-1){
                flag=1;
            }
            if(flag==0){
                // j++;
                v[j].push_back(s[i]);
                j++;
            }
            if(flag==1){
                v[j].push_back(s[i]);
                j--;
            }
        }
        // cout<<endl;
        string ans="";
        for(auto it: v){
            for(auto c:it){
                // cout<<char(c)<<" ";
                ans+=c;
            }
            // cout<<endl;
        }
        return ans;
    }
};