class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> smp;
        unordered_map<char, int> tmp;

        int reqcount = t.size();

        for(char c: t){
            tmp[c]++;
        }

        int currcount = 0;

        int l = 0;

        int minlen = INT_MAX;
        int startindex = 0;

        for(int r=0; r< s.size(); r++){
            smp[s[r]]++;

            if(tmp[s[r]] > 0 && smp[s[r]] <= tmp[s[r]]){
                currcount++;
            }

            if(currcount < reqcount)
                continue;

            while(currcount == reqcount){

                if(minlen > r-l+1){
                    minlen = r-l+1;
                    startindex = l;
                }

                if(tmp[s[l]] > 0 && smp[s[l]] <= tmp[s[l]]){
                    currcount--;
                }
                smp[s[l]]--;
                l++;
            }
        }

        return minlen == INT_MAX ? "" : s.substr(startindex, minlen);

    }
};