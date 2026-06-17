class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        vector<int>count(26,0);
        for(int i=0;i<s.length();i++){
            int indexS=s[i]-'a';
            int indexT=t[i]-'a';
            count[indexS]++;
            count[indexT]--;
        }
        for(int i:count){
            if (i!=0) return false;
        }
        return true; 
    }
};
