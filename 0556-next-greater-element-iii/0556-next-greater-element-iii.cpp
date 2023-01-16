class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> v;
        while(n> 0){
            int r = n%10;
            v.push_back(r);
            n/=10;
        }
        int flag=0;
        for(int i=1;i<v.size();i++){
            if(v[i] < v[i-1]){
                flag=1;
                break;
            }
        }
        if(flag==0){
            return -1;
        }
        int index;
        for(int i=1;i<v.size();i++){
            if(v[i] < v[i-1]){
                index=i;
                break;
            }
        }
        vector<int> prev;
        map<int,int> mp;
        for(int i=0;i<=index;i++){
            prev.push_back(v[i]);
            mp[v[i]]++;
        }
        sort(prev.begin(),prev.end());
        for(int i=0;i<=index;i++){
            if(prev[i] > v[index]){
                v[index] = prev[i];
                mp[prev[i]]--;
                break;
            }
        }
        vector<int> f;
        for(auto it: mp){
            while(it.second--){
                f.push_back(it.first);
            }
        }
        sort(f.begin(),f.end());
        long long ans=0;
        // cout<<v.size()<<"vsize"<<index<<endl;
        for(int i=v.size()-1;i>=index;i--){
            ans = (ans*10)+v[i];
        }
        // cout<<ans<<endl;
        // cout<<f.size()<<"fsize"<<index<<endl;
        for(int i=0;i<index;i++){
            ans = (ans*10)+f[i];
        }
        // cout<<ans<<endl;
        return ans> INT_MAX ? -1 : ans;
        
    }
    
//     12
// 21
// 1234
// 230241
};