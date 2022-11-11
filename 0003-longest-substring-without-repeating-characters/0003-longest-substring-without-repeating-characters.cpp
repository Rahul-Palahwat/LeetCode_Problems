class Solution {
public:
    
    // brute force approach 
//     bool check(string s){
//         map<char,int> mp;
//         for(auto it: s){
//             mp[it]++;
//         }
//         for(auto it: mp){
//             if(it.second >1){
//                 return false;
//             }
//         }
//         return true;
//     }
//     int lengthOfLongestSubstring(string s) {
//         int ans = 1;
//         for(int i=0;i<s.length()-1;i++){
//             string temp="";
//             temp+=s[i];
//             for(int j=i+1;j<s.length();j++){
//                 temp+=s[j];
//                 if(check(temp)){
//                 int len = temp.length();
//                 ans = max(ans,len);
//             }
//             }
            
//         }
//         return ans;
//     }
    
    // variable size sliding window
    unordered_map<char,int> mp;
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0){
            return 0;
        }
        int ans = 1;
        int i=0,j=0;
        while(j<s.length()){
            if(mp.find(s[j]) != mp.end()){
                int temp = mp[s[j]];
                while(i<=temp){
                    mp.erase(s[i]);
                    i++;
                }
            }
            ans = max(ans,j-i+1);
            mp[s[j]] = j;
            j++;
        }
        return ans;
    }
};