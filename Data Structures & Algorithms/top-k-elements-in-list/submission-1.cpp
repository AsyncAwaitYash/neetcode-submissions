class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> map;

        for(int i =0; i<nums.size();i++){
            map[nums[i]]++;
        }

        vector<pair<int,int>> v;

        for(auto it: map){
            v.push_back({it.second, it.first});
        }

        sort(v.rbegin(), v.rend());

        for(int i = 0; i<k;i++){
            ans.push_back(v[i].second);
        }

        return ans;
    }
};
