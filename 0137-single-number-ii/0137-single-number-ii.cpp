class Solution {
public:
    // BruteForce
    // int singleNumber(vector<int>& nums) {
    //     int ans;
    //     unordered_map<int,int> mp;
    //     for(auto it: nums){
    //         mp[it]++;
    //     }
    //     for(auto it: nums){
    //         if(mp[it] == 1){
    //             ans = it;
    //             break;
    //         }
    //     }
    //     return ans;
    // }
    
    
    // Can also be done by sorting and then traversing
    
    
    // Using concept of setBits
    void solve(long long n , vector<int>& bits){
        int i=0;
        while(n>0){
            if(n&1){
                bits[i]++;
            }
            n>>=1;
            i++;
        }
        return;
    }
    int singleNumber(vector<int>& s) 
    {
    	vector<int> bits(32 , 0);
        int mini = 0;
        
        // For handling negative number case
        for(auto it: s){
            mini = min(it , mini);
        }
        
        for(auto it: s){
            long long temp = it;
            // Adding mini to all numbers so that we can get a positive number
            temp-=mini;
            solve(temp , bits);
        }
        long long two = 1;
        long long ans=0;
        for(int i=0;i<32;i++){
            if((bits[i]%3) != 0){
                ans+=(two);
            }
            two*=2;
        }
        // Returning the
        return ans+mini;
    }
};