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
    // Below(Solve) is the function to set bit for the given number
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
        // Vector to store the cout of set bits at particular index
    	vector<int> bits(32 , 0);
        // Variable to store minimum from the array for handling negative number case
        int mini = 0;
        for(auto it: s){
            mini = min(it , mini);
        }
        // Loop to iterate over all elements to set their bit count 
        for(auto it: s){
            long long temp = it;
            // Adding mini(as itself a negative number so -) to all numbers so that we can get a positive number
            temp-=mini;
            solve(temp , bits);
        }
        long long two = 1;
        long long ans=0;
        for(int i=0;i<32;i++){
            // Here we can keep K in place of 3 to handle case for K times
            if((bits[i]%3) != 0){
                ans+=(two);
            }
            two<<=1;
        }
        // Returning the answer(mini is negative so +) after subtractions of added number 
        return ans+mini;
    }
};