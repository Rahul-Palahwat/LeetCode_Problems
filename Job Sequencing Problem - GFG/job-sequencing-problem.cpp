//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    
    static bool cmp(Job one, Job two){
        return one.profit > two.profit;
    }
    // Thought process maximum profit ko pehle krna h
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr, arr+n , cmp);
        vector<int> ans;
        int maxiDeadLine = 0;
        for(int i=0;i<n;i++){
            maxiDeadLine = max(maxiDeadLine , arr[i].dead);
        }
        vector<int> dp(maxiDeadLine+1 , -1);
        int cnt = 0 , sum = 0;
        for(int i=0;i<n;i++){
            for(int j = arr[i].dead;j>0;j--){
                if(dp[j] == -1){
                    sum+=arr[i].profit;
                    cnt++;
                    dp[j] = arr[i].profit;
                    break;
                }
            }
        }
        ans.push_back(cnt);
        ans.push_back(sum);
        return ans;
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends