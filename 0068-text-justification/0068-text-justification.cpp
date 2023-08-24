class Solution {
public:
    string add(vector<string> &words, int left, int right, int len, int width){
        string res;
        int spaces = width - len, gap = spaces, extra = 0;
        if(right!=left){
             gap = spaces/(right-left), extra = spaces%(right-left);
        }
  
        for(int i=left;i<=right;i++){
            res += words[i];
            for(int j=0;j<gap;j++)
                res +=' ';
            if(extra){
                res +=' ';
                extra--;
            }
        }
        
        while(res.size()>width)
            res.pop_back();
        
        return res;
    }
    
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int left = 0, n = words.size(), cnt = words[0].size();
        for(int i=1;i<n;i++){
            if(cnt + 1 + words[i].size()<=maxWidth){
                cnt += 1 + words[i].size();
                continue;
            }
            
            res.push_back(add(words, left, i-1, cnt-(i-1-left), maxWidth));
            cnt = words[i].size();
            left = i;
        }
     
        string temp = words[left];
        for(int i=left+1;i<n;i++){
            temp +=' ';
            temp += words[i];
        }
        
        while(temp.size()<maxWidth)
            temp+=' ';
        res.push_back(temp);
        
        return res;
    }
};