class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> uset;

        int l = 0;
        int maxLen = 0;

        for (int r = 0; r < s.size(); r++){
            while(uset.contains(s[r])){
                uset.erase(s[l]);
                l++;
            }

            uset.insert(s[r]);

            maxLen = max(maxLen, r-l+1);
        }

        return maxLen;
    }
};
