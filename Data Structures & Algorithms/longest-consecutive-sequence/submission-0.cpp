class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> store(nums.begin(), nums.end());

        int ans = 0;

        for(int i = 0; i < nums.size(); i++){
            int num = nums[i];

            if(!store.contains(num - 1)){
                int len = 1;

                while(store.contains(num + 1)){
                    len++;
                    num++;
                }

                ans = max(ans, len);
            }
        }

        return ans;
    }
};