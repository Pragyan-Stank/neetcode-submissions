class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        int maxlen=1;
        int currlen=1;
        if(nums.empty()) return 0;
        set<int> st(nums.begin(), nums.end());
        auto prev=st.begin();
        auto it=next(st.begin());

        while(it!=st.end()){
            if(*it==*prev+1)
                currlen++;
            else
                currlen=1;
            maxlen=max(maxlen,currlen);
            prev=it;
            ++it;
        }
        return maxlen;
    }
};
