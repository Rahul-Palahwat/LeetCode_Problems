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

class Solution
{
    public:
    Node *reverse(Node *temp){
        Node *prev = NULL, *curr = temp;
        while(temp){
            curr = temp->next;
            temp->next = prev;
            prev = temp;
            temp = curr;
        }
        return prev;
    }
    void rearrange(struct Node *odd)
    {
        //add code here
        if(!odd || !odd->next || !odd->next->next){
            return;
        }
        Node *slow = odd->next , *fast = odd;
        Node *temp = slow;
        while(fast){
            if(fast->next){
                fast->next = fast->next->next;
                fast = fast->next;
                if(fast){
                    slow->next = fast->next;
                    slow = slow->next;
                }
               
            }else{
                break;
            }
        }
        slow = temp;
        // while(slow){
        //     cout<<slow->data<<" ";
        //     slow = slow->next;
        // }
        temp = reverse(temp);
        slow = odd;
        while(slow->next){
            slow = slow->next;
        }
        slow->next = temp;
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