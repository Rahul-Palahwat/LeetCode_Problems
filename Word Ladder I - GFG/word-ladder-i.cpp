//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        int ans = 0;
        unordered_map<string, int> mp , vis;
        for(auto it: wordList){
            mp[it]++;
        }
        queue<string> q;
        q.push(startWord);
        while(!q.empty()){
            int sz = q.size();
            ans++;
            while(sz--){
                auto top = q.front();
                q.pop();
                if(vis.find(top) != vis.end()){
                    continue;
                }
                if(top == targetWord){
                    return ans;
                }
                vis[top] = 1;
                for(int i=0;i<top.size();i++){
                    for(char c='a';c<='z';c++){
                        char temp = top[i];
                        top[i] = c;
                        if(mp.find(top) != mp.end()){
                            q.push(top);
                        }
                        top[i] = temp;
                    }
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
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
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends