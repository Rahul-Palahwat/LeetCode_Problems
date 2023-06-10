//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	    int ans = 1;
	    int n = nums.size();
	    vector<int> preDp(n , 1),postDp(n,1);
	    for(int i=1;i<n;i++){
	        for(int j=0;j<i;j++){
	            if(nums[i]>nums[j]){
	                preDp[i] = max(preDp[i] , 1+preDp[j]);
	            }
	        }
	    }
	    for(int i=n-2;i>=0;i--){
	        for(int j=n-1;j>i;j--){
	            if(nums[i] > nums[j]){
	                postDp[i] = max(postDp[i] , 1+postDp[j]);
	            }
	        }
	    }
	    for(int i=0;i<n;i++){
	        if(i==0){
	            ans = max(ans , postDp[i]);
	        }else if(i == n-1){
	            ans = max(ans , preDp[i]);
	        }else{
	            ans = max(ans , preDp[i]+postDp[i]-1);
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends