//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        double ans = 0;
        priority_queue<pair<double , int>> pq;
        for(int i=0;i<n;i++){
            pq.push({(arr[i].value*1.0/arr[i].weight*1.0) , i});
        }
        while(W > 0 && pq.size() > 0){
            auto top = pq.top();
            int index = top.second;
            if(arr[index].weight >= W){
                ans+=((arr[index].value*1.0)/(arr[index].weight*1.0))*W;
                W = 0;
                break;
            }else{
                ans+=arr[index].value;
                W-=arr[index].weight;
            }
            pq.pop();
        }
        return ans;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends