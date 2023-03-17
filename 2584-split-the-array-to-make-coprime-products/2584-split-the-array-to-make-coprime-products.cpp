class Solution {
public:
    
    // Brute force approach 
    // map<int,int> findPrime(int n){
    //     map<int,int> tempmp;
    //     int c=2;
    //     while(n>1)
    //     {
    //         if(n%c==0){
    //             // cout<<c<<" c "<<n<<" n ";
    //             tempmp[c]+=1;
    //             n/=c;
    //         }
    //         else c++;
    //     }
    //     // cout<<tempmp.size()<<" size mp"<<endl;
    //     return tempmp;
    // }
    // int findValidSplit(vector<int>& nums) {
    //     unordered_map<int, int> mp,check;
    //     int index = -1;
    //     int n = nums.size();
    //     vector<int> g[n];
    //     for(int i=0;i<n;i++){
    //         for(auto it:findPrime(nums[i])){
    //             g[i].push_back(it.first);
    //         }
    //     }
    //     for(int i=0;i<n;i++){
    //         for(auto it: g[i]){
    //             // cout<<it<<" ";
    //             mp[it]++;
    //         }
    //         // cout<<endl;
    //     }
    //     for(int i=0;i<n-1;i++){
    //         for(auto it: g[i]){
    //             mp[it]--;
    //             check[it]=1;
    //             if(mp[it] == 0){
    //                 mp.erase(it);
    //             }
    //         }
    //         // cout<<mp.size()<<"sz"<<endl;
    //         int flag=0;
    //         for(auto it: check){
    //             if(mp.find(it.first) != mp.end()){
    //                 flag=1;
    //                 break;
    //             }
    //         }
    //         if(flag==0){
    //             return i;
    //         }
    //     }
    //     return index;
    // }
    
    
    // Optimized approach 
    vector<int> getpFactors(int n) {
        vector<int> res;
        for (int i = 2; i < 1000; i++)
            if (n % i == 0) {
                res.push_back(i);
                while(n % i == 0)
                    n /= i;
            }
        if (n > 1)
            res.push_back(n);
        return res;
    }
    
    int findValidSplit(vector<int>& nums) {
        int n = nums.size();
        
        if(n==1)
            return -1;

        unordered_map<int, int> mpr;
        unordered_map<int, int> mpl;
        unordered_map<int, vector<int>> pfv;
        
        for(int i=0;i<n;i++){
            int val = nums[i];
            vector<int> pf = getpFactors(val);
            pfv[i] = pf;
            for(auto el : pf){
                mpr[el] = i;
                
                if(mpl.find(el) == mpl.end())
                    mpl[el] = i;
            }
        }
        
        
        int mx_go_right = 0;
        for(int i=0;i<n;i++){
            vector<int> pf = pfv[i];
            for(auto el : pf)
                mx_go_right = max(mx_go_right, mpr[el]);
            
            if(i+1 > mx_go_right)
                break;
        }
        
        int mx_go_left = n;
        for(int i=n-1;i>=0;i--){
            vector<int> pf = pfv[i];
            for(auto el : pf)
                mx_go_left = min(mx_go_left, mpl[el]);
            
            if(i-1 < mx_go_left)
                break;
        }      
        
        if(mx_go_left <= mx_go_right)
            return -1;
        
        return mx_go_right;
    }
};