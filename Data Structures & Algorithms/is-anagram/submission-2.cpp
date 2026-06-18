class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        map<char,int>smap;
        map<char,int>tmap;
        for(char ch:s)  smap[ch]++;
        for(char ch:t)  tmap[ch]++;
        for(auto p:smap){
            if(p.second!=tmap[p.first])
                return false;
        }
        return true;
    }
};
