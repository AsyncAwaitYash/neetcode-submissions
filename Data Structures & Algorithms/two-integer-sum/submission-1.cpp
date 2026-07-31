class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;

        unordered_map<int, int> map;

        for(int i = 0; i< nums.size(); i++){
            int requiredSum = target - nums[i];
            if(map.find(requiredSum) != map.end()){
                ans.push_back(map[requiredSum]);
                ans.push_back(i);
                return ans;
            }

            map[nums[i]] = i;
        }
        
        return ans;
    }
};
