class Solution {
public:
//     vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
//         int n = spells.size();
//         vector<int> ans(n,0);
//         sort(potions.begin() , potions.end());
//         for(int i=0;i<n;i++){
//             int f;
//             if(success%spells[i] == 0){
//                 f = success/spells[i];
//             }else{
//                 f = (success/spells[i])+1;
//             }
//             // cout<<f<<" ";
//             int sz = upper_bound(potions.begin() , potions.end() , f)-potions.begin();
//             // cout<<sz<<" sz"<<endl;
//             int flag=0;
//             while(sz-1 >= 0 && potions[sz-1] == f){
//                 sz--;
//                 flag=1;
//             }
//             // cout<<sz<<" "<<endl;
//             if(sz != potions.size())
//                 if(potions[0] == f){
//                     ans[i] = (potions.size());
//                 }else{
//                     ans[i] = (potions.size()-sz);
//                 }
            
//         }
//         return ans;
//     }
    vector<int> successfulPairs(vector<int>& s, vector<int>& p, long long suc) {
        
        vector<int> v(s.size(),0);
        sort(p.begin(),p.end());
        
        for(int i=0;i<s.size();i++)
        {
            int h=p.size()-1;
            int l=0;
            int mid;
            while(l<=h)
            {
                mid = l + (h-l)/2;
                
                if((long long int)s[i]*(long long int)p[mid] >= suc)
                    h = mid-1;
                
                else
                    l = mid+1;
            }
            
            v[i] = p.size()-1-h;
        }
        
        return v;
    }
};