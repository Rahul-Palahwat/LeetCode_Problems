class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& r) {
        int n = r.size();
        int minix = INT_MAX , miniy = INT_MAX, maxx=INT_MIN , maxy = INT_MIN;
        long long area = 0;
        set<string> st;
        for(int i=0;i<n;i++){
            minix = min(minix , r[i][0]);
            maxx = max(maxx , r[i][2]);
            miniy = min(miniy , r[i][1]);
            maxy = max(maxy, r[i][3]);
            long long temp = (r[i][2] - r[i][0])*1LL*(r[i][3] - r[i][1]);
            area+=temp;
            
            string pt1 = to_string(r[i][0])+" "+to_string(r[i][1]), 
            pt2 = to_string(r[i][0])+" "+to_string(r[i][3]),
            pt3 = to_string(r[i][2])+" "+to_string(r[i][1]),
            pt4 = to_string(r[i][2])+" "+to_string(r[i][3]);
            if(st.find(pt1) != st.end()){
                st.erase(pt1);
            }else{
                st.insert(pt1);
            }
            if(st.find(pt2) != st.end()){
                st.erase(pt2);
            }else{
                st.insert(pt2);
            }
            if(st.find(pt3) != st.end()){
                st.erase(pt3);
            }else{
                st.insert(pt3);
            }
            if(st.find(pt4) != st.end()){
                st.erase(pt4);
            }else{
                st.insert(pt4);
            }
        }
        if(st.size() != 4){
            return false;
        }
        string s = to_string(minix)+" "+to_string(miniy);
        if(st.find(s) == st.end()){
            return false;
        }
        s = to_string(minix)+" "+to_string(maxy);
        if(st.find(s) == st.end()){
            return false;
        }
        s = to_string(maxx)+" "+to_string(miniy);
        if(st.find(s) == st.end()){
            return false;
        }
        s = to_string(maxx)+" "+to_string(maxy);
        if(st.find(s) == st.end()){
            return false;
        }
        long long expected = (maxx - minix)*1LL*(maxy - miniy);
        return expected == area;
    }
};