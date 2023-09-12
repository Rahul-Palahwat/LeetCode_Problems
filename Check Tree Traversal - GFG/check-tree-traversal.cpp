//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution{
    public:
    struct TreeNode{
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int _val){
            val = _val;
            left = nullptr;
            right = nullptr;
        }
    };
    map<int, int> mp;
    bool flag = false;
    TreeNode *makeTree(int pre[], int preS, int preE,int in[], int inS, int inE){
        if(preS > preE || inS > inE){
            return NULL;
        }
        if(flag){
            return NULL;
        }
        int pos = mp[pre[preS]];
        if(pos > inE || pos < inS){
            flag = true;
            return NULL;
        }
        int ele = pos-inS;
        TreeNode *root = new TreeNode(pre[preS]);
        root->left = makeTree(pre , preS+1 , preS+ele, in , inS ,pos-1);
        root->right = makeTree(pre , preS+ele+1 , preE , in , pos+1 , inE);
        return root;
    }
    void treeTraversal(TreeNode* root, vector<int> &post){
        if(!root){
            return;
        }
        treeTraversal(root->left , post);
        treeTraversal(root->right , post);
        post.push_back(root->val);
    }
    bool checktree(int preorder[], int inorder[], int postorder[], int N) 
    { 
    	// Your code goes here
    	int n = N;
    	for(int i=0;i<n;i++){
    	    mp[inorder[i]] = i;
    	}
    	TreeNode *root = makeTree(preorder , 0 , n-1 , inorder , 0 , n-1);
    	vector<int> post;
    	if(flag){
    	    return false;
    	}
    	treeTraversal(root , post);
    	for(int i=0;i<n;i++){
    	    if(post[i] != postorder[i]){
    	        return false;
    	    }
    	}
    	return true;
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
		int preorder[n];
		int inorder[n];
		int postorder[n];

		for (int i = 0; i < n; ++i)
			cin>>preorder[i];

		for (int i = 0; i < n; ++i)
			cin>>inorder[i];

		for (int i = 0; i < n; ++i)
			cin>>postorder[i];
        
        Solution obj;
		if(obj.checktree(preorder, inorder, postorder, n))
			cout << "Yes\n";
		else
			cout<<"No\n";
	} 
	return 0; 
} 


// } Driver Code Ends