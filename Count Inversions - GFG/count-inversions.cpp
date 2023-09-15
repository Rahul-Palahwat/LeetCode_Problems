//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int ans = 0;
    vector<long long> merge(vector<long long> &l, vector<long long> &r){
        vector<long long> vec;
        int n = l.size() , m = r.size();
        int i=0,j=0;
        while(i<n && j<m){
            if(l[i] > r[j]){
                ans+=(n-i);
                vec.push_back(r[j]);
                j++;
            }else{
                vec.push_back(l[i]);
                i++;
            }
        }
        while(i<n){
            vec.push_back(l[i]);
            i++;
        }
        while(j<m){
            vec.push_back(r[j]);
            j++;
        }
        return vec;
    }
    vector<long long> mergeSort(long long arr[], int start , int end){
        if(start == end){
            return {arr[start]};
        }
        int mid = (start+end)/2;
        vector<long long> left = mergeSort(arr , start , mid);
        vector<long long> right = mergeSort(arr , mid+1 , end);
        return merge(left , right);
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        vector<long long> temp = mergeSort(arr , 0 , N-1);
        return ans;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends