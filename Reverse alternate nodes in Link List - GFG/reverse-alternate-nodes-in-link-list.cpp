//{ Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert()
{
    int n,value;
    cin>>n;
    struct Node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}


// } Driver Code Ends
/*
  reverse alternate nodes and append at the end
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
      int data;
      struct Node *next;
    
      Node(int x){
        data = x;
        next = NULL;
      }
    
   };

*/
#include<bits/stdc++.h>
class Solution
{
    public:
    void rearrange(struct Node *odd)
    {
        //add code here
        vector<int> s , f;
        if(!odd || !odd->next || !odd->next->next){
            return;
        }
        Node *slow = odd->next , *fast = slow->next;
        while(fast){
            f.push_back(fast->data);
            if(fast->next)
                fast = fast->next->next;
            else
                break;
        }
        int i = 0;
        while(slow){
            if(i%2 == 0){
                s.push_back(slow->data);
            }
            i++;
            slow = slow->next;
        }
        i=0;
        slow = odd->next;
        while(slow && i<f.size()){
            slow->data = f[i];
            i++;
            slow= slow->next;
        }
        i = s.size()-1;
        while(slow){
            slow->data = s[i];
            i--;
            slow= slow->next;
        }
        return;
    }
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while (t--) {
        insert();
        Solution ob;
        ob.rearrange(start);
        printList(start);
    }
    return 0;
}

// } Driver Code Ends