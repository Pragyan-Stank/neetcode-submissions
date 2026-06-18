class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> freq;

        for(int num : nums)
            freq[num]++;

        vector<pair<int,int>> v;

        for(auto p : freq) {
            v.push_back({p.second, p.first});
        }

        sort(v.begin(), v.end());

        vector<int> ans;

        for(int i = v.size() - 1; k > 0; i--, k--) {
            ans.push_back(v[i].second);
        }

        return ans;
    }
};