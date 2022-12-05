class Solution {
public:
    
    // first approach brute force 
        
    int fact(int n){
        int ans=1;
        for(int i=1;i<=n;i++){
            ans*=i;
        }
        return ans;
    }
    string getPermutation(int n, int k) {
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
    
    
    
    // 2nd by recursion but my first is the optimal
    // vector<string> ans;
    // int sz;
    // void solve(vector<string> s,string out){
    //     if(s.size() ==0){
    //         ans.push_back(out);
    //         return;
    //     }
    //     if(ans.size() >= sz){
    //         return;
    //     }
    //     for(int i=0;i<s.size();i++){
    //         vector<string> temp = s;
    //         string o = out;
    //         o+=s[i];
    //         temp.erase(temp.begin()+i);
    //         solve(temp,o);
    //     }
    //     return;
    // }
    // string getPermutation(int n, int k) {
    //     // sort(ans.begin(),ans.end());
    //     vector<string> s;
    //     sz=k;
    //     for(int i=1;i<=n;i++){
    //         string t=to_string(i);
    //         s.push_back(t);
    //     }
    //     solve(s,"");
    //     return ans[k-1];
    // }
};