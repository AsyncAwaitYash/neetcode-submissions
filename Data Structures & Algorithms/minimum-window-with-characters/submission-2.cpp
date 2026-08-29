class Solution {
public:
    string minWindow(string s, string t) {
        // mineeee
        unordered_map<char, int> smp;
        unordered_map<char, int> tmp;

        for(char c: t){
            tmp[c]++;
        }

        int required = tmp.size();

        int formed = 0;

        int l = 0;

        int minlen = INT_MAX;
        int startindex = 0;

        for(int r=0; r < s.size(); r++){
            smp[s[r]]++;

            if(tmp.contains(s[r]) && smp[s[r]] == tmp[s[r]]){
                formed++;
            }

            while(formed == required){

                if(minlen > r-l+1){
                    minlen = r-l+1;
                    startindex = l;
                }

                if(tmp.contains(s[l]) && smp[s[l]] == tmp[s[l]]){
                    formed--;
                }
                smp[s[l]]--;
                l++;
            }
        }

        return minlen == INT_MAX ? "" : s.substr(startindex, minlen);

    }
};