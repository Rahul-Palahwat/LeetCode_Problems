class Solution {
public:
    
    string simplifyPath(string path) {
    string res, tmp;
    vector<string> stk;
    stringstream ss(path);
    while(getline(ss,tmp,'/')) {
        if (tmp == "" or tmp == ".") continue;
        if (tmp == ".." and !stk.empty()) stk.pop_back();
        else if (tmp != "..") stk.push_back(tmp);
    }
    for(auto str : stk) res += "/"+str;
    return res.empty() ? "/" : res;
}
    // string simplifyPath(string path) {
    //     string ans = "/";
    //     int n = path.length(),i=0;
    //     while()
    //     while(i<n && (s[i]== '.' || s[i] == '/'){
    //         i++;
    //     }
    //     int cntd = 0;
    //     for(;i<n;i++){
    //         if(s[i] == '.'){
    //             while(i<n && s[i] == '.'){
    //                 cntd++;
    //                 i++;
    //             }
    //         }
    //         if(cntd > 2){
    //             while(cntd--){
    //                 ans+='.';
    //             }
    //         }
    //     }
    //     return ans;
    // }
};