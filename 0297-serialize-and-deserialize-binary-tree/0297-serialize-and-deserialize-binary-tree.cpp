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
        string ans = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            if(top != NULL)
                ans+=to_string(top->val);
            else
                ans+="NULL";
            ans+="#";
            if(top){
                q.push(top->left);
                q.push(top->right);
            }
        }
        cout<<ans<<endl;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int n = data.size();
        string temp = "";
        int i = 0;
        while(data[i] != '#'){
            temp+=data[i];
            i++;
        }
        i++;
        // cout<<temp<<"temp"<<endl;
        if(temp[0] == 'N'){
            return NULL;
        }
        int val = stoi(temp);
        TreeNode *root = new TreeNode(val);
        queue<TreeNode*> q;
        q.push(root);
        temp = "";
        // cout<<n<<" "<<i<<endl;
        while(!q.empty() && i<n){
            auto top = q.front();
            q.pop();
            while(i<n && data[i] != '#'){
                temp+=data[i];
                i++;
            }
            i++;
            if(temp != "NULL"){
                val = stoi(temp);
                top->left = new TreeNode(val);
                q.push(top->left);
            }
            temp = "";
            while(i<n && data[i] != '#'){
                temp+=data[i];
                i++;
            }
            i++;
            if(temp != "NULL"){
                val = stoi(temp);
                top->right = new TreeNode(val);
                q.push(top->right);
            }
            // i++;
            temp = "";
            
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));