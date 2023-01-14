class Solution {
public:
    
    
    vector<int>headChar;

// find the parent or headChar.
    int find(int x){
        if(headChar[x] == -1){return x;}

        return headChar[x] = find(headChar[x]);
    }

    void Union(int x,int y){
        int parentx = find(x);
        int parenty = find(y);


        if(parentx == parenty){return;}


        // make smaller one represent of other. if parent are diffrent.
        headChar[max(parentx,parenty)] = min(parentx,parenty);
    }


    string smallestEquivalentString(string s1, string s2, string baseStr) {

        headChar.resize(26,-1);
        // make group (Union)
        for(int i=0;i<s1.size();i++){
            Union(s1[i]-'a',s2[i]-'a');
        }

        // traverse in the baseStr and find the parent of each char.
       for(auto i=0;i<baseStr.size();i++)
            baseStr[i]=find(baseStr[i]-'a')+'a';

        return baseStr;
    }
    
    
    
    
    
    // string smallestEquivalentString(string s1, string s2, string base) {
    //     unordered_map<char,vector<char>> mp1,mp2;
    //     string ans="";
    //     for(int i=0;i<s1.length();i++){
    //         mp1[s1[i]].push_back(s2[i]);
    //         mp2[s2[i]].push_back(s1[i]);
    //         if(mp2.find(s2[i]) != mp2.end()){
    //             for(auto it: mp2[s2[i]]){
    //                 mp1[s1[i]].push_back(it);
    //             }
    //         }
    //         if(mp1.find(s1[i]) != mp1.end()){
    //             for(auto it: mp1[s1[i]]){
    //                 mp2[s2[i]].push_back(it);
    //             }
    //         }
    //         if(mp2.find(s2[i]) != mp2.end()){
    //             for(auto it: mp2[s2[i]]){
    //                 mp1[s1[i]].push_back(it);
    //             }
    //         }
    //     }
    //     for(int i=0;i<s1.length();i++){
    //         sort(mp1[s1[i]].begin(), mp1[s1[i]].end());
    //     }
    //     for(int i=0;i<s2.length();i++){
    //         sort(mp2[s2[i]].begin(), mp2[s2[i]].end());
    //     }
    //     for(int i=0;i<base.length();i++){
    //         char c1=' ',c2=' ';
    //         if(mp1.find(base[i]) != mp1.end()){
    //             c1 = mp1[base[i]][0];
    //         }
    //         if(mp2.find(base[i]) != mp2.end()){
    //             c2 = mp2[base[i]][0];
    //         }
    //         if(c1 == ' ' && c2 == ' '){
    //             ans+=base[i];
    //         }else if(c1 == ' '){
    //             ans+=min(base[i],c2);
    //         }else if(c2 == ' '){
    //             ans+=min(base[i],c1);
    //         }else{
    //             ans+=min(base[i] , min(c1,c2));
    //         }
    //     }
    //     return ans;
    // }
};