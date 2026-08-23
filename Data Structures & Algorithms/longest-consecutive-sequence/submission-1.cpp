class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> store(nums.begin(), nums.end());

        int ans = 0;

        for (int num : nums) {
            if (!store.contains(num - 1)) {
                int len = 1;

                while (store.contains(num + len)) {
                    len++;
                }

                ans = max(ans, len);
            }
        }

        return ans;
    }
};