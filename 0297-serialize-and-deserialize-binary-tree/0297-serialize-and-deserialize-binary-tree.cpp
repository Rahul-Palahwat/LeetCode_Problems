/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root){
            return "";
        }
        string ans = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int t = q.size();
            while(t--){
                auto top = q.front();
                q.pop();
                if(top == NULL){
                    ans+="#,";
                }else{
                    ans+=to_string(top->val);
                    ans+=",";
                    q.push(top->left);
                    q.push(top->right);
                }
            }
        }
        cout<<ans<<endl;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length() == 0){
            return NULL;
        }
        int n = data.length();
        string temp= "";
        queue<TreeNode*> q;
        int i = 0;
        while(data[i] != ','){
            temp+=data[i];
            i++;
        }
        TreeNode* node = new TreeNode(stoi(temp));
        TreeNode* ans = node;
        temp = "";
        i++;
        q.push(node);
        int j=0;
        TreeNode* top;
        for(;i<n;i++){
            if(data[i] == ','){
                if(j%2 ==0){
                    top = q.front();
                    q.pop();
                }
                if(temp == "#"){
                    j++;
                }else{
                    int val = stoi(temp);
                    if(j%2 == 0){
                        top->left = new TreeNode(val);
                        q.push(top->left);
                    }else{
                        top->right = new TreeNode(val);
                        q.push(top->right);
                    }
                    j++;
                }
                temp = "";
            }else{
                temp+=data[i];
            }
        }
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));