class Solution {
public:
    // // brute force:
    // vector<int> topKFrequent(vector<int>& nums, int k) {
    //     unordered_map<int,int> freq;

    //     for(int num : nums){
    //         freq[num]++;
    //     }

    //     vector<pair<int,int>> count;

    //     for(auto &it : freq){
    //         count.push_back({it.first, it.second});
    //     }

    //     sort(count.begin(), count.end(), [](auto &a, auto &b){
    //         return a.second > b.second;
    //     });

    //     vector<int> ans;

    //     for(int i=0;i<k;i++){
    //         ans.push_back(count[i].first);
    //     }

    //     return ans;
    // }

    // Bucket sort:
    vector<int> topKFrequent(vector<int>& nums, int k){
        unordered_map<int,int>count;
        vector<vector<int>> freq(nums.size()+1);
        for (int n:nums){
            count[n]++;
        }
        for(const auto& entry : count){
            freq[entry.second].push_back(entry.first);
        }
        vector<int>res;
        for(int i=freq.size()-1;i>0;i--){
            for(int n:freq[i]){
                res.push_back(n);
                if(res.size()==k)   
                    return res;
            }
        }
        return res;
    }
};