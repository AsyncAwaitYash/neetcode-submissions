class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> s1map;

        for(char c: s1){
            s1map[c]++;
        }

        unordered_map<char, int> s2map;
        int l = 0;

        for(int r = 0; r < s2.size(); r++){
            s2map[s2[r]]++;


            while(r -l + 1 > s1.size()){
                s2map[s2[l]]--;
                if(s2map[s2[l]] == 0)
                    s2map.erase(s2[l]);
                l++;
            }

            if(s2map == s1map)
                return true;
        }

        return false;
    }
};
