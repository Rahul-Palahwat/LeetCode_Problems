//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    struct Node{
        Node *links[26];
        bool flag=false;
        
        bool contains(char key){
            return links[key-'a']!=NULL;
        }
        
        Node* get(char key){
            return links[key-'a'];
        }
        
        void put(char key, Node* node){
            links[key-'a'] = node;
        }
        
    };
    void Insert(string word , Node* root){
        Node* node = root;
        for(auto it: word){
            if(!node->contains(it)){
                node->put(it , new Node());
            }
            node = node->get(it);
        }
    }
    bool Check(string word , Node* root){
        Node* node = root;
        for(auto it:word){
            if(!node->contains(it)){
                return false;
            }
            node=node->get(it);
        }
        return true;
        
    }
    Node *root;
    int prefixSuffixString(vector<string> &s1,vector<string> s2){
        // Code here
        int ans = 0;
        root = new Node();
        for(auto it: s1){
            Insert(it , root);
            string temp = it;
            reverse(temp.begin() , temp.end());
            Insert(temp , root);
        }
        for(auto it: s2){
            if(Check(it , root)){
                // cout<<it<<endl;
                ans++;
            }else{
                string temp = it;
                reverse(temp.begin() , temp.end());
                if(Check(temp , root)){
                    ans++;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string str1,str2,newline;
        if(i==0)
        getline(cin,newline);
        getline(cin,str1);
        getline(cin,str2);
        // getline(cin,newline);
        // cout<<str1<<endl<<str2<<endl;
        vector<string> s1,s2;
        stringstream ss1(str1);
        stringstream ss2(str2);
        string str;
        while(ss1>>str){
            s1.push_back(str);
        }
        while(ss2>>str){
            s2.push_back(str);
        }
        Solution ob;
        cout<<ob.prefixSuffixString(s1, s2)<<endl;
    }
}
// } Driver Code Ends