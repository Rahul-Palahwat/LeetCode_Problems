//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        map<string , int> mp , vis;
        for(auto it: wordList){
            mp[it]++;
        }
        vector<vector<string>> ans;
        queue<vector<string>> q;
        q.push({beginWord});
        bool findAns = false;
        while(!q.empty()){
            int sz = q.size();
            vector<string> v;
            while(sz--){
                auto top = q.front();
                q.pop();
                string s = top.back();
                if(vis.find(s) != vis.end()){
                    continue;
                }
                // cout<<s<<" s"<<endl;
                if(s == endWord){
                    findAns = true;
                    ans.push_back(top);
                }
                v.push_back(s);
                for(int i=0;i<s.size();i++){
                    for(char ch = 'a';ch<='z';ch++){
                        char temp = s[i];
                        s[i] = ch;
                        if(mp.find(s) != mp.end()){
                            top.push_back(s);
                            q.push(top);
                            top.pop_back();
                        }
                        s[i] = temp;
                    }
                }
            }
            // if(findAns == true){
            //     return ans;
            // }
            for(auto it : v){
                vis[it] = 1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends