class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<pair<unordered_map<char, int>, int>> identifier;
        
        for(int i = 0; i< strs.size(); i++){
            unordered_map<char, int> tempMap;

            for(int j = 0; j< strs[i].size(); j++){
                tempMap[strs[i][j]]++;
            }

            identifier.push_back({tempMap, i});
        }

        vector<vector<string>> ans;

        vector<int> alreadyUsed(strs.size(), 0);

        for(int i = 0; i < identifier.size(); i++){
            if(alreadyUsed[i] == 1) continue;

            vector<string> current;
            current.push_back(strs[identifier[i].second]);

            for(int j = i+1; j< identifier.size(); j++){
                if(identifier[i].first == identifier[j].first){
                    current.push_back(strs[identifier[j].second]);
                    alreadyUsed[j] = 1;
                }
            }

            ans.push_back(current);
        }

        return ans;
    }
};
