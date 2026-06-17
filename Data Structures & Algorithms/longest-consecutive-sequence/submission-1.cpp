class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int maxlen=0;

        for (int num:st){
            if(st.find(num-1)==st.end()){
                int currlen=1;
                while(st.find(num+currlen)!=st.end()){
                    currlen++;
                }
                maxlen=max(maxlen,currlen);
            }
        }
        return maxlen;
    }
};
