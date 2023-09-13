//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    long long int convertToInt(string s){
        long long int ans = 0;
        int n = s.size();
        for(int i=0;i<n;i++){
            ans = (ans*10)+(s[i]-'0');
        }
        return ans;
    }
public:
	long long int closestPalindrome(long long int num){
	    // Code here
	   // long long int temp = num;
	    string s = to_string(num);
	    int sz = s.size();
	    if(sz == 1){
	        return num;
	    }
	    vector<long long int> probableCandidated;
	    probableCandidated.push_back(pow(10 , sz)+1);
	   // 1001
	    probableCandidated.push_back(pow(10, sz)-1);
	   // 999
	    probableCandidated.push_back(pow(10 , sz-1)+1);
	   // 101
	    probableCandidated.push_back(pow(10 , sz-1)-1);
	   // 99
	   int mid = sz/2;
	   if(sz %2 == 0){
	       mid-=1;
	   }
	   string temp ="";
	   for(int i=0;i<=mid;i++){
	       temp+=s[i];
	   }
	   string halfAdd = to_string(stoi(temp)+1);
	   string halfSub = to_string(stoi(temp)-1);
	   if(sz %2 == 0){
	       string tt = temp;
	       reverse(temp.begin() , temp.end());
	       string ev = tt+temp;
	       long long int val = convertToInt(ev);
	       probableCandidated.push_back(val);
	       if(halfAdd.size() == temp.size()){
	           tt = halfAdd;
	           reverse(halfAdd.begin() , halfAdd.end());
	           ev = tt+halfAdd;
	           val = convertToInt(ev);
	           probableCandidated.push_back(val);
	       }
	       if(halfSub.size() == temp.size()){
	           tt = halfSub;
	           reverse(halfSub.begin() , halfSub.end());
	           ev = tt+halfSub;
	           val = convertToInt(ev);
	           probableCandidated.push_back(val);
	       }
	   }else{
	       string ev = temp;
	       int end = temp.size()-2;
	       while(end >= 0){
	           ev+=temp[end];
	           end--;
	       }
	       long long int val = convertToInt(ev);
	       probableCandidated.push_back(val);
	       if(halfAdd.size() == temp.size()){
	           ev = halfAdd;
	           end = halfAdd.size()-2;
	           while(end >= 0){
	               ev+=halfAdd[end];
	               end--;
	           }
	           val = convertToInt(ev);
	           probableCandidated.push_back(val);
	       }
	       if(halfSub.size() == temp.size()){
	           ev = halfSub;
	           end = halfSub.size()-2;
	           while(end >= 0){
	               ev+=halfSub[end];
	               end--;
	           }
	           val = convertToInt(ev);
	           probableCandidated.push_back(val);
	       }
	   }
	   long long int ans = 0;
	   long long int mini = INT_MAX;
	   sort(probableCandidated.begin() , probableCandidated.end());
	   for(auto it: probableCandidated){
	       if(abs(it-num) < mini){
	           ans = it;
	           mini = abs(it-num);
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
		long long int num;
		cin >> num;
		Solution obj;
		long long int ans = obj.closestPalindrome(num);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends