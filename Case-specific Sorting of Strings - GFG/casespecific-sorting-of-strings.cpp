//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        // your code here
        string small="",cap="",ans="";
        for(int i=0;i<n;i++){
            if(str[i]-'a'>=0){
                small+=str[i];
            }else{
                cap+=str[i];
            }
        }
        sort(small.begin(),small.end());
        sort(cap.begin(),cap.end());
        int i=0,j=0;
        for(int k=0;k<n;k++){
            if(str[k]-'a' >=0){
                ans+=small[i];
                i++;
            }else{
                ans+=cap[j];
                j++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends