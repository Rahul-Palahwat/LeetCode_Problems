class Solution {
public:
    // vector<string> ans;
    // void solve(int n,string s);
    int fact(int n){
        int ans=1;
        for(int i=1;i<=n;i++){
            ans*=i;
        }
        return ans;
    }
    string getPermutation(int n, int k) {
        // solve(n);
        // return ans[k-1];
        vector<string> v;
        string ans="";
        for(int i=1;i<=n;i++){
            string c=to_string(i);
            v.push_back(c);
        }
        int t=n;
        k--;
        while(ans.length()<n && k>=0){
            int mul = fact(t-1);
            int index = k/mul;
            ans+=v[index];
            v.erase(v.begin()+index);
            t--;
            k-=(mul*index);
        }
        return ans;
    }
};