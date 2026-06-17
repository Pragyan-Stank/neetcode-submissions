class Solution {
public:
    bool checkAnagram(string s1, string s2){
        if(s1.length() != s2.length()) return false;

        vector<int> count(26,0);

        for(int i=0;i<s1.length();i++){
            count[s1[i]-'a']++;
            count[s2[i]-'a']--;
        }

        for(int x : count){
            if(x != 0) return false;
        }
        return true;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> anagramsGroup;
        vector<bool> used(strs.size(), false);

        for(int i=0;i<strs.size();i++){
            if(used[i]) continue;

            vector<string> anagrams;
            anagrams.push_back(strs[i]);
            used[i] = true;

            for(int j=i+1;j<strs.size();j++){
                if(!used[j] && checkAnagram(strs[i], strs[j])){
                    anagrams.push_back(strs[j]);
                    used[j] = true;
                }
            }

            anagramsGroup.push_back(anagrams);
        }

        return anagramsGroup;
    }
};