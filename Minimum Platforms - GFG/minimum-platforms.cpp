//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    
    
    // 2nd approach 
    int findPlatform(int arr[], int dep[], int n)
    {
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	int ans = 1;
    	int plat=1;
    	int i=1,j=0;
    	while(i<n&&j<n){
    	    if(dep[j] >= arr[i]){
    	        plat++;
    	        i++;
    	    }else if(arr[i]>dep[j]){
    	        plat--;
    	        j++;
    	    }
    	    ans = max(plat,ans);
    	}
    	return ans;
    }
    
    
    
    // 1st approach 
    // struct Timing{
    //     int arrive;
    //     int departure;
    // };
    // static bool comparator(struct Timing t1, Timing t2){
    //     if(t1.departure < t2.departure){
    //         return true;
    //     }else{
    //         return false;
    //     }
    // }
    // int findPlatform(int arr[], int dep[], int n)
    // {
    // 	struct Timing t[n];
    // 	for(int i=0;i<n;i++){
    // 	    t[i].arrive = arr[i];
    // 	    t[i].departure = dep[i];
    // 	}
    // 	sort(t,t+n,comparator);
    // 	int ans = 1;
    // 	for(int i=0;i<n;i++){
    // 	    int temp = 1;
    // 	    int e = t[i].departure;
    // 	    for(int j=i+1;j<n;j++){
    // 	        if(t[j].arrive < e){
    // 	            temp++;
    // 	            ans = max(ans,temp);
    // 	        }else{
    // 	            break;
    // 	        }
    // 	    }
    	    
    // 	}
    // 	return ans;
    // }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends