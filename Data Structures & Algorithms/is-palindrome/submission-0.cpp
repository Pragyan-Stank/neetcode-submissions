class Solution {
public:
    bool isPalindrome(string s) {
        string s1 = "";

        // keep only alphanumeric characters
        for(char ch : s){
            if(isalnum(ch)){
                s1 += tolower(ch);
            }
        }

        int len = s1.length();
        int mid = len / 2;

        string s2 = s1.substr(0, mid);
        string s3;

        if(len % 2 == 0)
            s3 = s1.substr(mid, mid);
        else
            s3 = s1.substr(mid + 1, mid);

        reverse(s3.begin(), s3.end());

        if(s2 == s3) return true;
        return false;
    }
};