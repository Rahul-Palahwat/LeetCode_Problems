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
    
    
    
    int singleNumber(vector<int>& s) 
    {
    	vector<int> t(32);////Made a array contain 32 elements.
    	int sz = s.size();
    	int i, j, n;
    	for (i = 0; i < sz; ++i)
    	{
    		n = s[i];
    		for (j = 31; j >= 0; --j)
    		{
    			t[j] += n & 1;//Find the last digit.
    			n >>= 1;
    			if (!n)
    				break;
    	    }
        }
	int res = 0;
	for (j = 31; j >= 0; --j)
	{
		n = t[j] % 3;//"3" represents k times. 
		if (n)
			res += 1 << (31 - j);
	}
	return res;
}
};