class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans = 0;
        int n = words.size();
        vector<unordered_map<char,int>> v(n);
        for(int i=0;i<n;i++){
            for(auto it: words[i]){
                v[i][it]++;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int flag=0;
                for(auto it: v[i]){
                    if(v[j].find(it.first) != v[j].end()){
                        flag=1;
                        break;
                    }
                }
                if(flag == 0){
                    int temp = words[i].length()*words[j].length();
                    ans = max(ans , temp);
                }
            }
        }
        return ans;
    }
};