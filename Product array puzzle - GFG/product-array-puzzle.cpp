//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    long long int devide(long long int mul, long long int d){
        long long int ans = 0;
        if(d==1){
            return mul;
        }
        while(mul >= d){
            mul-=d;
            ans++;
        }
        return ans;
    }
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here      
        vector<long long int> ans;
        long long int mul = 1;
        int flag = 0;
        for(auto it: nums){
            if(it == 0 && flag == 0){
                flag = 1;
                continue;
            }
            mul *= it;
        }
        for(auto it: nums){
            // long long int temp = devide(mul , it);
            if(it == 0){
                ans.push_back(mul);
                continue;
            }
            if(flag > 0){
                ans.push_back(0);
            }else
                ans.push_back(mul/it);
        }
        return ans;
     }
};


//{ Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends