//{ Driver Code Starts
// C++ program to find predecessor and successor in a BST
#include <iostream>
using namespace std;

// BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};

int key=0;
// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key);

 void insert(struct Node *root,int n1,int n2,char lr)
 {
     if(root==NULL)
        return;
     if(root->key==n1)
     {
         switch(lr)
         {
          case 'L': root->left=new Node(n2);
                    break;
          case 'R': root->right=new Node(n2);
                    break;
         }
     }
     else
     {
         insert(root->left,n1,n2,lr);
         insert(root->right,n1,n2,lr);
     }
 }
// Driver program to test above functions
int main()
{
    /* Let us construct the tree shown in above diagram */
    int t,k;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    struct Node *root=NULL;
    Node *pre=NULL;
    Node *suc=NULL;
    while(n--)
    {
        char lr;
        int n1,n2;
        cin>>n1>>n2;
        cin>>lr;
        if(root==NULL)
        {
            root=new Node(n1);
            switch(lr){
                    case 'L': root->left=new Node(n2);
                    break;
                    case 'R': root->right=new Node(n2);
                    break;
                    }
        }
        else
        {
            insert(root,n1,n2,lr);
        }
    }
   // Inorder(root);
    //Node * target =ptr;
    //printkdistanceNode(root, target, k);
    //cout<<endl;
    cin>>key;
    findPreSuc(root, pre, suc, key);
	if (pre != NULL)
	cout << pre->key;
	else
	cout << "-1";

	if (suc != NULL)
	cout <<" "<<suc->key<<endl;
	else
	cout << " "<<"-1"<<endl;
    }
	return 0;
}
// } Driver Code Ends


/* BST Node
struct Node
{
	int key;
	struct Node *left, *right;
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
#include<bits/stdc++.h>
unordered_map<int, Node*> mp;
vector<int> ans;
void solve(Node* root){
    if(!root){
        return;
    }
    mp[root->key] = root;
    solve(root->left);
    ans.push_back(root->key);
    solve(root->right);
    return;
}
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    mp.clear();
    ans.clear();
    solve(root);
    pre = NULL;
    suc = NULL;
// Your code goes here
    for(int i=0;i<ans.size()-1;i++){
        if(key > ans[i] && key < ans[i+1]){
            // cout<<"firts"<<endl;
            pre = mp[ans[i]];
            suc = mp[ans[i+1]];
            break;
        }else if(key >= ans[i] && key < ans[i+1]){
            // cout<<"second"<<endl;
            if(i>0){
                pre = mp[ans[i-1]];
            }else{
                pre = NULL;
            }
            // cout<<ans[i+1]<<endl;
            suc = mp[ans[i+1]];
            break;
        }else if(key > ans[i] && key <= ans[i+1]){
            // cout<<"third"<<endl;
            if(i+2< ans.size()){
                suc = mp[ans[i+2]];
            }else{
                suc = NULL;
            }
            pre = mp[ans[i]];
            break;
        }
    }
    if(ans[0] == key){
        // cout<<"fi"<<endl;
        if(ans.size() > 1)
            suc = mp[ans[1]];
    }
    if(ans[0] > key){
        // cout<<"fi"<<endl;
        // if(ans.size() > 1)
            suc = mp[ans[0]];
    }
    if(ans[ans.size()-1] == key){
        if(ans.size() > 1)
        pre = mp[ans[ans.size()-2]];
    }
    if(ans[ans.size()-1] < key){
        // if(ans.size() > 1)
        pre = mp[ans[ans.size()-1]];
    }
    
    return;

}