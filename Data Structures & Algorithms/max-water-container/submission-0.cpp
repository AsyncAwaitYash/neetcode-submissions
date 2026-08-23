class Solution {
public:
    int maxArea(vector<int>& h) {
        int l = 0, r = h.size() - 1;

        int ans = 0;

        while (l < r){
            int currArea = min(h[l], h[r]) * (r - l);
            ans = max(ans, currArea);
            if(h[l] <= h[r]){
                l++;
            }
            else{
                r--;
            }
        }

        return ans;
    }
};
