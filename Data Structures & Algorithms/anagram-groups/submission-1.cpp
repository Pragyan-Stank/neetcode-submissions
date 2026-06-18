class Solution {
public:
    bool checkAnagram(string s1,string s2){
        vector<int>freq(26,0);
        if(s1.length()!=s2.length())    return false;
        for(char ch:s1) freq[ch-'a']++;
        for(char ch:s2) freq[ch-'a']--;
        for(int count:freq){
            if(count!=0) return false;
        }
        return true;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        vector<bool> visited(strs.size(),false);

        for(int i=0;i<strs.size();i++){
            if(visited[i]) continue;
            
            vector<string>group;
            group.push_back(strs[i]);
            visited[i]=true;

            for(int j=i+1;j<strs.size();j++){
                if(!visited[j] && checkAnagram(strs[i],strs[j])){
                    group.push_back(strs[j]);
                    visited[j]=true;
                }
            }
            ans.push_back(group);
        }
        return ans;
    }
};
